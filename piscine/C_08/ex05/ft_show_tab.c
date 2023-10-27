/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:47:58 by ycho2             #+#    #+#             */
/*   Updated: 2023/09/15 02:54:02 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_wrnum(int get_int);
void	ft_putnbr(int nb);

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		write (1, par[i].str, par[i].size);
		write (1, "\n", 1);
		ft_putnbr (par[i].size);
		write (1, "\n", 1);
		write (1, par[i].copy, par[i].size);
		write (1, "\n", 1);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	int		nb_divqu;
	int		nb_rem;

	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
	}
	else if (nb < 0)
	{
		write (1, "-", 1);
		ft_putnbr (-nb);
	}
	else if (nb >= 10)
	{
		nb_divqu = nb / 10;
		ft_putnbr(nb_divqu);
		nb_rem = nb % 10;
		ft_wrnum(nb_rem);
	}
	else
	{
		ft_wrnum(nb);
	}
}

void	ft_wrnum(int get_int)
{
	char	out_char;

	out_char = get_int + '0';
	write(1, &out_char, 1);
}
