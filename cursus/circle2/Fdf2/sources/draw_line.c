/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:15:17 by ycho2             #+#    #+#             */
/*   Updated: 2024/05/17 10:22:04 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line_w (t_data *data, t_draw_utils draw_utils, int is_ascend);
static void	draw_line_h (t_data *data, t_draw_utils draw_utils, int is_ascend);
static void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
static void	draw_line_sub(t_data *data, t_draw_utils draw_utils, t_cnv_dot from, t_cnv_dot to);

void	draw_line(t_data *data, t_cnv_dot from, t_cnv_dot to, t_trans *trans)
{
	t_draw_utils	draw_utils;

	if (from.x_val <= to.x_val)
	{
		draw_utils.start = from;
		draw_utils.dest = to;
	}
	else
	{
		draw_utils.start = to;
		draw_utils.dest = from;
	}
	draw_utils.gradient = (double)(draw_utils.dest.y_val - draw_utils.start.y_val) / (draw_utils.dest.x_val - draw_utils.start.x_val);
	draw_utils.win_height = trans->win_height;
	draw_utils.win_width = trans->win_width;
	draw_utils.w = draw_utils.dest.x_val - draw_utils.start.x_val;
	if (draw_utils.gradient < 0)
		draw_utils.h = draw_utils.start.y_val - draw_utils.dest.y_val;
	else
		draw_utils.h = draw_utils.dest.y_val - draw_utils.start.y_val;
	draw_line_sub(data, draw_utils, from, to);
}

static void	draw_line_sub(t_data *data, t_draw_utils draw_utils, t_cnv_dot from, t_cnv_dot to)
{
	if (from.color == 0 && to.color == 0)
		draw_utils.color = 0;
	else if (from.color != 0)
		draw_utils.color = from.color;
	else
		draw_utils.color = to.color;
	if (draw_utils.gradient > 0 && draw_utils.gradient < 1)
		draw_line_w(data, draw_utils, 1);
	else if (draw_utils.gradient >= 1)
		draw_line_h(data, draw_utils, 1);
	else if (draw_utils.gradient <= 0 && draw_utils.gradient > -1)
		draw_line_w(data, draw_utils, -1);
	else
		draw_line_h(data, draw_utils, -1);
}

static void	draw_line_w (t_data *data, t_draw_utils draw_utils, int is_ascend)
{
	int	m;
	int	x;
	int y;
	int dest_x;

	x = draw_utils.start.x_val;
	y = draw_utils.start.y_val;
	dest_x = draw_utils.dest.x_val;
	m = draw_utils.w - 2 * draw_utils.h;
	while (x <= dest_x)
	{
		if (x >= 0 && x < draw_utils.win_width && y >= 0 && y < draw_utils.win_height)
			my_mlx_pixel_put(data, x, y, draw_utils.color);
		if (m > 0)
			m -= 2 * draw_utils.h;
		else
		{
			m += 2 * (draw_utils.w - draw_utils.h);
			if (is_ascend == 1)
				y++;
			else
				y--;
		}
		x++;
	}
}

static void	draw_line_h (t_data *data, t_draw_utils draw_utils, int is_ascend)
{
	int	m;
	int	x;
	int	y;
	int	y_leng;

	x = draw_utils.start.x_val;
	y = draw_utils.start.y_val;
	y_leng = fabs(draw_utils.dest.y_val - y);
	m = 2 * draw_utils.w - draw_utils.h;
	while (y_leng >= 0)
	{
		if (x >= 0 && x < draw_utils.win_width && y >= 0 && y < draw_utils.win_height)
			my_mlx_pixel_put(data, x, y, draw_utils.color);
		if (m < 0)
			m += 2 * draw_utils.w;
		else
		{
			m += 2 * (draw_utils.w - draw_utils.h);
			x++;
		}
		y += is_ascend;
		y_leng--;
	}
}

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color) //img에 점 찍어주는 함수
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
