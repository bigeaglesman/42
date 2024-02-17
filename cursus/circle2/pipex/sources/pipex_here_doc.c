/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:42:44 by ycho2             #+#    #+#             */
/*   Updated: 2024/02/17 14:23:03 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	check_marker(char *str, char *marker);

int	pipex_here_doc(int argc, char **argv, char **envp, char **seperated_path, int **pipe)
{
	char	*input;
	int		i;
	int		pid;

	i = 0;
	input = get_here_doc_input(argv[3]);
	write(pipe[0][1], input, ft_strlen(input + 1));
	while (i < argc - 4)
	{
		pid = fork();
		if (pid < 0)
			fork_err();
		else if (pid == 0)
		{
			close_unusing_pipe(i, argc - 3);
			return (child_execve(i, argv[i + 3], envp, seperated_path, pipe));
		}
		else
			wait(NULL);
		i++;
	}
	return (write_output(argv[argc - 1], pipe[i][0]));
}

char	*get_here_doc_input(char *marker)
{
	char	*line;
	char	*input;
	char	*input_tmp;

	input = (char *)malloc(sizeof(char));
	input[0] = 0;
	line = get_next_line(0);
	while (!check_marker(line, marker))
	{
		input_tmp = ft_strjoin(input, line);
		free(input);
		free(line);
		input = input_tmp;
		line = get_next_line(0);
	}
	free(line);
	return(input);
}

static int	check_marker(char *str, char *marker)
{
	int	marker_len;

	marker_len = ft_strlen(marker);
	return (ft_strncmp(str, marker, marker_len -1));
}

int	write_output(char *file2, int readfd)
{
	char	*buf[BUFFER_SIZE];
	int		fd2;
	int		nread;

	fd2 = open(file2, O_WRONLY | O_CREAT | O_APPEND, 0644);
	nread = read(readfd, buf, sizeof(buf));
	while (nread > 0)
	{
		write(fd2, buf, nread);
		nread = read(readfd, buf, sizeof(buf));
	}
	if (nread < 0)
		return (-1);
	else
		return (0);
}
