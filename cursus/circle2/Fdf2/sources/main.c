/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:27:03 by ycho2             #+#    #+#             */
/*   Updated: 2024/04/28 19:19:24 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	int		fd;

	if (argc != 2 || extension_validity(argv[1]))
	{
		ft_printf("wrong argument\n");
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		fd_error();
	map = parse_map(fd);
	t_dot *dot = map->dot_list;
	int i = 1;
	while (dot)
	{
		ft_printf("z_val: %d , color: %x\n", dot->z_val, dot->color);
		dot = dot->next;
		if (i % map->col == 0)
			ft_printf("new row\n");
		i++;
	}
	ft_printf("%d\n", map->col);
	return (0);
}
