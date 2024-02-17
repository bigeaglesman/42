/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:49:38 by ycho2             #+#    #+#             */
/*   Updated: 2024/02/17 22:11:49 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parsing_main(int argc, char **argv, t_parsing *parsing)
{
	int	cmd_cnt;

	parsing->seped_path_envp = split_path_envp(parsing->envp);
	if (!ft_strncmp(argv[2], "here_doc", 9))
	{
		parsing->is_here_doc = 1;
		parsing->delimiter = argv[2];
	}
	else
		parsing->is_here_doc = 0;
	parsing->seped_command = make_seped_command(argv, );
	parsing->command_path = make_command_path_arr(argv, parsing->is_here_doc);
	parsing->pipe_fd = make_pipefd(parsing->is_here_doc, argc);

}

char	**split_path(char **envp)
{
	char	**path;
	int		i;

	i = 0;
	while(!ft_strncmp(envp[i], "PATH", 4))
		i++;
	return (ft_split(envp[i] + 5, ':'));
}

char	*check_command(char **path, char *command)
{
	int		i;
	char	*tmp;
	char	*slash_command;

	while (path[i])
	{
		slash_command = ft_strjoin("/", command);
		tmp = ft_strjoin(path[i], slash_command);
		if (!access(tmp, X_OK))
		{
			free(slash_command);
			ft_printf("ACCESS SUCCESS: %s\n", tmp);
			return(tmp);
		}
		free(slash_command);
		free(tmp);
	}
	return (NULL);
}

char	*read_input(int input_fd)
{
	char	*input_tmp;
	char	*input;
	char	buf[BUFFER_SIZE];
	int		nread;

	input = (char *)malloc(sizeof(char));
	input[0] = 0;
	nread = read(input_fd, buf, ft_strlen(buf));
	while (nread > 0)
	{
		input_tmp = ft_strjoin(input, buf);
		free(input);
		input = input_tmp;
	}
	return (input);
}

char	**concat_command_input(char *command, char *input)
{
	char	**args;
	char	**sep_command;
	int		command_len;
	int		i;

	sep_command = ft_split(command, ' ');
	command_len = 0;
	while (sep_command[command_len])
		command_len++;
	args = (char **)malloc(sizeof(char *) * (command_len + 2));
	i = 0;
	while (i < command_len)
	{
		args[i] = sep_command[i];
		i++;
	}
	split_free(sep_command);
	args[i++] = input;
	args[i] = NULL;
	return (args);
}
