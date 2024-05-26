/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:57:05 by ycho2             #+#    #+#             */
/*   Updated: 2024/05/21 14:05:01 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	count_row(char *map_file, t_map *map);
static void	save_mat(t_map *map, int fd);
static void	save_dot(t_map *map, char **line, int y);
static char	**seperate_line(int fd);

t_map	*parse_map(char *map_file)
{
	t_map	*map;
	int		fd;

	map = (t_map *)malloc(sizeof(t_map));
	map->row = 0;
	count_row(map_file, map);
	map->mat = (t_dot **)malloc(sizeof(t_dot *) * map->row);
	if (!map->mat)
		exit(1);
	fd = file_open(map_file);
	save_mat(map, fd);
	return (map);
}

static void	count_row(char *map_file, t_map *map)
{
	int		read_byte;
	char	*buf;
	int		i;
	int		fd;

	fd = file_open(map_file);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	read_byte = read(fd, buf, BUFFER_SIZE);
	while (1)
	{
		i = 0;
		while (i < read_byte)
		{
			if (buf[i] == '\n')
				map->row++;
			i++;
		}
		read_byte = read(fd, buf, BUFFER_SIZE);
		if (read_byte == 0)
			break ;
	}
	free(buf);
	close(fd);
}

static void	save_mat(t_map *map, int fd)
{
	char	**seperated_line;
	int		i;
	int		col_chk;

	seperated_line = seperate_line(fd);
	map->col = 0;
	while (seperated_line[map->col])
		map->col++;
	if (seperated_line[map->col - 1][0] == '\n')
		map->col--;
	i = 0;
	while (i < map->row)
	{
		col_chk = 0;
		while (seperated_line[col_chk])
			col_chk++;
		if (seperated_line[col_chk - 1][0] == '\n')
			col_chk--;
		check_col(map->col, col_chk);
		map->mat[i] = (t_dot *)malloc(sizeof(t_dot) * map->col);
		save_dot(map, seperated_line, i);
		split_free(seperated_line);
		seperated_line = seperate_line(fd);
		i++;
	}
}

static char	**seperate_line(int fd)
{
	char	*line;
	char	**seperated_line;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	seperated_line = ft_split(line, 32);
	free(line);
	return (seperated_line);
}

static void	save_dot(t_map *map, char **line, int y)
{
	int		i;
	char	**mte;

	i = 0;
	while (i < map->col)
	{
		mte = ft_split(line[i], ',');
		map->mat[y][i].x_val = i;
		map->mat[y][i].y_val = y;
		map->mat[y][i].z_val = ft_atoi(mte[0]);
		if (mte[1])
			map->mat[y][i].color = ft_atoi16(mte[1]);
		else
			map->mat[y][i].color = 0xffffff;
		split_free(mte);
		i++;
	}
}
