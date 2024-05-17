/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:27:03 by ycho2             #+#    #+#             */
/*   Updated: 2024/05/17 10:35:12 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_trans	*set_trans(t_map *map);
static void		get_size_val(t_map *map, t_trans *trans);
static void		draw_map(t_data *data, t_map *map, t_trans *trans);

int	main(int argc, char **argv)
{
	t_map	*map;
	t_trans	*trans;
	t_vars	vars;
	t_data	image;

	if (argc != 2 || extension_validity(argv[1]))
	{
		ft_printf("wrong argument\n");
		exit(1);
	}
	map = parse_map(argv[1]);
	vars.mlx = mlx_init();
	trans = set_trans(map);
	vars.win = mlx_new_window(vars.mlx, trans->win_width, trans->win_height, "fdf");
	image.img = mlx_new_image(vars.mlx, trans->win_width, trans->win_height);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
	draw_map(&image, map, trans);
	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_hook, 0); // close button press event
	mlx_loop(vars.mlx);
	return (0);
}

static t_trans	*set_trans(t_map *map)
{
	t_trans *trans = (t_trans *)malloc(sizeof(t_trans));
	
	get_size_val(map, trans);
	trans->cosx = cos(PI/6);
	trans->sinx = sin(PI/6);
	trans->siny = sin(0);
	trans->cosy = cos(0);
	trans->cosz = cos(PI/4);
	trans->sinz = sin(PI/4);
	return (trans);
}

static void get_size_val(t_map *map, t_trans *trans)
{
	double	win_size;

	if (map->col > map->row)
		win_size = map->col * ROOT2;
	else
		win_size = map->row * ROOT2;
	trans->win_height = 2000;
	trans->win_width = 2500;
	trans->par_x = 1250;
	trans->sca_xy = 1500 / win_size;
	trans->sca_z = 900 / win_size;
	if (trans->sca_xy < 3)
		trans->sca_xy = 3;
	if (trans->sca_z > 15)
		trans->sca_z = 15;
	if (trans->sca_z < 3)
		trans->sca_z = 3;
	trans->par_y = (trans->win_height - win_size * trans->sca_xy) / 4;
}

static void	draw_map(t_data *data, t_map *map, t_trans *trans)
{
	int			x;
	int			y;
	t_cnv_dot	**cnv_map;

	cnv_map = trans_map(map, trans);
	y = 0;
	while (y < map->row)
	{
		x = 0;
		while (x < map->col)
		{
			if (x != map->col-1)
				draw_line(data, cnv_map[y][x], cnv_map[y][x+1], trans);
			if (y != map->row-1)
				draw_line(data, cnv_map[y][x], cnv_map[y+1][x], trans);
			x++;
		}
		y++;
	}
}
