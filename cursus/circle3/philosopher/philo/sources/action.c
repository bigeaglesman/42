/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:31:45 by ycho2             #+#    #+#             */
/*   Updated: 2024/06/20 22:31:50 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_thinking(t_arg *arg)
{
	struct timeval	tv;

	gettimeofday(&tv, 0);
	print_status(3, arg, tv);
}

void	philo_eating(t_arg *arg)
{
	struct timeval	start;
	struct timeval	mid;
	unsigned int	rest;


	if (grab_fork(arg) == -1)
		return (-1);
	gettimeofday(&start, 0);
	print_status(1, arg, start);
	arg->philo_stat[arg->philo_nth]++;
	gettimeofday(&mid, 0);
	rest = arg->time_to_eat * 1000 -1000 * (mid.tv_sec - start.tv_sec) + (mid.tv_sec - start.tv_sec) / 1000;
	usleep(rest);
}

void	philo_sleeping(t_arg *arg)
{
	struct timeval	start;
	struct timeval	mid;
	unsigned int	rest;

	gettimeofday(&start, 0);
	print_status(2, arg, start);
	gettimeofday(&mid, 0);
	rest = arg->time_to_sleep * 1000 -1000 * (mid.tv_sec - start.tv_sec) + (mid.tv_sec - start.tv_sec) / 1000;
	usleep(rest);
}

int	grab_fork(t_arg *arg)
{
	const int		left_fork = arg->philo_nth;
	int				right_fork;
	struct timeval	tv;

	if (arg->philo_nth == arg->number_of_philos)
		right_fork = 0;
	else
		right_fork = arg->philo_nth + 1;
	pthread_mutex_lock(&arg->fork[left_fork]);
	gettimeofday(&tv, 0);
	print_status(0, arg, tv);
	pthread_mutex_lock(&arg->fork[right_fork]);
	gettimeofday(&tv, 0);
	print_status(0, arg, tv);
}
