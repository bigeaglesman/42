/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:27:03 by ycho2             #+#    #+#             */
/*   Updated: 2024/02/06 17:07:06 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2 || extension_validity(argv[1]))
	{
		perror("wrong argument");
		exit(1);
	}
	map = read_map(argv[1]);
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 19; j++)
			printf("[%d][%d]=%d 0x%x  ",i, j, (map->map[i][j]).z_val, (map->map[i][j]).color);
		printf("\n");
	}
	prtimage();
	return (0);
}