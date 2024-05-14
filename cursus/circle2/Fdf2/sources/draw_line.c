/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:15:17 by ycho2             #+#    #+#             */
/*   Updated: 2024/05/14 10:36:40 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	line_desc(t_data *data, t_cnv_dot from, t_cnv_dot to, double gradient, t_trans *trans);
static void line_asc(t_data *data, t_cnv_dot from, t_cnv_dot to, double gradient, t_trans *trans);

void	draw_line(t_data *data, t_cnv_dot from, t_cnv_dot to, t_trans *trans)
{
	double		gradient;
	t_cnv_dot	start;
	t_cnv_dot	dest;

	if (from.x_val <= to.x_val)
	{
		start = from;
		dest = to;
	}
	else
	{
		start = to;
		dest = from;
	}
	gradient = (double)(dest.y_val - start.y_val) / (dest.x_val - start.x_val);
	if (gradient < 0)
		line_desc(data, start, dest, gradient, trans);
	else
		line_asc(data, start, dest, gradient, trans);
}

static void	line_desc(t_data *data, t_cnv_dot start, t_cnv_dot dest, double gradient, t_trans *trans)
{
	t_line_utils	line_utils;

	line_utils.w = dest.x_val - start.x_val;
	line_utils.h = start.y_val - dest.y_val ;
	line_utils.start_x = start.x_val;
	line_utils.start_y = start.y_val;
	line_utils.start_color = start.color;
	line_utils.final_color = dest.color;
	if (gradient < -1)
		draw_line_desc_h(data, line_utils, dest.y_val, trans);
	else
		draw_line_desc_w(data, line_utils, dest.x_val, trans);
}

static void line_asc(t_data *data, t_cnv_dot start, t_cnv_dot dest, double gradient, t_trans *trans)
{
	t_line_utils	line_utils;

	line_utils.w = dest.x_val - start.x_val;
	line_utils.h = dest.y_val - start.y_val;
	line_utils.start_x = start.x_val;
	line_utils.start_y = start.y_val;
	line_utils.start_color = start.color;
	line_utils.final_color = dest.color;
	if (gradient < 1)
		draw_line_asc_w(data, line_utils, dest.x_val, trans);
	else
		draw_line_asc_h(data, line_utils, dest.y_val, trans);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color) //img에 점 찍어주는 함수
{
	char	*dst;

	// printf("(%d, %d) ", x, y);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
