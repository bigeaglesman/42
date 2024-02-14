/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:24:27 by ycho2             #+#    #+#             */
/*   Updated: 2024/02/14 22:05:19 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv)
{
	int	**pipe;

	if (argc < 4)
		argument_err();
	if (argv[1] == "here_doc")
		return (pipex_here_doc(argc, argv));
	else
		return (pipex_file(argc, argv));
}

int	pipex_here_doc(int argc, char **argv)
{
	int		**pipe;
	char	*line;
	int		i;
	int		pid;

	pipe = create_pipe_arr(argc - 3);
	i = 0;
	while (i < argc - 4)
	{
		pid = fork();
		if (pid < 0)
			fork_err();
		else if (pid == 0)
		{
			dup2(pipe[i+1][1], 1);
			execve();
		}
		else
		{
			waitpid(pid, 0, 0);
			i++;
		}
	}
	close_unusing_pipe(0);
	line = get_next_line(0);
	while (!check_marker(line, argv[2]))
	{
		write(pipe[0][1], line, ft_strlen(line) + 1);
		free(line);
		line = get_next_line(0);
	}

}

int	check_marker(char *str, char *marker)
{
	int	marker_len;

	marker_len = ft_strlen(marker);
	return (ft_strncmp(str, marker, marker_len -1));
}

int	pipex_file(int argc, char **argv)
{
	int	**pipe;
	int	file1_fd;

	file1_fd = open_file(argv[1]);
	pipe = create_pipe_arr(argc - 2);

}

int	**open_file(char *file)
{
	int		file_fd;

	if (!access(file, R_OK|F_OK))
		file_access_err();
	else
		file_fd = open (file, O_RDONLY);
	if (file_fd < 0)
		file_open_err();
	else
		return (file_fd);
}

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