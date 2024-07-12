/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:29:53 by ycho2             #+#    #+#             */
/*   Updated: 2024/07/12 14:08:17 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_threads(t_shared *shared, t_thread *threads, long long st);
static void	join_threads(t_shared *shared);
static void	free_memory(t_thread *threads);

int	main(int argc, char **argv)
{
	t_shared	*shared;
	t_thread	*threads;
	long long	start;

	start = get_current_time();
	shared = (t_shared *)malloc(sizeof(t_shared));
	if (parsing_arg(shared, argc - 1, argv, start) == -1)
	{
		printf ("arg error\n");
		free(shared);
		return (-1);
	}
	threads = (t_thread *)malloc(sizeof(t_thread)*shared->number_of_philos);
	set_threads(shared, threads, start);
	check_philos(shared, start);
	join_threads(shared);
	free_memory(threads);
}

static void	set_threads(t_shared *shared, t_thread *threads, long long st)
{
	int			i;

	i = 0; 
	pthread_mutex_lock(&shared->start_lock);
	while (i < shared->number_of_philos)
	{
		threads[i].eat_cnt = 0;
		threads[i].philo_nth = i;
		threads[i].shared = shared;
		threads[i].start = st;
		if (i == shared->number_of_philos - 1)
			threads[i].right_fork = 0;
		else
			threads[i].right_fork = i + 1;
		pthread_create(&shared->philo[i], 0, (void *)&thread_func, &threads[i]);
		i++;
	} 
	pthread_mutex_unlock(&shared->start_lock);
}

static void	join_threads(t_shared *shared)
{
	int	i;

	i = 0;
	while (i < shared->number_of_philos)
	{
		pthread_join(shared->philo[i], 0);
		i++;
	}
}

static void	free_memory(t_thread *threads)
{
	t_shared	*shared;
	int			i;

	i = 0;
	shared = threads[0].shared;
	while (i < shared->number_of_philos)
	{
		pthread_mutex_destroy(&shared->eat_time_lock[i]);
		pthread_mutex_destroy(&shared->fork[i]);
		i++;
	}
	free(shared->last_eat_time);
	free(shared->eat_time_lock);
	free(shared->fork);
	free(shared->philo);
	free(shared);
	free(threads);
}
