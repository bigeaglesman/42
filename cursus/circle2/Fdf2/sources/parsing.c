/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:57:05 by ycho2             #+#    #+#             */
/*   Updated: 2024/02/14 21:44:58 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		count_col(char *line);
static t_dot	**fill_map(char *argv, int map_col, int map_row);
static void		fill_line(t_dot *row_arr, char *line, int col, int y);
static t_mat	*fill_dot(int x, int y, int z);

t_dot	**read_map(char *argv)
{
	int		map_col;
	int		map_row;
	int		fd;
	char	*line;

	map_row = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		fd_error();
	line = get_next_line(fd);
	map_col = count_col(line);
	while (line)
	{
		map_row++;
		free (line);
		line = get_next_line(fd);
	}
	close (fd);
	return (fill_map(argv, map_col, map_row));
}

static int	count_col(char *line)
{
	char	**cut_line;
	int		i;

	i = 0;
	cut_line = ft_split(line, 32);
	while (cut_line[i])
		i++;
	split_free(cut_line);
	return (i);
}

static t_dot	**fill_map(char *argv, int map_col, int map_row)
{
	t_dot	**map;
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(argv, O_RDONLY);
	map = (t_dot **)malloc(sizeof(t_dot *) * (map_row+1));
	while (i < map_row)
	{
		map[i] = (t_dot *)malloc(sizeof(t_dot) * (map_col +1));
		line = get_next_line(fd);
		fill_line(map[i], line , map_col, i);
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