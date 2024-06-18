/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:58:50 by youngho           #+#    #+#             */
/*   Updated: 2024/06/18 20:27:46 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parsing_arg(t_arg *arg, int num_arg, char **argv)
{
	if (num_arg == 4 || num_arg == 5)
	{
		arg->philo_num = ft_atoi(argv[1]);
		arg->time_to_die = ft_atoi(argv[2]);
		arg->time_to_eat = ft_atoi(argv[3]);
		arg->time_to_sleep = ft_atoi(argv[4]);
		if (num_arg == 5)
			arg->min_eat_times = ft_atoi(argv[5]);
		else
			arg->min_eat_times = -1;
	}
	else
		printf("arg num err\n");
}
