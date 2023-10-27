/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:13:37 by ycho2             #+#    #+#             */
/*   Updated: 2023/10/20 15:58:52 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subcpy;
	size_t	i;

	subcpy = (char *)malloc(len * sizeof(char));
	if (!subcpy)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		subcpy[i] = s[start + i];
		i++;
	}
	subcpy[i] = 0;
	return (subcpy);
}
