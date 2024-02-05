/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:57:05 by ycho2             #+#    #+#             */
/*   Updated: 2024/02/05 15:51:04 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int ft_count_row(int fd);

t_map	*read_map(int fd, char *argv)
{
	t_map	*p_map;
	int		map_row;
	int		map_col;
	int		i;

	i = 0;
	p_map = (t_map *)malloc(sizeof(t_map));
	p_map -> map_col = ft_count_words(get_next_line(fd), 32);
	p_map -> map_row = ft_count_row(fd);
	p_map -> map = (t_dot **)malloc(sizeof(t_dot *) * map_row);
	while (i < map_row)
	{
		map[i] = (t_dot *)malloc(sizeof(t_dot) * map_col);
		i++;
	}
	close(fd);
	fd = open(argv, O_RDONLY);
	fill_map(fd, map, map_col);
	return (map);
}

static int ft_count_row(int fd)
{
	int		row_cnt;
	char	*row;
	row_cnt = 1;

	row = get_next_line(fd);
	while (row)
	{
		free(row);
		row_cnt++;
		row = get_next_line(fd);
	}
	return (row_cnt);
}

static void fill_map(int fd, t_dot **map)
{
	char	**line;
	int		row;

	row = 0;
	line = ft_split(get_next_line(fd), 32);
	while (line)
	{
		while ()
		map[row];
		free(line);
		line = ft_split(get_next_line(fd), 32);
	}
}
