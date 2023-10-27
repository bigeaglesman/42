/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:42:24 by ycho2             #+#    #+#             */
/*   Updated: 2023/09/06 20:35:22 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void			ft_print_base(long long nbr, char *base, long long base_len);
long long		ft_base_valid(char *base);

void	ft_putnbr_base(int nbr, char *base)
{
	int			sign;
	int			base_len;
	long long	long_nbr;

	long_nbr = (long long)nbr;
	base_len = ft_base_valid(base);
	sign = 1;
	if (base_len != 0)
	{
		if (nbr < 0)
		{
			long_nbr *= -1;
			write (1, "-", 1);
		}
		ft_print_base(long_nbr, base, base_len);
	}
}

void	ft_print_base(long long nbr, char *base, long long base_len)
{
	if (nbr >= base_len)
	{
		ft_print_base(nbr / base_len, base, base_len);
		write (1, base + (nbr % base_len), 1);
	}
	else
	{
		write (1, base + (nbr % base_len), 1);
	}
}

long long	ft_base_valid(char *base)
{
	long long	i;
	long long	j;

	i = 0;
	while (*(base + i))
	{
		j = 0;
		if (*(base + i) == '+' || *(base + i) == '-')
			return (0);
		while (j < i)
		{
			if (*(base + i) == *(base + j))
				return (0);
			j++;
		}
		i++;
	}
	if (i == 1)
		return (0);
	return (i);
}
