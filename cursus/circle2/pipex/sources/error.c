/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:55:21 by ycho2             #+#    #+#             */
/*   Updated: 2024/02/14 19:36:40 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	argument_err()
{
	perror("argument input error");
	exit (1);
}

void	file_access_err()
{
	perror("file access error");
	exit (1);
}

void	file_open_err()
{
	perror("file open error");
	exit (1);
}

void	pipe_malloc_err(int **pipe_arr, int i)
{
	free_pipe_arr(pipe_arr, i);
	perror("pipe malloc error");
	exit(1);
}