/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 22:10:35 by ycho2             #+#    #+#             */
/*   Updated: 2023/09/11 16:30:42 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	range;
	int	*arr;
	int	i;

	i = 0;
	if (max <= min)
		return (0);
	range = max - min;
	arr = (int *)malloc(sizeof(int) * range);
	while (min + i < max)
	{
		*(arr + i) = min + i;
		i++;
	}
	return (arr);
}
