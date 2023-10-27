/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:02:23 by ycho2             #+#    #+#             */
/*   Updated: 2023/09/13 22:12:44 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
char	*ft_strcat(char *dest, char *src);
int		ft_get_concat_len(char **strs, char *sep, int size);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	int		i;
	char	*concat_str;

	len = 0;
	i = 0;
	if (size == 0)
	{
		concat_str = (char *)malloc(sizeof(char));
		*concat_str = 0;
		return (concat_str);
	}
	len = ft_get_concat_len(strs, sep, size);
	concat_str = (char *)malloc(sizeof(char) * len);
	concat_str[0] = 0;
	while (i < size)
	{
		ft_strcat(concat_str, strs[i]);
		if (i + 1 < size)
			ft_strcat(concat_str, sep);
		i++;
	}
	concat_str[len - 1] = 0;
	return (concat_str);
}

char	*ft_strcat(char *dest, char *src)
{
	int	dest_len;
	int	i;

	i = 0;
	dest_len = ft_strlen(dest);
	while (src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = 0;
	return (dest);
}

int	ft_get_concat_len(char **strs, char *sep, int size)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (i < size)
	{
		len = len + ft_strlen(strs[i]);
		i++;
	}
	len = len + ft_strlen(sep) * (size - 1) + 1;
	return (len);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
