/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:15:17 by ycho2             #+#    #+#             */
/*   Updated: 2024/01/27 18:50:15 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void draw_line(t_data *data, const int x1, const int y1, const int x2, const int y2)
// {
// 	int	x;
// 	int y;

// 	x = x1;
// 	y = y1;
// 	while (x <= x2)
// 	{
// 		my_mlx_pixel_put(data, x, y, 0xff0000);
// 		if ((-x2+x1)*(2*y+1-2*y1)+(y2-y1)*(2*x+2-2*x1) > 0)
// 			y++;
// 		x++;
// 	}

	
// }

void draw_rectangle(t_data *data, const int x_c, const int y_c, const int width)
{
	int a;

	a = width / 2;
	draw_line(data, x_c - a, y_c - a, x_c - a, y_c + a);
	draw_line(data, x_c + a, y_c - a, x_c + a, y_c + a);
	draw_line(data, x_c - a, y_c + a, x_c + a, y_c + a);
	draw_line(data, x_c - a, y_c - a, x_c + a, y_c - a);
}

void draw_line(t_data *data, const int x1, const int y1, const int x2, const int y2)
{
	const int	w = x2 - x1;
	const int	h = y2 - y1;

	if (w >= h)
		draw_line_x(data, x1, y1, x2, y2);
	else
		draw_line_y(data, x1, y1, x2, y2);
}

void draw_line_y(t_data *data, int x1, int y1, const int x2, const int y2)
{
	const int	w = x2 -x1;
	const int	h = y2 - y1;
	int	m;

	m = h - 2 * w;
	while (y1 <= y2)
	{
		my_mlx_pixel_put(data, x1, y1, 0xff0000);
		if (m > 0)
			m -= 2*w;
		else
		{
			m += 2*(h - w);
			x1++;
		}
		y1++;
	}
}

void draw_line_x(t_data *data, int x1, int y1, const int x2, const int y2)
{
	const int	w = x2 -x1;
	const int	h = y2 - y1;
	int	m;

	m = w - 2 * h;
	while (x1 <= x2)
	{
		my_mlx_pixel_put(data, x1, y1, 0xff0000);
		if (m > 0)
			m -= 2*h;
		else
		{
			m += 2*(w - h);
			y1++;
		}
		x1++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
