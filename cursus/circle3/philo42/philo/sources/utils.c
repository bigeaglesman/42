/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngho <youngho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:53:25 by ycho2             #+#    #+#             */
/*   Updated: 2024/07/13 14:48:52 by youngho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while(str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num = num * 10 + (str[i] - '0');
			i++;
		}
		else
			return (-1);
	}
	if (num == 0)
		return (-1);
	return (num);
}

long long	get_current_time(void)
{
	struct timeval	tv;
	long long		current;

	gettimeofday(&tv, 0);
	current = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (current);
}