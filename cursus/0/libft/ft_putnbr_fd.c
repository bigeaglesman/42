/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:39:42 by ycho2             #+#    #+#             */
/*   Updated: 2023/11/04 20:26:04 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_write_num(long long ll_n, int fd);
void	ft_iteri_num(long long ll_n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	long long	ll_n;

	ll_n = (long long)n;
	if (ll_n < 0)
	{
		write (fd, "-", 1);
		ll_n *= -1;
	}
	ft_iteri_num(ll_n, fd);
}

void	ft_iteri_num(long long ll_n, int fd)
{
	if (ll_n >= 10)
		ft_iteri_num(ll_n / 10, fd);
	ft_write_num(ll_n % 10, fd);
}

void	ft_write_num(long long ll_n, int fd)
{
	char	num;

	num = (char)(ll_n + 48);
	write (fd, &num, 1);
}