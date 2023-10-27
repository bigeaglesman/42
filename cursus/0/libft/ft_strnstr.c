/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:44:31 by ycho2             #+#    #+#             */
/*   Updated: 2023/10/20 15:11:15 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(char *str);

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	find_size;
	size_t	i;
	size_t	find_i;

	i = 0;
	find_size = ft_strlen(find);
	if (find[i] == 0)
		return (str);
	while (i <= len - find_size)
	{
		find_i = 0;
		if (str[i] == find[find_i])
		{
			while (str[i + find_i] == find[find_i])
			{
				if (find_i + 1 == find_size)
					return (str + i);
				find_i++;
			}
		}
		i++;
	}
	return (0);
}
