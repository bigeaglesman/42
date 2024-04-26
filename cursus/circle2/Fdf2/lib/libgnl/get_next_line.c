/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:45:55 by ycho2             #+#    #+#             */
/*   Updated: 2024/04/22 12:57:06 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_buf	buf_arr[OPEN_MAX];
	char			*out;
	int				flag;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	out = (char *)malloc(sizeof(char));
	if (out == NULL)
		return (NULL);
	out[0] = 0;
	while (1)
	{
		flag = ft_read_attach(fd, &out, &buf_arr[fd]);
		if (flag == 1 || (flag == 0 && *out != 0))
			return (out);
		else if (flag == -1 || flag == 0)
		{
			free (out);
			return (NULL);
		}
	}
}

int	ft_read_attach(int fd, char **pout, t_buf *buf_case)
{
	int	flag;
	int	read_len;

	read_len = 1;
	if ((buf_case -> used) == 0)
	{
		buf_case -> used = 1;
		buf_case -> idx = -1;
	}
	if ((buf_case -> idx) == -1)
		read_len = ft_read_line(fd, buf_case);
	if (read_len == -1 || read_len == 0)
		return (read_len);
	else
	{
		flag = ft_attach_nl(pout, buf_case);
		return (flag);
	}
}
