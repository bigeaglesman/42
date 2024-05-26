/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:15:17 by ycho2             #+#    #+#             */
/*   Updated: 2024/05/21 13:56:17 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line_w(t_data *data, t_draw draw, int is_ascend);
static void	draw_line_h(t_data *data, t_draw draw, int is_ascend);
static void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
static void	draw_sub(t_data *data, t_draw draw, t_cnv_dot from, t_cnv_dot to);

void	draw_line(t_data *data, t_cnv_dot from, t_cnv_dot to, t_trans *trans)
{
	t_draw	draw;

	if (from.x_val <= to.x_val)
	{
		draw.start = from;
		draw.dest = to;
	}
	else
	{
		draw.start = to;
		draw.dest = from;
	}
	draw.gradient = (double)(draw.dest.y_val - draw.start.y_val)
		/ (draw.dest.x_val - draw.start.x_val);
	draw.win_height = trans->win_height;
	draw.win_width = trans->win_width;
	draw.w = draw.dest.x_val - draw.start.x_val;
	if (draw.gradient < 0)
		draw.h = draw.start.y_val - draw.dest.y_val;
	else
		draw.h = draw.dest.y_val - draw.start.y_val;
	draw_sub(data, draw, from, to);
}

static void	draw_sub(t_data *data, t_draw draw, t_cnv_dot from, t_cnv_dot to)
{
	if (from.color == 0 && to.color == 0)
		draw.color = 0;
	else if (from.color != 0)
		draw.color = from.color;
	else
		draw.color = to.color;
	if (draw.gradient > 0 && draw.gradient < 1)
		draw_line_w(data, draw, 1);
	else if (draw.gradient >= 1)
		draw_line_h(data, draw, 1);
	else if (draw.gradient <= 0 && draw.gradient > -1)
		draw_line_w(data, draw, -1);
	else
		draw_line_h(data, draw, -1);
}

static void	draw_line_w(t_data *data, t_draw draw, int is_ascend)
{
	int	m;
	int	x;
	int	y;
	int	dest_x;

	x = draw.start.x_val;
	y = draw.start.y_val;
	dest_x = draw.dest.x_val;
	m = draw.w - 2 * draw.h;
	while (x <= dest_x)
	{
		if (x >= 0 && x < draw.win_width && y >= 0 && y < draw.win_height)
			my_mlx_pixel_put(data, x, y, draw.color);
		if (m > 0)
			m -= 2 * draw.h;
		else
		{
			m += 2 * (draw.w - draw.h);
			if (is_ascend == 1)
				y++;
			else
				y--;
		}
		x++;
	}
}

static void	draw_line_h(t_data *data, t_draw draw, int is_ascend)
{
	int	m;
	int	x;
	int	y;
	int	y_leng;

	x = draw.start.x_val;
	y = draw.start.y_val;
	y_leng = abs((int)draw.dest.y_val - y);
	m = 2 * draw.w - draw.h;
	while (y_leng >= 0)
	{
		if (x >= 0 && x < draw.win_width && y >= 0 && y < draw.win_height)
			my_mlx_pixel_put(data, x, y, draw.color);
		if (m < 0)
			m += 2 * draw.w;
		else
		{
			m += 2 * (draw.w - draw.h);
			x++;
		}
		y += is_ascend;
		y_leng--;
	}
}

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
