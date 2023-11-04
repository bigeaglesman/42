/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:35:34 by ycho2             #+#    #+#             */
/*   Updated: 2023/11/04 21:54:42 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_start_move(unsigned char *src, unsigned char *dst, size_t len);
void	ft_end_move(unsigned char *src, unsigned char *dst, size_t len);

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp_src;
	unsigned char	*tmp_dst;

	if (dst == src)
		return (dst);
	tmp_src = (unsigned char *)src;
	tmp_dst = (unsigned char *)dst;
	if (tmp_src < tmp_dst)
		ft_end_move(tmp_src, tmp_dst, len);
	else
		ft_start_move(tmp_src, tmp_dst, len);
	return (dst);
}

void	ft_end_move(unsigned char *src, unsigned char *dst, size_t len)
{
	size_t			i;

	i = 0;
	while (i < len)
	{
		dst[len - i - 1] = src[len - i - 1];
		i++;
	}
}

void	ft_start_move(unsigned char *src, unsigned char *dst, size_t len)
{
	size_t			i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}