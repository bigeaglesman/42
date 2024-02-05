/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:15:17 by ycho2             #+#    #+#             */
/*   Updated: 2024/02/04 19:24:45 by ycho2            ###   ########.fr       */
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
	t_mat	*unit = unit_mat_create(3);
	t_mat	*y_30_rot = y_rot_mat(unit, 30);
	t_mat	*xy_30_rot = x_rot_mat(y_30_rot, 30);
	t_mat	*xy_proj = mat_create(3,3);

	t_mat	*a_1 = mat_create(3,1);
	a_1->mat[0][0] = 500+0;
	a_1->mat[1][0] = 500+0;
	a_1->mat[2][0] = 500+0;

	t_mat	*a_2 = mat_create(3,1);
	a_2->mat[0][0] = 500+100;
	a_2->mat[1][0] = 500+0;
	a_2->mat[2][0] = 500+0;

	t_mat	*a_3 = mat_create(3,1);
	a_3->mat[0][0] = 500+0;
	a_3->mat[1][0] = 500+0;
	a_3->mat[2][0] = 500+ 100;

	t_mat	*a_4 = mat_create(3,1);
	a_4->mat[0][0] = 500+ 100;
	a_4->mat[1][0] = 500+ 0;
	a_4->mat[2][0] = 500+ 100;

	t_mat	*b_1 = mat_create(3,1);
	b_1->mat[0][0] = 500+0;
	b_1->mat[1][0] = 500+ 100;
	b_1->mat[2][0] = 500+0;

	t_mat	*b_2 = mat_create(3,1);
	b_2->mat[0][0] = 500+ 100;
	b_2->mat[1][0] = 500+ 100;
	b_2->mat[2][0] = 500+ 0;

	t_mat	*b_3 = mat_create(3,1);
	b_3->mat[0][0] = 500+ 0;
	b_3->mat[1][0] = 500+ 100;
	b_3->mat[2][0] = 500+ 100;

	t_mat	*b_4 = mat_create(3,1);
	b_4->mat[0][0] = 500+ 100;
	b_4->mat[1][0] = 500+ 100;
	b_4->mat[2][0] = 500+ 100;

	xy_proj->mat[0][0] = 1;
	xy_proj->mat[1][1] = 1;

	t_mat *temp2_mat = mat_multiple(xy_proj,xy_30_rot);
	t_mat *a1 = mat_multiple(temp2_mat, a_1);
	t_mat *a2 = mat_multiple(temp2_mat, a_2);
	t_mat *a3 = mat_multiple(temp2_mat, a_3);
	t_mat *a4 = mat_multiple(temp2_mat, a_4);
	t_mat *b1 = mat_multiple(temp2_mat, b_1);
	t_mat *b2 = mat_multiple(temp2_mat, b_2);
	t_mat *b3 = mat_multiple(temp2_mat, b_3);
	t_mat *b4 = mat_multiple(temp2_mat, b_4);
	printf("a1 = %d, %d\n", (int)(a1->mat[0][0]), (int)(a1->mat[1][0]));
	printf("a2 = %d, %d\n", (int)(a2->mat[0][0]), (int)(a2->mat[1][0]));
	printf("a3 = %d, %d\n", (int)(a3->mat[0][0]), (int)(a3->mat[1][0]));
	printf("a4 = %d, %d\n", (int)(a4->mat[0][0]), (int)(a4->mat[1][0]));
	printf("b1 = %d, %d\n", (int)(b1->mat[0][0]), (int)(b1->mat[1][0]));
	printf("b2 = %d, %d\n", (int)(b2->mat[0][0]), (int)(b2->mat[1][0]));
	printf("b3 = %d, %d\n", (int)(b3->mat[0][0]), (int)(b3->mat[1][0]));
	printf("b4 = %d, %d\n", (int)(b4->mat[0][0]), (int)(b4->mat[1][0]));
	
	draw_line(data, (int)(a1->mat[0][0]), (int)(a1->mat[1][0]), (int)(b1->mat[0][0]), (int)(b1->mat[1][0]));
	draw_line(data, (int)(a2->mat[0][0]), (int)(a2->mat[1][0]), (int)(b2->mat[0][0]), (int)(b2->mat[1][0]));
	draw_line(data, (int)(a3->mat[0][0]), (int)(a3->mat[1][0]), (int)(b3->mat[0][0]), (int)(b3->mat[1][0]));
	draw_line(data, (int)(a4->mat[0][0]), (int)(a4->mat[1][0]), (int)(b4->mat[0][0]), (int)(b4->mat[1][0]));
	draw_line(data, (int)(a1->mat[0][0]), (int)(a1->mat[1][0]), (int)(a2->mat[0][0]), (int)(a2->mat[1][0]));
	draw_line(data, (int)(a3->mat[0][0]), (int)(a3->mat[1][0]), (int)(a4->mat[0][0]), (int)(a4->mat[1][0]));
	draw_line(data, (int)(a3->mat[0][0]), (int)(a3->mat[1][0]), (int)(a1->mat[0][0]), (int)(a1->mat[1][0]));
	draw_line(data, (int)(a4->mat[0][0]), (int)(a4->mat[1][0]), (int)(a2->mat[0][0]), (int)(a2->mat[1][0]));
	draw_line(data, (int)(b1->mat[0][0]), (int)(b1->mat[1][0]), (int)(b2->mat[0][0]), (int)(b2->mat[1][0]));
	draw_line(data, (int)(b3->mat[0][0]), (int)(b3->mat[1][0]), (int)(b4->mat[0][0]), (int)(b4->mat[1][0]));
	draw_line(data, (int)(b3->mat[0][0]), (int)(b3->mat[1][0]), (int)(b1->mat[0][0]), (int)(b1->mat[1][0]));
	draw_line(data, (int)(b4->mat[0][0]), (int)(b4->mat[1][0]), (int)(b2->mat[0][0]), (int)(b2->mat[1][0]));
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
