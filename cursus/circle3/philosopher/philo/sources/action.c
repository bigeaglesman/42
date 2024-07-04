/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngho <youngho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:31:45 by ycho2             #+#    #+#             */
/*   Updated: 2024/07/04 12:36:29 by youngho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_thinking(t_thread *thread)
{
	thread->status = THINKING;
	if (print_status(THINKING, thread))
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
	if (grab_fork(thread, thread->philo_nth) == -1)
		return (-1);
	thread->status = EATING;
	gettimeofday(&start, 0);
	shared->last_eat_time[thread->philo_nth] = start;
	if (print_status(EATING, thread) == -1)
		return (-1);
	gettimeofday(&mid, 0);
	rest = shared->time_to_eat * 1000 -1000 * (mid.tv_sec - start.tv_sec) + (mid.tv_usec - start.tv_usec) / 1000;
	usleep(rest);
	thread->eat_cnt++;
	return (0);
}

int	philo_sleeping(t_thread *thread)
{
	t_shared		*shared;
	struct timeval	start;
	struct timeval	mid;
	unsigned int	rest;

	shared = thread->shared;
	thread->status = SLEEPING;
	gettimeofday(&start, 0);
	if (print_status(SLEEPING, thread) == -1)
		return (-1);
	gettimeofday(&mid, 0);
	rest = shared->time_to_sleep * 1000 -1000 * (mid.tv_sec - start.tv_sec) + (mid.tv_sec - start.tv_sec) / 1000;
	usleep(rest);
	return (0);
}

int	grab_fork(t_thread *thread, int philo_nth)
{
	const int	left_fork = philo_nth;
	int			right_fork;
	t_shared	*shared;

	shared = thread ->shared;
	if (philo_nth == shared->number_of_philos)
		right_fork = 0;
	else
		right_fork = philo_nth + 1;
	pthread_mutex_lock(&shared->fork[left_fork]);
	thread->status = LEFT_FORK;
	if (print_status(LEFT_FORK, thread) == -1)
		return (-1);
	pthread_mutex_lock(&shared->fork[right_fork]);
	thread->status = RIGHT_FORK;
	if (print_status(RIGHT_FORK, thread) == -1)
		return (-1);
	return (0);
}

int	check_eat_cnt(t_thread *thread)
{
	t_shared	*shared;

	shared = thread->shared;
	if (thread->eat_cnt == shared->min_eat_times)
	{
		pthread_mutex_lock(&shared->eat_finish_lock);
		shared->eat_finish_philos++;
		pthread_mutex_unlock(&shared->eat_finish_lock);
		return (1);
	}
	return (0);
}
