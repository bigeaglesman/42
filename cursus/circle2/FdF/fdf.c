/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:08:27 by ycho2             #+#    #+#             */
/*   Updated: 2024/01/26 22:35:39 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	prtimage();

int	main()
{
	// if (argc != 2 || check_file_validity(argv[1]))
	prtimage();
	return (0);
}

void	prtimage()
{
	t_vars	vars;
	t_data	image;
	const int	img_width = 1000;
	const int	img_height = 1000;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, img_width, img_height, "fdf");
	image.img = mlx_new_image(vars.mlx, img_width, img_height);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	mlx_event_control(&vars);
}
