/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:24:27 by ycho2             #+#    #+#             */
/*   Updated: 2024/02/20 22:19:42 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	check_argument(int argc, char **argv);

int main(int argc, char **argv, char **envp)
{
	int			pipefd[2];
	t_parsing	parsing;
	int			cmd_cnt;
	int			pid;
	int			tmp_fd;
	int			*statloc;

	statloc = NULL;
	check_argument(argc, argv);
	parsing.envp = envp;
	parsing_main(argc, argv, &parsing);
	cmd_cnt = 0;
	tmp_fd = -1;
	while (cmd_cnt < parsing.num_cmd)
	{
		pipe(pipefd);
		pid = fork();
		if (pid < 0)
			exit(1);
		else if (pid == 0)
		{
			close(pipefd[0]);
			dup2(pipefd[1], STDOUT_FILENO);
			close(pipefd[1]);
			if (cmd_cnt == 0)
				dup2(parsing.fd1, STDIN_FILENO);
			else
				dup2(tmp_fd, STDIN_FILENO);
			if (cmd_cnt == parsing.num_cmd-1)
				dup2(parsing.fd2, STDOUT_FILENO);
			execve(parsing.command_path[cmd_cnt],parsing.seped_command[cmd_cnt], parsing.envp);
		}
		else
		{
			close(pipefd[1]);
			if (cmd_cnt)
				close(tmp_fd);
			else
				unlink("tmp.txt");
			if (!(cmd_cnt == parsing.num_cmd-1))
				tmp_fd = dup(pipefd[0]);
			close(pipefd[0]);
		}
		cmd_cnt++;
	}
	cmd_cnt = 0;
	while (cmd_cnt < parsing.num_cmd)
	{
		wait(statloc);
		cmd_cnt++;
	}
	return (0);
}

static void	check_argument(int argc, char **argv)
{
	if (strncmp (argv[1], "here_doc", 9))
	{
		if (argc < 6)
			exit(1);
	}
	else
	{
		if (argc < 5)
			exit(1);
	}
}