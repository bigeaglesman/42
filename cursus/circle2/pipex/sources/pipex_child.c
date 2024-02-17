/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:31:06 by ycho2             #+#    #+#             */
/*   Updated: 2024/02/17 14:01:08 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child_execve(int num_child, char *command, char **envp, char **path_env, int **pipe)
{
	char	*command_path;
	char	**args;
	char	*input;

	dup2(pipe[num_child + 1][1], 1);
	input = read_input(pipe[num_child][0]);
	args = concat_command_input(command, input);
	command_path = check_command(path_env, args[0]);
	return(execve(command_path, args, envp));
}
