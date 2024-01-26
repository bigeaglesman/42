/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:15:17 by ycho2             #+#    #+#             */
/*   Updated: 2024/01/26 22:34:33 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw_line(t_data *data, const int x1, const int y1, const int x2, const int y2,)
{
	int	x;
	int y;

	x = x1;
	while (x <= x1)
	{
		if (x == x1)
			y = y1;
		else
		{
			if ((-x2+x1)*(2*y+1-2*y1)+(y2-y1)(2*x+2-2*x1) > 0)
				y++;
		}
		my_mlx_pixel_put(data, x, y, 0xff0000);
		x++;
	}

	
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
