/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:57:05 by ycho2             #+#    #+#             */
/*   Updated: 2024/04/26 21:08:34 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		count_col(char *line);
static t_dot	**fill_map(char *argv, int map_col, int map_row);
static void		fill_line(t_dot *row_arr, char *line, int col, int y);
static t_mat	*fill_dot(int x, int y, int z);

t_dot	**parse_map(char *map_file)
{
	int		fd;
	t_dot	**map;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		fd_error();
	make_case(fd);
	fill_map(map);
	close (fd);
}

static t_dot	**make_case(int fd)
{
	char	*line;
	int		col;
	int		row;
	t_dot	**map;
	int		i;

	row = 0;
	line = get_next_line(fd);
	col = check_col(line);
	while (line)
	{
		if (col != check_col(line))
			exit(1);
		row++;
		free(line);
		line = get_next_line(fd);
	}
	map = malloc_map(col, row);
}

static int	check_col(char *line)
{
	int		col;
	char	**cut_line;

	if (!line)
	{
		ft_printf("map col err\n");
		exit(1);
	}
	col = 0;
	cut_line = ft_split(line, 32);
	while (cut_line[col])
		col++;
	split_free(cut_line);
	return (col);
}

static t_dot	**malloc_map(int col, int row)
{
	t_dot	**map;
	int		i;

	i = 0;
	map = (t_dot **)malloc(row * sizeof(t_dot *));
	handle_malloc_error((void *)map);
	while (i < row)
	{
		map[i] = (t_dot *)malloc(col * sizeof(t_dot));
		handle_malloc_error((void *)map[i]);
		i++;
	}
	return (map);
}

static void	fill_map(t_dot **map, char *map_file)
{
	t_dot	**map;
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(argv, O_RDONLY);
	map = (t_dot **)malloc(sizeof(t_dot *) * (map_row +1));
	while (i < map_row)
	{
		map[i] = (t_dot *)malloc(sizeof(t_dot) * (map_col +1));
		line = get_next_line(fd);
		fill_line(map[i], line, map_col, i);
		i++;
	}
	map[i] = NULL;
	return (map);
}

static void	fill_line(t_dot *row_arr, char *line, int col, int y)
{
	char	**seped_line;
	char	**z_n_color;
	int		x;

	x = 0;
	seped_line = ft_split(line, 32);
	while (x < col)
	{
		z_n_color = ft_split(seped_line[x], 44);
		row_arr[x].coord = fill_dot(x, y, ft_atoi(z_n_color[0]));
		if (!z_n_color[1])
			row_arr[x].color = 0xffffff;
		else
			row_arr[x].color = ft_atoi16(z_n_color[1]);
		split_free(z_n_color);
		row_arr[x].is_end = 0;
		x++;
	}
	row_arr[x].is_end = 1;
	split_free(seped_line);
}

static t_mat	*fill_dot(int x, int y, int z)
{
	t_mat	*coord;

	coord = mat_create(4, 1);
	coord->mat[0][0] = x;
	coord->mat[1][0] = y;
	coord->mat[2][0] = z;
	coord->mat[3][0] = 1;
	return (coord);
}