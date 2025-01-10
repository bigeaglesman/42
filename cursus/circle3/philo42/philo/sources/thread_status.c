/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_status.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:01:42 by ycho2             #+#    #+#             */
/*   Updated: 2024/09/02 17:17:10 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	die_check(t_shared *shared);

int	print_status(int action, t_thread *thread)
{
	const char	*act_char[] = {"has taken a fork",
		"has taken a fork", "is eating",
		"is sleeping", "is thinking", "died"};
	int			time;
	t_shared	*shared;

	shared = thread->shared;
	pthread_mutex_lock(&shared->print_lock);
	if (die_check(shared))
	{
		pthread_mutex_unlock(&shared->print_lock);
		return (-1);
	}
	time = get_current_time() - thread->start;
	printf("%d %d %s\n", time, thread->philo_nth + 1, act_char[action]);
	pthread_mutex_unlock(&shared->print_lock);
	return (0);
}

static int	die_check(t_shared *shared)
{
	pthread_mutex_lock(&shared->die_lock);
	if (shared->die_flag == 1)
	{
		pthread_mutex_unlock(&shared->die_lock);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&shared->die_lock);
		return (0);
	}
}
