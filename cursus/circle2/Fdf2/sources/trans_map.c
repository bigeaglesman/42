/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:14:35 by ycho2             #+#    #+#             */
/*   Updated: 2024/05/13 17:03:41 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double trans_x(t_dot dot, t_trans *t);
static double trans_y(t_dot dot, t_trans *t);

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
			cnv_map[row][col].y_val = trans_y(map->mat[row][col], trans);
			col++;
		}
		row++;
	}
	return (cnv_map);
}

static double trans_x(t_dot dot, t_trans *t)
{
	const int	x = dot.x_val;
	const int	y = dot.y_val;
	const int	z = dot.z_val;
	double		t_x;

	t_x = t->sca_xy * (x * t->cosy * t->cosz - y * t->sinz * t->cosy) + t->sca_z * z * t->siny + t->par_x;
	return (t_x);
}

static double trans_y(t_dot dot, t_trans *t)
{
	const int	x = dot.x_val;
	const int	y = dot.y_val;
	const int	z = dot.z_val;
	double		t_y;

	t_y = t->sca_xy * (x * (t->sinx * t->siny * t->cosz + t->cosx * t->sinz) \
			+ y * (-t->sinx * t->siny * t->sinz + t->cosx * t->cosz)) - t->sca_z * z * t->sinx * t->cosy + t->par_y;
	return (t_y);
}