/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:45:06 by ycho2             #+#    #+#             */
/*   Updated: 2023/10/29 22:07:15 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *str, int val)
{
	size_t			i;
	unsigned char	temp_val;
	unsigned char	*temp_str;

	i = 0;
	temp_str = (unsigned char *)str;
	temp_val = (unsigned char)val;
	while (temp_str[i])
	{
		if (temp_str[i] == temp_val)
			return ((char *)(temp_str + i));
		i++;
	}
	if (temp_val == 0)
		return ((char *)(str + i));
	return (0);
}
