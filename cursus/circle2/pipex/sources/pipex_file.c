/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:04:36 by ycho2             #+#    #+#             */
/*   Updated: 2024/02/17 14:04:49 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex_file(int argc, char **argv, char **envp, char **seperated_path, int **pipe)
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