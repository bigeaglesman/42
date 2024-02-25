/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:03:40 by ycho2             #+#    #+#             */
/*   Updated: 2024/02/25 11:51:05 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_read_line(int fd, t_buf *buf_case)
{
	int	flag;

	flag = read(fd, buf_case->read_buf, BUFFER_SIZE);
	if (flag != -1)
	{
		buf_case->read_buf[flag] = 0;
		(buf_case->idx) = 0;
	}
	return (flag);
}

int	ft_attach_nl(char **pout, t_buf *buf_case)
{
	int		i;
	char	*concat_out;

	i = 0;
	while (buf_case->read_buf[(buf_case->idx) + i])
	{
		if (buf_case->read_buf[(buf_case->idx) + i] == '\n')
		{
			concat_out = gnl_strjoin(*pout, buf_case, ++i);
			if (concat_out == NULL)
				return (-1);
			free (*pout);
			*pout = concat_out;
			(buf_case->idx) += i;
			return (1);
		}
		i++;
	}
	concat_out = gnl_strjoin(*pout, buf_case, i);
	if (concat_out == NULL)
		return (-1);
	free (*pout);
	*pout = concat_out;
	(buf_case->idx) = -1;
	return (2);
}

char	*gnl_strjoin(char *out, t_buf *buf_case, int attach_len)
{
	int		out_len;
	char	*concat_str;

	out_len = ft_strlen(out);
	concat_str = (char *)malloc(sizeof(char) * (attach_len + out_len + 1));
	if (!concat_str)
		return (NULL);
	concat_str[0] = 0;
	ft_strlcat(concat_str, out, out_len + 1);
	ft_strlcat(concat_str, buf_case->read_buf
		+ (buf_case->idx), out_len + attach_len + 1);
	return (concat_str);
}
