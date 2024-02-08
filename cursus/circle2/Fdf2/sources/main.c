/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:27:03 by ycho2             #+#    #+#             */
/*   Updated: 2024/02/08 14:49:28 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_dot	**map;

	if (argc != 2 || extension_validity(argv[1]))
	{
		perror("wrong argument");
		exit(1);
	}
	map = read_map(argv[1]);
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 19; j++)
			printf("[%d][%d]=%d %d  ",i, j, (int)map[i][j].coord->mat[2][0], (int)map[i][j].color);
		printf("\n");
	}
	prtimage();
	return (0);
}