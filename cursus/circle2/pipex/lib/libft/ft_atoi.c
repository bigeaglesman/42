/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:43:18 by ycho2             #+#    #+#             */
/*   Updated: 2024/02/06 15:21:26 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_is_space(char ch);

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

static int	ft_is_space(char ch)
{
	if (ch == 32 || (ch >= 9 && ch <= 13))
		return (1);
	return (0);
}
