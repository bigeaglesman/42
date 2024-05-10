/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_coord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:14:35 by ycho2             #+#    #+#             */
/*   Updated: 2024/05/10 22:19:36 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_cnv_dot	**trans_map(t_map *map, t_trans *trans)
{
	t_cnv_dot	**cnv_map;
	int			row;
	int			col;

	cnv_map = (t_cnv_dot **)malloc(sizeof(t_cnv_dot *) * map->row);
	row = 0;
	while (row < map->row)
	{
		col = 0;
		cnv_map[row] = (t_cnv_dot *)malloc(sizeof(t_cnv_dot) * map->col);
		while (col < map->col)
		{
			cnv_map[row][col].x_val = trans_x(map->mat[row][col], trans);
			cnv_map[row][col].x_val = trans_y(map->mat[row][col], trans);
			col++;
		}
		row++;
	}

}

double trans_x(t_dot dot, t_trans *trans)
{
	
}