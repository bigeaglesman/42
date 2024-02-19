/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:42:44 by ycho2             #+#    #+#             */
/*   Updated: 2024/02/19 18:01:44 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	check_marker(char *str, char *marker);

char	*get_here_doc_input(char *marker)
{
	char	*line;
	char	*input;
	char	*input_tmp;

	input = (char *)malloc(sizeof(char));
	input[0] = 0;
	line = get_next_line(0);
	while (!check_marker(line, marker))
	{
		input_tmp = ft_strjoin(input, line);
		free(input);
		free(line);
		input = input_tmp;
		line = get_next_line(0);
	}
	free(line);
	return(input);
}

static int	check_marker(char *str, char *marker)
{
	int	marker_len;

	marker_len = ft_strlen(marker);
	return (ft_strncmp(str, marker, marker_len -1));
}
