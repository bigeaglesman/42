/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:10:35 by ycho2             #+#    #+#             */
/*   Updated: 2024/02/17 14:01:05 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int **create_pipe_arr(int num_pipe)
{
	int	**pipe_arr;
	int	i;

	pipe_arr = (int **)malloc(num_pipe * sizeof(int *));
	if (!pipe_arr)
		pipe_malloc_err(pipe_arr, -1);
	i = 0;
	while (i < num_pipe)
	{
		pipe_arr[i] = (int *)malloc(2 * sizeof(int));
		if (!pipe_arr[i])
			pipe_malloc_err(pipe_arr, i);
		pipe(pipe_arr[i]);
		i++;
	}
	return (pipe_arr);
}

void	free_pipe_arr(int **pipe_arr, int i)
{
	while (i > 0)
	{
		free (pipe_arr[i - 1]);
		i--;
	}
	free (pipe_arr);
}

void	close_unusing_pipe(int num, int total_pipe, int **pipe_arr)
{
	int i;

	int i = 0;
	while (i < total_pipe)
	{
		if (i != num)
			close(pipe_arr[i][0]);
		if (i != num + 1)
			close(pipe_arr[i][1]);
		i++;
	}
}