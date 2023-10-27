/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:00:50 by ycho2             #+#    #+#             */
/*   Updated: 2023/09/12 22:23:25 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_base_valid(char *base);
long long	ft_atoi_base(char *str, char *base);
long long	ft_base_to_int(char *str, char *base, long long base_len);

long long	ft_base_valid(char *base)
{
	long long	i;
	long long	j;

	i = 0;
	while (*(base + i))
	{
		j = 0;
		if (*(base + i) == '+' || *(base + i) == '-' || *(base + i) == 32
			|| (*(base + i) >= 9 && *(base + i) <= 13))
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

long long	ft_atoi_base(char *str, char *base)
{
	long long	sign;
	long long	base_len;
	long long	i;

	i = 0;
	sign = 1;
	base_len = ft_base_valid(base);
	while (*(str + i) == 32 || (*(str + i) >= 9 && *(str + i) <= 13))
		i++;
	while (*(str + i) == '-' || *(str + i) == '+')
	{
		if (*(str + i) == '-')
			sign *= -1;
		i++;
	}
	if (base_len == 0)
		return (0);
	else
		return (sign * ft_base_to_int(str + i, base, base_len));
}

long long	ft_base_to_int(char *str, char *base, long long base_len)
{
	int			i;
	long long	base_i;
	long long	num;

	num = 0;
	i = 0;
	while (*(str + i))
	{
		base_i = 0;
		while (*(base + base_i))
		{
			if (*(base + base_i) == *(str + i))
				break ;
			if (base_len == base_i + 1)
				return (num);
			base_i++;
		}
		num = num * base_len + base_i;
		i++;
	}
	return (num);
}
