/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:25:50 by seongjko          #+#    #+#             */
/*   Updated: 2024/02/20 19:48:48 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	gnl_strchr(const char *s, int c)
{
	int	cnt;

	cnt = 0;
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (-1);
		cnt++;
		s++;
	}
	return (cnt);
}

char	*gnl_strndup(char *str, int len)
{
	int			i;
	char		*p;

	i = 0;
	p = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
		p[i++] = *str++;
	p[i] = '\0';
	return (p);
}

char	*gnl_strjoin(char *dest, char *append)
{
	char	*p;
	int		cnt1;
	int		cnt2;
	int		i;

	i = 0;
	cnt1 = gnl_strlen(dest);
	cnt2 = gnl_strlen(append);
	p = (char *)malloc(cnt1 + cnt2 + 1);
	while (*dest)
		p[i++] = *dest++;
	while (*append)
		p[i++] = *append++;
	p[i] = '\0';
	return (p);
}

size_t	gnl_strlen(const char *str)
{
	size_t	cnt;

	cnt = 0;
	while (*str)
	{
		str++;
		cnt++;
	}
	return (cnt);
}
