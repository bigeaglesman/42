/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:15:17 by ycho2             #+#    #+#             */
/*   Updated: 2024/04/30 03:45:42 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_data *data, t_mat *a, t_mat *b) //선 그려주는 함수
{
	const int	w = (int)(b->mat[0][0] - a->mat[0][0]);
	const int	h = (int)(b->mat[1][0] - a->mat[1][0]);

	if (w >= h)
		draw_line_x(data, a, b);
	else
		draw_line_y(data, a, b);
}

void	draw_line_y(t_data *data, t_mat *a, t_mat *b)
{
	const int	w = (int)(b->mat[0][0] - a->mat[0][0]);
	const int	h = (int)(b->mat[1][0] - a->mat[1][0]);
	int			m;
	int			y;
	int			x;

	x = (int)(a->mat[0][0]);
	y = (int)(a->mat[1][0]);
	m = h - 2 * w;
	while (y <= (int)(b->mat[1][0]))
	{
		my_mlx_pixel_put(data, x, y, 0xffffff);
		if (m > 0)
			m -= 2 * w;
		else
		{
			m += 2 *(h - w);
			x++;
		}
		y++;
	}
}

void	draw_line_x(t_data *data, t_mat *a, t_mat *b)
{
	const int	w = (int)(b->mat[0][0] - a->mat[0][0]);
	const int	h = (int)(b->mat[1][0] - a->mat[1][0]);
	int			m;
	int			y;
	int			x;

	x = (int)(a->mat[0][0]);
	y = (int)(a->mat[1][0]);
	m = w - 2 * h;
	while (x <= (int)(b->mat[0][0]))
	{
		my_mlx_pixel_put(data, x, y, 0xff0000);
		if (m > 0)
			m -= 2 * h;
		else
		{
			m += 2 * (w - h);
			y++;
		}
		x++;
	}
}

void draw_test(t_map *map)
{
	int		row;
	int		col;
	t_cnvdot	**cnv_map;
	const double cos30 = cos(PI/6);
	const double sin30 = sin(PI/6);
	const double cos45 = cos(PI/4);
	const double sin45 = sin(PI/6);

	row = 0;
	cnv_map = (t_cnvdot **)malloc(sizeof(t_cnvdot *) * map->row);
	printf("%f %f %f %f\n", cos30, sin30, cos45, sin45);
	while (row < map->row)
	{
		col = 0;
		cnv_map[row] = (t_cnvdot *)malloc(sizeof(t_cnvdot) * map->col);
		while (col < map->col)
		{
			cnv_map[row][col].x_val = ((double)map->mat[row][col].x_val)*cos30 - ((double)map->mat[row][col].y_val)*sin30;
			cnv_map[row][col].y_val = map->mat[row][col].x_val*sin30*cos45 + map->mat[row][col].y_val*cos45*cos30 - map->mat[row][col].z_val * sin45;
			col++;
		}
		printf("\n");
		row++;
	}
	for (int row = 0; row < map->row; row++)
	{
		for (int col = 0; col < map->col; col++)
			printf("x %f y %f ", cnv_map[row][col].x_val, cnv_map[row][col].y_val);
		printf("\n");
	}
	// draw_map(data, cnv_map);
}

// void draw_cube(t_data *data)
// {
// 	t_mat	*unit = unit_mat_create(4);
// 	t_mat	*y_30_rot = y_rot_mat(unit, 45);
// 	t_mat	*xy_30_rot = x_rot_mat(y_30_rot, 30);
// 	t_mat	*xyz_rot = z_rot_mat(xy_30_rot, 30);
// 	t_mat	*xy_proj = n_mat_proj(xyz_rot, 'z');
// 	t_mat	*par_mov = mat_par_mov(xy_proj, 500, 500, 0);

// 	t_mat	*a_1 = mat_create(4,1);
// 	a_1->mat[0][0] = 0;
// 	a_1->mat[1][0] = 0;
// 	a_1->mat[2][0] = 0;
// 	a_1->mat[3][0] = 1;

// 	t_mat	*a_2 = mat_create(4,1);
// 	a_2->mat[0][0] = 100;
// 	a_2->mat[1][0] = 0;
// 	a_2->mat[2][0] = 0;
// 	a_2->mat[3][0] = 1;

// 	t_mat	*a_3 = mat_create(4,1);
// 	a_3->mat[0][0] = 0;
// 	a_3->mat[1][0] = 0;
// 	a_3->mat[2][0] =  100;
// 	a_3->mat[3][0] = 1;

// 	t_mat	*a_4 = mat_create(4,1);
// 	a_4->mat[0][0] =  100;
// 	a_4->mat[1][0] =  0;
// 	a_4->mat[2][0] =  100;
// 	a_4->mat[3][0] = 1;

// 	t_mat	*b_1 = mat_create(4,1);
// 	b_1->mat[0][0] = 0;
// 	b_1->mat[1][0] =  100;
// 	b_1->mat[2][0] = 0;
// 	b_1->mat[3][0] = 1;

// 	t_mat	*b_2 = mat_create(4,1);
// 	b_2->mat[0][0] =  100;
// 	b_2->mat[1][0] =  100;
// 	b_2->mat[2][0] =  0;
// 	b_2->mat[3][0] = 1;

// 	t_mat	*b_3 = mat_create(4,1);
// 	b_3->mat[0][0] =  0;
// 	b_3->mat[1][0] =  100;
// 	b_3->mat[2][0] =  100;
// 	b_3->mat[3][0] = 1;

// 	t_mat	*b_4 = mat_create(4,1);
// 	b_4->mat[0][0] =  100;
// 	b_4->mat[1][0] =  100;
// 	b_4->mat[2][0] =  100;
// 	b_4->mat[3][0] = 1;

// 	t_mat *a1 = mat_multiple(par_mov, a_1);
// 	t_mat *a2 = mat_multiple(par_mov, a_2);
// 	t_mat *a3 = mat_multiple(par_mov, a_3);
// 	t_mat *a4 = mat_multiple(par_mov, a_4);
// 	t_mat *b1 = mat_multiple(par_mov, b_1);
// 	t_mat *b2 = mat_multiple(par_mov, b_2);
// 	t_mat *b3 = mat_multiple(par_mov, b_3);
// 	t_mat *b4 = mat_multiple(par_mov, b_4);
// 	printf("a1 = %f, %f\n", (a1->mat[0][0]), (a1->mat[1][0]));
// 	printf("a2 = %f, %f\n", (a2->mat[0][0]), (a2->mat[1][0]));
// 	printf("a3 = %f, %f\n", (a3->mat[0][0]), (a3->mat[1][0]));
// 	printf("a4 = %f, %f\n", (a4->mat[0][0]), (a4->mat[1][0]));
// 	printf("b1 = %f, %f\n", (b1->mat[0][0]), (b1->mat[1][0]));
// 	printf("b2 = %f, %f\n", (b2->mat[0][0]), (b2->mat[1][0]));
// 	printf("b3 = %f, %f\n", (b3->mat[0][0]), (b3->mat[1][0]));
// 	printf("b4 = %f, %f\n", (b4->mat[0][0]), (b4->mat[1][0]));
	
// 	draw_line(data, a1, b1);
// 	draw_line(data, a2, b2);
// 	draw_line(data, a3, b3);
// 	draw_line(data, a4, b4);
// 	draw_line(data, a1, a2);
// 	draw_line(data, a3, a4);
// 	draw_line(data, a3, a1);
// 	draw_line(data, a4, a2);
// 	draw_line(data, b1, b2);
// 	draw_line(data, b3, b4);
// 	draw_line(data, b3, b1);
// 	draw_line(data, b4, b2);
// }

void	my_mlx_pixel_put(t_data *data, int x, int y, int color) //img에 점 찍어주는 함수
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
