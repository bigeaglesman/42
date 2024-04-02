/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parsing_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:49:38 by ycho2             #+#    #+#             */
/*   Updated: 2024/02/27 16:21:30 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	**split_path_env(char **envp);
static char	***make_seped_cmd(char **argv_cmd, int num_cmd);
static char	**make_cmd_path(char ***seped_cmd, char **path_env, int num_cmd);
static void	chk_path_cmd(char **path_env, char **cmd_path, \
			char ***sep_cmd, int cmd_cnt);

void	parsing_main(int argc, char **argv, t_parsing *parsing)
{
	parsing->seped_path_env = split_path_env(parsing->envp);
	if (!parsing->seped_path_env)
		malloc_err();
	if (!ft_strncmp(argv[1], "here_doc", 9))
		parsing_here_doc(parsing, argv, argc);
	else
	{
		parsing->is_here_doc = 0;
		parsing->fd1 = open(argv[1], O_RDONLY);
		parsing->fd2 = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	parsing->num_cmd = argc - parsing->is_here_doc - 3;
	parsing->seped_cmd = make_seped_cmd(&argv[2 + parsing->is_here_doc], \
							parsing->num_cmd);
	parsing->cmd_path = make_cmd_path(parsing->seped_cmd, \
							parsing->seped_path_env, parsing->num_cmd);
}

static char	**split_path_env(char **envp)
{
	int		i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	return (ft_split(envp[i] + 5, ':'));
}

static char	***make_seped_cmd(char **argv_cmd, int num_cmd)
{
	char	***seped_cmd;
	int		i;

	i = 0;
	seped_cmd = (char ***)malloc(sizeof(char **) * (num_cmd + 1));
	if (!seped_cmd)
		malloc_err();
	while (i < num_cmd)
	{
		seped_cmd[i] = ft_split(argv_cmd[i], ' ');
		if (!seped_cmd)
			malloc_err();
		i++;
	}
	seped_cmd[num_cmd] = 0;
	return (seped_cmd);
}

char	**make_cmd_path(char ***seped_cmd, char **path_env, int num_cmd)
{
	char	**cmd_path_arr;
	int		cmd_cnt;

	cmd_cnt = 0;
	cmd_path_arr = (char **)malloc (sizeof(char *) * (num_cmd + 1));
	if (!cmd_path_arr)
		malloc_err();
	while (cmd_cnt < num_cmd)
	{
		chk_path_cmd(path_env, cmd_path_arr, seped_cmd, cmd_cnt);
		cmd_cnt++;
	}
	cmd_path_arr[num_cmd] = 0;
	return (cmd_path_arr);
}

static void	chk_path_cmd(char **path_env, char **cmd_path, \
			char ***sep_cmd, int cmd_cnt)
{
	char	*join_path_cmd;
	int		path_cnt;
	char	*slash_cmd;

	path_cnt = 0;
	slash_cmd = ft_strjoin("/", sep_cmd[cmd_cnt][0]);
	while (path_env[path_cnt])
	{
		join_path_cmd = ft_strjoin(path_env[path_cnt], slash_cmd);
		if (!access(join_path_cmd, X_OK))
		{
			cmd_path[cmd_cnt] = join_path_cmd;
			break ;
		}
		free(join_path_cmd);
		path_cnt++;
	}
	free(slash_cmd);
}
