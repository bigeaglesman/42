/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:24:27 by ycho2             #+#    #+#             */
/*   Updated: 2024/02/17 22:08:33 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	int		**pipe;
	char	**seperated_path;
	t_parsing	parsing;

	if (argc < 4)
		argument_err();
	parsing.envp = envp;
	parsing_main(argc, argv, &parsing);
	seperated_path = split_path(envp);
	if (argv[1] == "here_doc")
	{
		pipe = create_pipe_arr(argc - 3);
		return (pipex_here_doc(argc, argv, envp, seperated_path, pipe));
	}
	else
	{
		pipe = create_pipe_arr(argc - 2);
		return (pipex_file(argc, argv, envp, seperated_path, pipe));
	}
}
