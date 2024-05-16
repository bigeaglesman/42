/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:43:18 by ycho2             #+#    #+#             */
/*   Updated: 2024/05/16 23:43:36 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			print_err(void);
static long long	increase_num(char a, long long num);

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	num;

	num = 0;
	i = 0;
	sign = 1;
	if (str[i] == '-' || str [i] == '+')
	{
		if (str[i++] == '-')
			sign *= -1;
		if (!str[i])
			print_err();
	}
	while (str[i])
	{
		num = increase_num(str[i], num);
		i++;
	}
	num *= sign;
	if (num > 2147483647 || num < -2147483648)
		print_err();
	return ((int)num);
}

static long long	increase_num(char a, long long num)
{
	const long long	temp = num;

	if (a >= '0' && a <= '9')
		num = num * 10 + (a - '0');
	else
		print_err();
	if (num / 10 != temp)
		print_err();
	return (num);
}

int	ft_atoi16(const char *str)
{
	int			i;
	long long	num;

	num = 0;
	i = 2;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			num = num * 16 + (str[i] - '0');
		else if (str[i] >= 'A' && str[i] <= 'F')
			num = num * 16 + (str[i] - 'A' + 10);
		else if (str[i] >= 'a' && str[i] <= 'f')
			num = num * 16 + (str[i] - 'a' + 10);
		i++;
	}
	return ((int)num);
}

static void	print_err(void)
{
	ft_printf("Error\n");
	exit(1);
}
