/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:57:33 by ycho2             #+#    #+#             */
/*   Updated: 2023/11/04 21:14:25 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t size)
{
	unsigned char	*temp_ptr;

	temp_ptr = (unsigned char *)ptr;
	ft_memset(temp_ptr, 0, size);
}
