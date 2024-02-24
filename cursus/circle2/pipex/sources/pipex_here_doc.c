/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:42:44 by ycho2             #+#    #+#             */
/*   Updated: 2024/02/24 16:46:33 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_here_doc_input(char *marker);

void	parsing_here_doc(t_parsing *parsing, char **argv, int argc)
{
	char	*here_doc_str;

	parsing->is_here_doc = 1;
	parsing->delimiter = argv[2];
	parsing->fd1 = open("tmp.txt", O_RDWR | O_CREAT, 0600);
	if (parsing->fd1 == -1)
		file_open_err();
	here_doc_str = get_here_doc_input(parsing->delimiter);
	write(parsing->fd1, here_doc_str, ft_strlen(here_doc_str));
	close(parsing->fd1);
	parsing->fd1 = open("tmp.txt", O_RDONLY);
	parsing->fd2 = open(argv[argc - 1], O_RDWR | O_APPEND | O_CREAT, 0600);
}

static char	*get_here_doc_input(char *marker)
{
	char	*line;
	char	*input;
	char	*input_tmp;
	char	*trans_marker;

	trans_marker = ft_strjoin(marker, "\n");
	input = (char *)malloc(sizeof(char));
	line = get_next_line(0);
	if (!line || !input || !trans_marker)
		malloc_err();
	input[0] = 0;
	while (ft_strncmp(line, trans_marker, ft_strlen(trans_marker) + 1))
	{
		input_tmp = ft_strjoin(input, line);
		free(input);
		free(line);
		input = input_tmp;
		line = get_next_line(0);
		if (!line)
			malloc_err();
	}
	free(trans_marker);
	free(line);
	return (input);
}
