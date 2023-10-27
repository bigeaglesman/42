/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:03:29 by ycho2             #+#    #+#             */
/*   Updated: 2023/08/28 14:51:43 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	num_sw(int num);

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{	
			num_sw(a);
			write (1, " ", 1);
			num_sw(b);
			if (a != 98 || b != 99)
			{
				write(1, ", ", 2);
			}
			b++;
		}
		a++;
	}
}

void	num_sw(int num)
{	
	char	n_ten;
	char	n_one;
	char	n[2];

	n_ten = num / 10 + '0';
	n_one = num % 10 + '0';
	n[0] = n_ten;
	n[1] = n_one;
	write(1, n, 2);
}
