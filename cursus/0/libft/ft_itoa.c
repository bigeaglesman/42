/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 03:01:19 by ycho2             #+#    #+#             */
/*   Updated: 2023/10/29 15:50:04 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_numlen(long long num);

char	*ft_itoa(int n)
{
	size_t		len;
	char		*str;
	long long	ll_n;
	size_t		i;

	i = 0;
	ll_n = (long long)n;
	len = ft_numlen(ll_n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[len] = 0;
	if (ll_n < 0)
	{
		ll_n *= -1;
		str[0] = '-';
	}
	else if (ll_n == 0)
		str[0] = '0';
	while (ll_n)
	{
		str[--len] = ll_n % 10 + 48;
		ll_n /= 10;
	}
	return (str);
}

size_t	ft_numlen(long long num)
{
	size_t	len;

	len = 0;
	if (num < 0)
		len++;
	else if (num == 0)
		return (1);
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}
