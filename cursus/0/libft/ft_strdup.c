/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:46:01 by ycho2             #+#    #+#             */
/*   Updated: 2023/10/28 04:15:51 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s1_cpy;
	int		i;

	i = 0;
	len = ft_strlen((char *)s1);
	s1_cpy = (char *)malloc((len + 1) * sizeof(char));
	if (!s1_cpy)
		return (NULL);
	while (s1[i])
	{
		s1_cpy[i] = s1[i];
		i++;
	}
	s1_cpy[i] = 0;
	return (s1_cpy);
}
