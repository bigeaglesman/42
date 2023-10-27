/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:38:20 by ycho2             #+#    #+#             */
/*   Updated: 2023/09/04 16:57:10 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str);

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	find_i;
	int	find_len;

	find_len = ft_strlen(to_find);
	i = 0;
	if (!(*to_find))
		return (str);
	while (*(str + i))
	{
		find_i = 0;
		if (*(str + i) == *to_find)
		{	
			while (*(str + i + find_i) == *(to_find + find_i))
			{
				if (find_i + 1 == find_len)
					return (str + i);
				find_i++;
			}
		}
		i++;
	}
	return ((char *) NULL);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}
