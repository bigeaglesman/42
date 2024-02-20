/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:42:44 by ycho2             #+#    #+#             */
/*   Updated: 2024/02/20 21:19:16 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_here_doc_input(char *marker)
{
	char	*line;
	char	*input;
	char	*input_tmp;
	char	*trans_marker;

	trans_marker = ft_strjoin(marker, "\n");
	input = (char *)malloc(sizeof(char));
	input[0] = 0;
	line = get_next_line(0);
	while (ft_strncmp(line, trans_marker, ft_strlen(trans_marker) + 1))
	{
		// ft_printf("input string: %s, marker: %s\n", line, trans_marker);
		input_tmp = ft_strjoin(input, line);
		free(input);
		free(line);
		input = input_tmp;
		line = get_next_line(0);
	}
	free(trans_marker);
	free(line);
	return(input);
}
