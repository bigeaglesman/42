/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:57:05 by ycho2             #+#    #+#             */
/*   Updated: 2024/02/06 16:11:32 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_col(char *line);
static void	fill_map(t_map *p_map, char *argv);
static void	fill_line(t_dot *p_dot, char *line, int col);

t_map	*read_map(char *argv)
{
	t_map	*p_map;
	int		map_row;
	int		fd;
	char	*line;

	map_row = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		fd_error();
	p_map = (t_map *)malloc(sizeof(t_map));
	if (!p_map)
		return (NULL);
	line = get_next_line(fd);
	p_map->col = count_col(line);
	while (line)
	{
		map_row++;
		free (line);
		line = get_next_line(fd);
	}
	p_map->row = map_row;
	close (fd);
	fill_map(p_map, argv);
	return (p_map);
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

static void	fill_map(t_map *p_map, char *argv)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(argv, O_RDONLY);
	p_map->map = (t_dot **)malloc(sizeof(t_dot *) * p_map->row);
	while (i < p_map->row)
	{
		p_map->map[i] = (t_dot *)malloc(sizeof(t_dot) * p_map->col);
		line = get_next_line(fd);
		fill_line(p_map->map[i], line , p_map->col);
		i++;
	}
}

static void	fill_line(t_dot *p_dot, char *line, int col)
{
	char	**seped_line;
	char	**z_val_color;
	int		j;

	j = 0;
	seped_line = ft_split(line, 32);
	while (j < col)
	{
		z_val_color = ft_split(seped_line[j], 44);
		p_dot[j].z_val = ft_atoi(z_val_color[0]);
		if (!z_val_color[1])
			p_dot[j].color = 0xffffff;
		else
			p_dot[j].color = ft_atoi16(z_val_color[1]);
		split_free(z_val_color);
		j++;
	}
	split_free(seped_line);
}

