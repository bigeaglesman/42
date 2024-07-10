/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngho <youngho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:29:53 by ycho2             #+#    #+#             */
/*   Updated: 2024/07/10 23:43:27 by youngho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_threads(t_shared *shared, t_thread *threads);
static void	join_threads(t_shared *shared);
static void	free_memory(t_thread *threads);

void leak()
{
	system("leaks philo");
}

int	main(int argc, char **argv)
{
	t_shared	*shared;
	t_thread	*threads;
	
	atexit(leak);
	shared = (t_shared *)malloc(sizeof(t_shared));
	if (parsing_arg(shared, argc - 1, argv) == -1)
		return (-1);
	threads = (t_thread *)malloc(sizeof(t_thread)*shared->number_of_philos);
	set_threads(shared, threads);
	check_philos(shared);
	join_threads(shared);
	free_memory(threads);
}

static void	set_threads(t_shared *shared, t_thread *threads)
{
	int			i;

	i = 0; 
	pthread_mutex_lock(&shared->start_lock);
	while (i < shared->number_of_philos)
	{
		threads[i].eat_cnt = 0;
		threads[i].philo_nth = i;
		threads[i].shared = shared;
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
