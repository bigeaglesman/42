/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 21:06:11 by ycho2             #+#    #+#             */
/*   Updated: 2023/09/11 14:35:21 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		len;
	char	*arr;
	int		i;

	i = 0;
	len = 0;
	while (*(src + len))
		len++;
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (0);
	while (*(src + i))
	{
		*(arr + i) = *(src + i);
		i++;
	}
	*(arr + i) = 0;
	return (arr);
}
