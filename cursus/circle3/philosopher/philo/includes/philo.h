/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycho2 <ycho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:03:06 by youngho           #+#    #+#             */
/*   Updated: 2024/06/26 20:13:33 by ycho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

# define LEFT_FORK 0
# define RIGHT_FORK 1
# define EATING 2
# define SLEEPING 3
# define THINKING 4
# define DEAD 5
# define FULL 6

typedef struct s_shared
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				min_eat_times;
	int				eat_finish_philos;
	int				die_flag;
	struct timeval	*last_eat_time;
	pthread_mutex_t	start_lock;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	*fork;
	pthread_t		*philo;
	pthread_mutex_t	die_lock;
	pthread_mutex_t	eat_finish_lock;
}t_shared;

typedef struct s_thread
{
	int	philo_nth;
	int	eat_cnt;
	int	status;
	// 자신의 상태 저장해 놨다가 나중에 자원 회수해야됨 
	// 행동->상태 업데이트->프린트락 획득-> 다이플래그확인-> 다이플래그on->상태 확인하고 자원 회수
	// status는 다른 스레드와 공유하지 않음-> 뮤텍스걸필요 없음
	// 스레드는 프린트하기 직전마다 자기 상태를 검사하고 상태검사 전에는 무조건 상태를 업데이트 함
	// 스레드의 상태가 잘못 업데이트 되어있을 경우 없음
	t_shared	*shared;
}t_thread;

int		ft_atoi(char *str);
void	parsing_arg(t_shared *shared, int num_arg, char **argv);
int		print_status(int action, t_thread *thread);

int	philo_thinking(t_thread *thread);
int	philo_thinking(t_thread *thread);
int	philo_sleeping(t_thread *thread);
int	grab_fork(t_shared *shared, int philo_nth);
int	check_eat_cnt(t_thread *thread);
#endif