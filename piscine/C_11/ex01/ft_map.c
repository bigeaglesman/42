/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 03:10:12 by ycho2             #+#    #+#             */
/*   Updated: 2023/09/15 06:08:38 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*arr;

	arr = (int *)malloc(sizeof(int) * length);
	if (!arr)
		return (0);
	while (i < length)
	{
		arr[i] = (*f)(tab[i]);
		i++;
	}
	return (arr);
}
