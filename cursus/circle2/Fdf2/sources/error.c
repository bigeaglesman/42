/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:46:40 by ycho2             #+#    #+#             */
/*   Updated: 2024/04/29 15:09:57 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_malloc_error(void *mem)
{
	if (mem == 0)
	{
		ft_printf("malloc error\n");
		exit(1);
	}
}

void	map_file_error(void)
{
	ft_printf("map column error\n");
	exit(1);
}
