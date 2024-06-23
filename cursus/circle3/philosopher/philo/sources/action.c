/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:31:45 by ycho2             #+#    #+#             */
/*   Updated: 2024/06/23 11:53:33 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_thinking(t_shared *shared)
{
	struct timeval	tv;

	gettimeofday(&tv, 0);
	if (print_status(3, shared, tv))
		return (-1);
	return (0);
}

int	philo_eating(t_thread *thread)
{
	struct timeval	start;
	struct timeval	mid;
	unsigned int	rest;
	t_shared		*shared;

	shared = thread->shared;
	if (grab_fork(shared, thread->philo_nth) == -1)
		return (-1);
	gettimeofday(&start, 0);
	if (print_status(EATING, shared, start) == -1)
		return (-1);
	shared->philo_stat[thread->philo_nth]++;
	gettimeofday(&mid, 0);
	rest = shared->time_to_eat * 1000 -1000 * (mid.tv_sec - start.tv_sec) + (mid.tv_sec - start.tv_sec) / 1000;
	usleep(rest);
	return (0);
}

int	philo_sleeping(t_shared *shared)
{
	struct timeval	start;
	struct timeval	mid;
	unsigned int	rest;

	gettimeofday(&start, 0);
	if (print_status(SLEEPING, shared, start) == -1)
		return (-1);
	gettimeofday(&mid, 0);
	rest = shared->time_to_sleep * 1000 -1000 * (mid.tv_sec - start.tv_sec) + (mid.tv_sec - start.tv_sec) / 1000;
	usleep(rest);
	return (0);
}

int	grab_fork(t_shared *shared, int philo_nth)
{
	const int		left_fork = philo_nth;
	int				right_fork;
	struct timeval	tv;

	if (philo_nth == shared->number_of_philos)
		right_fork = 0;
	else
		right_fork = philo_nth + 1;
	pthread_mutex_lock(&shared->fork[left_fork]);
	update_status(LEFT_FORK, shared);
	gettimeofday(&tv, 0);
	if (print_status(LEFT_FORK, shared, tv) == -1)
		return (-1);
	pthread_mutex_lock(&shared->fork[right_fork]);
	update_status(RIGHT_FORK, shared);
	gettimeofday(&tv, 0);
	if (print_status(RIGHT_FORK, shared, tv) == -1)
		return (-1);
	return (0);
}
