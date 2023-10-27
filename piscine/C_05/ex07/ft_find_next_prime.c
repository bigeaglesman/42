/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:32:46 by ycho2             #+#    #+#             */
/*   Updated: 2023/09/13 18:03:23 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb);

int	ft_find_next_prime(int nb)
{
	while (!(ft_is_prime(nb)))
		nb++;
	return (nb);
}

int	ft_is_prime(int nb)
{
	long long	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i * i <= nb)
	{
		if (!(nb % i))
			return (0);
		i++;
	}
	return (1);
}
#include <stdio.h>
int main()
{
	printf("%d\n", ft_find_next_prime(-2147483648));
}
