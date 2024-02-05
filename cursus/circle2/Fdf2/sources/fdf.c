/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:08:27 by ycho2             #+#    #+#             */
/*   Updated: 2024/02/05 15:51:11 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	prtimage();

int	main(int argc, char **argv)
{
	int fd;
	t_map	*map;

	if (argc != 2 || extension_validity(argv[1]))
	{
		perror("wrong argument");
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("file open error");
		exit(1);
	}	
	map = read_map(fd, argv[1]);
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
	// draw_line(&image, 300, 300, 900, 700);
	// draw_line(&image, 150, 270, 500, 444);
	// draw_line(&image, 800, 400, 900, 450);
	// draw_line(&image, 300, 300, 700, 900);
	// draw_line(&image, 150, 270, 250, 500);
	// draw_line(&image, 400, 100, 900, 900);
	// draw_rectangle(&image, 200, 200 , 100);
	draw_cube(&image);
	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_hook, 0); // close button press event
	mlx_loop(vars.mlx);
}
