/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:49:38 by ycho2             #+#    #+#             */
/*   Updated: 2024/02/19 21:00:09 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parsing_main(int argc, char **argv, t_parsing *parsing)
{
	parsing->seped_path_envp = split_path_envp(parsing->envp);
	if (!ft_strncmp(argv[2], "here_doc", 9))
	{
		parsing->is_here_doc = 1;
		parsing->delimiter = ft_strjoin(argv[2], "\n");
		parsing->fd2 = open(argv[argc - 1], O_RDWR | O_APPEND | O_CREAT, 0644);
	}
	else
	{
		parsing->is_here_doc = 0;
		parsing->fd1 = open(argv[1], O_RDONLY);
		parsing->fd2 = open(argv[argc-1], O_RDWR | O_TRUNC);
	}
	parsing->num_cmd = argc - parsing->is_here_doc - 3;
	parsing->seped_command = make_seped_cmd(&argv[2 + parsing->is_here_doc], parsing->num_cmd);
	parsing->command_path = make_cmd_path(parsing->seped_command, parsing->seped_path_envp, parsing->num_cmd);
}

char	**split_path_envp(char **envp)
{
	int		i;

	i = 0;
	while(ft_strncmp(envp[i], "PATH=", 5))
		i++;
	return (ft_split(envp[i] + 5, ':'));
}

char	***make_seped_cmd(char **argv_command, int num_cmd)
{
	char	***seped_command;
	int		i;

	i = 0;
	seped_command = (char ***)malloc(sizeof(char **) * (num_cmd + 1));
	while (i < num_cmd)
	{
		seped_command[i] = ft_split(argv_command[i], ' ');
		i++;
	}
	seped_command[num_cmd] = 0;
	return (seped_command);
}

char	**make_cmd_path(char ***seped_command, char **path_envp, int num_cmd)
{
	char	**command_path_arr;
	int		command_cnt;
	int		path_cnt;
	char	*slash_command;
	char	*concated_path_command;

	command_cnt = 0;
	command_path_arr = (char **)malloc( sizeof(char *) * (num_cmd + 1));
	while (command_cnt < num_cmd)
	{
		path_cnt = 0;
		slash_command = ft_strjoin("/", seped_command[command_cnt][0]);
		while(path_envp[path_cnt])
		{
			concated_path_command = ft_strjoin(path_envp[path_cnt], slash_command);
			if (!access(concated_path_command, X_OK))
			{
				command_path_arr[command_cnt] = concated_path_command;
				break;
			}
			free(concated_path_command);
			path_cnt++;
		}
		free(slash_command);
		command_cnt++;
	}
	command_path_arr[num_cmd] = 0;
	return (command_path_arr);
}


