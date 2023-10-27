/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:56:57 by ycho2             #+#    #+#             */
/*   Updated: 2023/10/20 15:46:03 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	int	*arr;
	int	i;

	i = 0;
	arr = (int *)malloc(count * size);
	if (!arr)
		return (NULL);
	while (size > i)
	{
		arr[i] = 0;
		i++;
	}
	return ((void *)arr);
}
