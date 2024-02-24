/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:55:21 by ycho2             #+#    #+#             */
/*   Updated: 2024/02/24 15:55:03 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_access_err(void)
{
	perror("command access error");
	exit (1);
}

void	file_open_err(void)
{
	perror("file open error");
	exit (1);
}

void	malloc_err(void)
{
	perror("malloc error");
	exit(1);
}
