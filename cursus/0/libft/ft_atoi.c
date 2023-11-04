/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:43:18 by ycho2             #+#    #+#             */
/*   Updated: 2023/11/04 21:14:23 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_space(char ch);

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	num;

	num = 0;
	i = 0;
	sign = 1;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '-' || str [i] == '+')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i] >= '0' && str [i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(sign * num));
}

int	ft_is_space(char ch)
{
	if (ch == 32 || (ch >= 9 && ch <= 13))
		return (1);
	return (0);
}
