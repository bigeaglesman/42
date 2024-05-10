/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:15:17 by ycho2             #+#    #+#             */
/*   Updated: 2024/05/10 16:27:33 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	line_desc(t_data *data, t_cnv_dot from, t_cnv_dot to, double gradient);
static void line_asc(t_data *data, t_cnv_dot from, t_cnv_dot to, double gradient);
static void	draw_map(t_data *data, t_cnv_dot **cnv_map, int row, int col);

void	draw_line(t_data *data, t_cnv_dot from, t_cnv_dot to)
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
		line_desc(data, start, dest, gradient);
	else
		line_asc(data, start, dest, gradient);
}

static void	line_desc(t_data *data, t_cnv_dot start, t_cnv_dot dest, double gradient)
{
	t_line_utils	line_utils;

	line_utils.w = dest.x_val - start.x_val;
	line_utils.h = start.y_val - dest.y_val ;
	line_utils.start_x = start.x_val;
	line_utils.start_y = start.y_val;
	if (gradient < -1)
		draw_line_desc_h(data, line_utils, dest.y_val);
	else
		draw_line_desc_w(data, line_utils, dest.x_val);
}

static void line_asc(t_data *data, t_cnv_dot start, t_cnv_dot dest, double gradient)
{
	t_line_utils	line_utils;

	line_utils.w = dest.x_val - start.x_val;
	line_utils.h = dest.y_val - start.y_val;
	line_utils.start_x = start.x_val;
	line_utils.start_y = start.y_val;
	if (gradient < 1)
		draw_line_asc_w(data, line_utils, dest.x_val);
	else
		draw_line_asc_h(data, line_utils, dest.y_val);
}

void draw_test(t_data *data, t_map *map)
{
	int		row;
	int		col;
	t_cnv_dot	**cnv_map;
	const double cos30 = cos(PI/6);
	const double sin30 = sin(PI/6);
	const double cos45 = cos(PI/4);
	const double sin45 = sin(PI/6);

	row = 0;
	cnv_map = (t_cnv_dot **)malloc(sizeof(t_cnv_dot *) * map->row);
	printf("%f %f %f %f\n", cos30, sin30, cos45, sin45);
	while (row < map->row)
	{
		col = 0;
		cnv_map[row] = (t_cnv_dot *)malloc(sizeof(t_cnv_dot) * map->col);
		while (col < map->col)
		{
			cnv_map[row][col].x_val = (((double)map->mat[row][col].x_val)*cos30 - ((double)map->mat[row][col].y_val)*sin30)*5 + 500;
			cnv_map[row][col].y_val = (map->mat[row][col].x_val*sin30*cos45 + map->mat[row][col].y_val*cos45*cos30 - map->mat[row][col].z_val * sin45) * 30 + 500;
			col++;
		}
		row++;
	}
	// for (int row = 0; row < map->row; row++)
	// {
	// 	for (int col = 0; col < map->col; col++)
	// 		printf("x %f y %f ", cnv_map[row][col].x_val, cnv_map[row][col].y_val);
	// 	printf("\n");
	// }
	draw_map(data, cnv_map, map->row, map->col);
}

static void	draw_map(t_data *data, t_cnv_dot **cnv_map, int row, int col)
{
	int	x;
	int	y;

	y = 0;
	while (y < row)
	{
		x = 0;
		while (x < col)
		{
			if (x != col-1)
			{
				draw_line(data, cnv_map[y][x], cnv_map[y][x+1]);
				// printf("\n");
			}
			if (y != row-1)
			{
				draw_line(data, cnv_map[y][x], cnv_map[y+1][x]);
				// printf("\n");
			}

			x++;
		}
		y++;
	}
				// printf("\n");
				// printf("\n");
				// printf("\n");
	y = 0;
	while (y < row)
	{
		x = 0;
		while (x < col)
		{
			my_mlx_pixel_put(data, cnv_map[y][x].x_val, cnv_map[y][x].y_val, 0xffffff);
			x++;
		}
		y++;
	}
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

	// printf("(%d, %d) ", x, y);
	if (x >= 0 && x <= 999 && y >= 0 && y <= 999)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}
