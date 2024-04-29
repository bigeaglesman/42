/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:27:03 by ycho2             #+#    #+#             */
/*   Updated: 2024/04/29 23:09:27 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2 || extension_validity(argv[1]))
	{
		ft_printf("wrong argument\n");
		exit(1);
	}
	map = parse_map(argv[1]);
	draw_test(map);

	// prtimage(map);
	return (0);
}
