/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:25:53 by ycho2             #+#    #+#             */
/*   Updated: 2023/09/03 13:29:11 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_printaddr(long long addr_l);
void	ft_printtext_16(unsigned char *addr_ch, int rowsize);
void	ft_printtext_char(unsigned char *addr_ch, int rowsize);

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*addr_ch;
	int				rowsize;
	long long		addr_l;

	i = 0;
	while (i * 16 < size)
	{
		addr_ch = (unsigned char *)(addr + i * 16);
		addr_l = (long long)addr_ch;
		if ((i + 1) * 16 <= size)
			rowsize = 16;
		else
			rowsize = size % 16;
		ft_printaddr(addr_l);
		write(1, ":", 1);
		ft_printtext_16(addr_ch, rowsize);
		ft_printtext_char(addr_ch, rowsize);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

void	ft_printaddr(long long addr_l)
{
	int			i;
	char		*hexa;
	long long	addr_16[16];

	i = 15;
	while (addr_l > 0)
	{
		addr_16[i] = addr_l % 16;
		addr_l /= 16;
		i--;
	}
	while (i >= 0)
	{
		addr_16[i + 1] = 0;
		i--;
	}
	hexa = "0123456789abcdef";
	i++;
	while (i < 16)
	{
		write (1, hexa + *(addr_16 + i) % 16, 1);
		i++;
	}
}

void	ft_printtext_16(unsigned char *addr_ch, int rowsize)
{
	int				i;
	char			*hexa;	

	hexa = "0123456789abcdef";
	i = 0;
	while (i < rowsize)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		write (1, hexa + *(addr_ch + i) / 16, 1);
		write (1, hexa + *(addr_ch + i) % 16, 1);
		i++;
	}
	while (rowsize < 16)
	{
		if (rowsize % 2)
			write(1, "  ", 2);
		else
			write(1, "   ", 3);
		rowsize++;
	}
}

void	ft_printtext_char(unsigned char *addr_ch, int rowsize)
{
	int	i;

	i = 0;
	write(1, " ", 1);
	while (i < rowsize)
	{
		if (*(addr_ch + i) >= 32 && *(addr_ch + i) <= 126)
			write(1, addr_ch + i, 1);
		else
			write(1, ".", 1);
		i++;
	}
}

int main(void)
{
ft_print_memory("Bonjour les aminches\t\n\tc\a est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n \0",92);
}
