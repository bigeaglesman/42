/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 19:53:46 by ycho2             #+#    #+#             */
/*   Updated: 2023/09/02 21:44:31 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_pr_dec_to_hex(char ch);
void	ft_putchar(char ch);

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		if (!(*(str + i) >= 32 && *(str + i) <= 126))
			ft_pr_dec_to_hex(*(str + i));
		else
			ft_putchar(*(str + i));
	i++;
	}
}

void	ft_pr_dec_to_hex(char ch)
{	
	char	*hexa;

	ft_putchar('\\');
	hexa = "0123456789abcdef";
	ft_putchar(hexa[(unsigned char) ch / 16]);
	ft_putchar(hexa[(unsigned char) ch % 16]);
}

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}
