/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:57:05 by ycho2             #+#    #+#             */
/*   Updated: 2024/04/28 19:30:29 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char		**seperate_line(int fd);
static int		count_col(char **line);
static t_dot	*fill_row(t_map *map, char **line, t_dot *dot);
static t_dot	*get_dot_info(char *mte);

t_map	*parse_map(int fd)
{
	char	**seperated_line;
	t_map	*map;
	t_dot	*temp_dot;

	seperated_line = seperate_line(fd);
	if (!seperated_line)
		return (NULL); //empty map file
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		ft_malloc_err();
	map->col = count_col(seperated_line);
	map->dot_list = NULL;
	map->row = 0;
	temp_dot = NULL;
	while (seperated_line)
	{
		ft_printf("row %d\n", map->row);
		temp_dot = fill_row(map, seperated_line, temp_dot);
		split_free(seperated_line);
		seperated_line = seperate_line(fd);
	}
	return (map);
}

static char	**seperate_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	return (ft_split(line, 32));
}

static int	count_col(char **line)
{
	int	col;

	col = 0;
	while (line[col])
		col++;
	return (col);
}

static t_dot	*fill_row(t_map *map, char **line, t_dot *dot)
{
	int		col;
	int		i;
	t_dot	*temp_dot;
	t_dot	*current_dot;

	col = count_col(line);
	if (col != map->col)
		map_file_error();
	i = 0;
	current_dot = dot;
	while (line[i])
	{
		temp_dot = get_dot_info(line[i]);
		if (!map->dot_list)
			map->dot_list = temp_dot;
		else
			current_dot->next = temp_dot;
		current_dot = temp_dot;
		i++;
	}
	map->row++;
	return (current_dot);
}

static t_dot	*get_dot_info(char *mte)
{
	char	**z_and_color;
	t_dot	*temp_dot;

	temp_dot = (t_dot *)malloc(sizeof(t_dot));
	z_and_color = ft_split(mte, ',');
	temp_dot->z_val = atoi(z_and_color[0]);
	if (z_and_color[1])
		temp_dot->color = ft_atoi16(z_and_color[1]);
	else
		temp_dot->color = 0xffffff;
	return (temp_dot);
}
