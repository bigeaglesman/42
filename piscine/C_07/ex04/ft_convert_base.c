/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:05:41 by ycho2             #+#    #+#             */
/*   Updated: 2023/09/14 17:27:58 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long long	ft_base_valid(char *base);
long long	ft_base_to_int(char *str, char *base, int base_len);
long long	ft_atoi_base(char *str, char *base);
char		*ft_itoa_base(long long nbr_i, char *base);
long long	ft_get_arr_size(long long nbr_i, long long base_len);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	nbr_i;
	char		*arr;

	if (!ft_base_valid(base_from) || !ft_base_valid(base_to))
		return (0);
	nbr_i = ft_atoi_base(nbr, base_from);
	arr = ft_itoa_base(nbr_i, base_to);
	return (arr);
}

char	*ft_itoa_base(long long nbr_i, char *base)
{
	char		*arr;
	long long	i;
	long long	arr_size;
	long long	base_len;

	base_len = ft_base_valid(base);
	arr_size = ft_get_arr_size(nbr_i, base_len);
	arr = (char *)malloc(sizeof(char) * (arr_size + 1));
	i = arr_size - 1;
	arr[arr_size] = 0;
	if (nbr_i < 0)
	{
		*arr = '-';
		nbr_i *= -1;
	}
	if (nbr_i == 0)
		*arr = base[0];
	while (nbr_i > 0)
	{
		*(arr + i) = base[nbr_i % base_len];
		nbr_i /= base_len;
		i--;
	}
	return (arr);
}

long long	ft_get_arr_size(long long nbr_i, long long base_len)
{
	long long	arr_size;

	arr_size = 0;
	if (nbr_i == 0)
		return (1);
	if (nbr_i < 0)
	{
		nbr_i *= -1;
		arr_size++;
	}
	while (nbr_i > 0)
	{
		nbr_i /= base_len;
		arr_size++;
	}
	return (arr_size);
}
