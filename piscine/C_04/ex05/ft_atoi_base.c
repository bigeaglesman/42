/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:57:48 by ycho2             #+#    #+#             */
/*   Updated: 2023/09/06 20:56:15 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_base_valid(char *base);
int			ft_is_space(char ch);
long long	ft_base_to_int(char *str, char *base, int base_len);

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	base_len;
	int	i;

	i = 0;
	sign = 1;
	base_len = ft_base_valid(base);
	while (ft_is_space(*(str + i)))
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
	{
		return ((int)(sign * ft_base_to_int(str + i, base, base_len)));
	}
}

long long	ft_base_to_int(char *str, char *base, int base_len)
{
	int			i;
	int			base_i;
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

int	ft_base_valid(char *base)
{
	int	i;
	int	j;

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

int	ft_is_space(char ch)
{
	if (ch == ' ' || ch == '\n' || ch == '\t'
		|| ch == '\v' || ch == '\f' || ch == '\r')
		return (1);
	return (0);
}
