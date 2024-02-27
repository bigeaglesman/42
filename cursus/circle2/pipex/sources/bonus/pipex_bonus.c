/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:24:27 by ycho2             #+#    #+#             */
/*   Updated: 2024/02/27 12:50:18 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	check_argument(int argc, char **argv);
static void	child_proc(t_parsing parsing, int *pfd, int cmd_cnt);
static void	parent_proc(t_parsing *parsing, int *pfd, int cmd_cnt);
static void	c_p_proc(t_parsing *parsing, int *pipefd, int cmd_cnt);

int	main(int argc, char **argv, char *envp[])
{
	int			pipefd[2];
	t_parsing	parsing;
	int			cmd_cnt;

	check_argument(argc, argv);
	parsing.envp = envp;
	parsing.tmp_fd = -1;
	parsing_main(argc, argv, &parsing);
	cmd_cnt = 0;
	while (cmd_cnt < parsing.num_cmd)
	{
		c_p_proc(&parsing, pipefd, cmd_cnt);
		cmd_cnt++;
	}
	cmd_cnt = 0;
	while (cmd_cnt < parsing.num_cmd)
	{
		wait(NULL);
		cmd_cnt++;
	}
	exit (0);
}

static void	check_argument(int argc, char **argv)
{
	if (argc < 5)
	{
		perror("argument input error\n");
		exit(1);
	}
	else if (!strncmp (argv[1], "here_doc", 9))
	{
		if (argc < 6)
		{
			perror("here_doc argument error\n");
			exit(1);
		}
	}
}

static void	child_proc(t_parsing parsing, int *pfd, int cmd_cnt)
{
	close(pfd[0]);
	dup2(pfd[1], STDOUT_FILENO);
	close(pfd[1]);
	if (cmd_cnt == 0)
	{
		if (parsing.fd1 == -1)
			file_open_err();
		else
			dup2(parsing.fd1, STDIN_FILENO);
	}
	else
		dup2(parsing.tmp_fd, STDIN_FILENO);
	if (cmd_cnt == parsing.num_cmd - 1)
	{
		if (parsing.fd2 == -1)
			file_open_err();
		else
			dup2(parsing.fd2, STDOUT_FILENO);
	}
	if (execve (parsing.cmd_path[cmd_cnt], parsing.seped_cmd[cmd_cnt] \
		, parsing.envp) == -1)
		child_process_err();
}

static void	parent_proc(t_parsing *parsing, int *pfd, int cmd_cnt)
{
	close(pfd[1]);
	if (cmd_cnt)
		close(parsing->tmp_fd);
	else
		unlink("tmp.txt");
	if (!(cmd_cnt == parsing->num_cmd - 1))
		parsing->tmp_fd = dup(pfd[0]);
	close(pfd[0]);
}

static void	c_p_proc(t_parsing *parsing, int *pipefd, int cmd_cnt)
{
	int	pid;

	pipe(pipefd);
	pid = fork();
	if (pid < 0)
		exit(1);
	else if (pid == 0)
		child_proc(*parsing, pipefd, cmd_cnt);
	else
		parent_proc(parsing, pipefd, cmd_cnt);
}
