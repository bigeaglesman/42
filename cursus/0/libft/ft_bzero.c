/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:57:33 by ycho2             #+#    #+#             */
/*   Updated: 2023/10/13 13:47:28 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *ptr, size_t size)
{
	size_t			i;
	unsigned char	*temp_ptr;

	temp_ptr = (unsigned char *)ptr;
	i = 0;
	while (size > i)
		temp_ptr[i++] = 0;
}
