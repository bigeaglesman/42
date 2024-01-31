/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:15:17 by ycho2             #+#    #+#             */
/*   Updated: 2024/01/31 19:02:15 by ycho2            ###   ########.fr       */
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
			m -= 2 * h;
		else
		{
			m += 2 * (w - h);
			y1++;
		}
		x1++;
	}
}

void draw_cube(t_data *data)
{
	t_mat	*y_trans = mat_create(3, 3);
	t_mat	*z_trans = mat_create(3,3);
	t_mat	*xy_proj = mat_create(3,3);
	double pi = PI;

	int cos_45 = (int)(cos(45 * pi /180)+0.5);
	int cos_m30 = (int)(cos(-30 * pi /180)+0.5);
	int sin_m30 = (int)(sin(-30 * pi /180)+0.5);

	t_mat	*a = mat_create(3,1);
	a->mat[0][0] = 200;
	a->mat[1][0] = 100;

	t_mat	*b = mat_create(3,1);
	b->mat[0][0] = 300;
	b->mat[1][0] = 300;

	y_trans->mat[0][0] = cos_45;
	y_trans->mat[2][2] = cos_45;
	y_trans->mat[0][2] = -cos_45;
	y_trans->mat[2][1] = cos_45;
	y_trans->mat[1][1] = 1;

	z_trans->mat[0][0] = cos_m30;
	z_trans->mat[0][1] = -sin_m30;
	z_trans->mat[1][0] = sin_m30;
	z_trans->mat[1][1] = cos_m30;
	z_trans->mat[2][2] = 1;

	xy_proj->mat[0][0] = 1;
	xy_proj->mat[1][1] = 1;

	t_mat *temp_mat = mat_multiple(z_trans, y_trans);
	t_mat *temp2_mat = mat_multiple(xy_proj,temp_mat);
	t_mat *temp3_mat = mat_multiple(temp2_mat, a);
	t_mat *temp4_mat = mat_multiple(temp2_mat, b);
	printf("3[0][0]:%d 3[1][0]:%d 4[0][0]%d 4[1][0]%d\n", temp3_mat->mat[0][0], temp3_mat->mat[1][0], temp4_mat->mat[0][0], temp4_mat->mat[1][0]);

	draw_line(data, temp3_mat->mat[0][0], temp3_mat->mat[1][0], temp4_mat->mat[0][0], temp4_mat->mat[1][0]);
	free(temp2_mat);
	free(temp_mat);
	free(temp3_mat);
	free(temp4_mat);
	free(xy_proj);
	free(z_trans);
	free(y_trans);
	free(a);
	free(b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
