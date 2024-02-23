/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:55:21 by ycho2             #+#    #+#             */
/*   Updated: 2024/02/23 18:17:08 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_access_err(void)
{
	ft_printf("command access error\n");
	exit (1);
}

void	file_open_err(void)
{
	ft_printf("file open error\n");
	exit (1);
}

void	malloc_err(void)
{
	ft_printf("malloc error\n");
	exit(1);
}
