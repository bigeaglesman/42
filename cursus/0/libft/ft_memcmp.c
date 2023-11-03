/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:25:38 by ycho2             #+#    #+#             */
/*   Updated: 2023/10/28 09:00:50 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned char	*temp_ptr1;
	unsigned char	*temp_ptr2;
	size_t			i;

	i = 0;
	temp_ptr1 = (unsigned char *)ptr1;
	temp_ptr2 = (unsigned char *)ptr2;
	while (num > i)
	{
		if (temp_ptr1[i] != temp_ptr2[i])
			return (temp_ptr1[i] - temp_ptr2[i]);
		i++;
	}
	return (0);
}
