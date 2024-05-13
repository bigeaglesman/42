/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:56:15 by ycho2             #+#    #+#             */
/*   Updated: 2024/05/13 21:29:57 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(t_data *data, t_map *map, t_trans *trans)
{
	int			x;
	int			y;
	t_cnv_dot	**cnv_map;

	cnv_map = trans_map(map, trans);
	y = 0;
	while (y < map->row)
	{
		x = 0;
		while (x < map->col)
		{
			if (x != map->col-1)
			{
				draw_line(data, cnv_map[y][x], cnv_map[y][x+1], trans);
				// printf("\n");
			}
			if (y != map->row-1)
			{
				draw_line(data, cnv_map[y][x], cnv_map[y+1][x], trans);
				// printf("\n");
			}

			x++;
		}
		y++;
	}
				// printf("\n");
				// printf("\n");
				// printf("\n");
}
