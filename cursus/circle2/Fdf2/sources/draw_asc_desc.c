/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_asc_desc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:15:57 by ycho2             #+#    #+#             */
/*   Updated: 2024/05/10 13:37:43 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line_desc_h(t_data *data, t_line_utils line_utils, int final_y)
{
	int	m;
	int	x;
	int	y;

	x = line_utils.start_x;
	y = line_utils.start_y;
	m = 2 * line_utils.w - line_utils.h;
	while (y >= final_y)
	{
		my_mlx_pixel_put(data, x, y, 0x0000ff);
		if (m < 0)
			m += 2 * line_utils.w;
		else
		{
			m += 2 * (line_utils.w - line_utils.h);
			x++;
		}
		y--;
	}
}

void	draw_line_desc_w(t_data *data, t_line_utils line_utils, int final_x)
{
	int			m;
	int			y;
	int			x;

	x = line_utils.start_x;
	y = line_utils.start_y;
	m = line_utils.w - 2 * line_utils.h;
	while (x <= final_x)
	{
		my_mlx_pixel_put(data, x, y, 0xff0000);
		if (m > 0)
			m -= 2 * line_utils.h;
		else
		{
			m += 2 * (line_utils.w - line_utils.h);
			y--;
		}
		x++;
	}
}

void	draw_line_asc_h(t_data *data, t_line_utils line_utils, int final_y)
{
	int	m;
	int	x;
	int	y;

	x = line_utils.start_x;
	y = line_utils.start_y;
	m = 2 * line_utils.w - line_utils.h;
	while (y <= final_y)
	{
		my_mlx_pixel_put(data, x, y, 0xff00ff);
		if (m < 0)
			m += 2 * line_utils.w;
		else
		{
			m += 2 * (line_utils.w - line_utils.h);
			x++;
		}
		y++;
	}
}

void	draw_line_asc_w(t_data *data, t_line_utils line_utils, int final_x)
{
	int			m;
	int			y;
	int			x;

	x = line_utils.start_x;
	y = line_utils.start_y;
	m = line_utils.w - 2 * line_utils.h;
	while (x <= final_x)
	{
		my_mlx_pixel_put(data, x, y, 0xff0000);
		if (m > 0)
			m -= 2 * line_utils.h;
		else
		{
			m += 2 * (line_utils.w - line_utils.h);
			y++;
		}
		x++;
	}
}
