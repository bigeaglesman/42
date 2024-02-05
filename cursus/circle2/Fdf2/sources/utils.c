/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:15:09 by ycho2             #+#    #+#             */
/*   Updated: 2024/02/05 12:02:22 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*temp_s1;
	const unsigned char	*temp_s2;

	temp_s1 = (const unsigned char *)s1;
	temp_s2 = (const unsigned char *)s2;
	i = 0;
	while ((temp_s1[i] || temp_s2[i]) && i < n)
	{
		if (temp_s1[i] != temp_s2[i])
			return (temp_s1[i] - temp_s2[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void		*arr;
	size_t		mul_size_cnt;

	mul_size_cnt = count * size;
	if (count != 0 && mul_size_cnt / count != size)
		return (NULL);
	arr = malloc(count * size);
	if (!arr)
		return (NULL);
	ft_bzero(arr, count * size);
	return (arr);
}

void	ft_bzero(void *ptr, size_t size)
{
	ft_memset(ptr, 0, size);
}

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t			i;
	unsigned char	*temp_ptr;

	temp_ptr = (unsigned char *)ptr;
	i = 0;
	while (i < num)
		temp_ptr[i++] = (unsigned char)value;
	return (ptr);
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
