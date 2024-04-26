/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:46:40 by ycho2             #+#    #+#             */
/*   Updated: 2024/04/26 21:12:01 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fd_error(void)
{
	perror ("file open failed");
	exit (1);
}

void	handle_malloc_error(void *mem)
{
	if (mem == 0)
	{
		ft_printf("malloc error\n");
		exit(1);
	}
}
