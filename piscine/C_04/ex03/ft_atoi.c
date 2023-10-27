/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 19:15:33 by ycho2             #+#    #+#             */
/*   Updated: 2023/09/06 20:13:03 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_space(char ch);

int	ft_atoi(char *str)
{
	int			i;
	int			sign;
	long long	num;

	num = 0;
	i = 0;
	sign = 1;
	while (ft_is_space(*(str + i)))
		i++;
	while (*(str + i) == '-' || *(str + i) == '+')
	{
		if (*(str + i) == '-')
			sign *= -1;
		i++;
	}
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		num = num * 10 + (*(str + i) - '0');
		i++;
	}
	return ((int)(sign * num));
}

int	ft_is_space(char ch)
{
	if (ch == ' ' || ch == '\n' || ch == '\t'
		|| ch == '\v' || ch == '\f' || ch == '\r')
		return (1);
	return (0);
}
