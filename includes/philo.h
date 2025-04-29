/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:28:15 by wimam             #+#    #+#             */
/*   Updated: 2025/04/29 16:29:54 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// Header
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>

// BOOL MACROS
# define BOOL unsigned short
# define TRUE 1
# define FALSE 0 

// ERR MACROS
# define ERR_ARG_COUNT 1
# define ERR_PHILO_RANGE 2
# define ERR_NEGATIVE_ARG 3
# define ERR_CREAT_MUTEX 4

// PHILO MACROS
# define MAX_PHILO 200
# define USLEEP_TIME 2000

// Mutex Macros
# define LOCK 0
# define UNLOCK 1

// Event Macros
# define FORK 0
# define EAT 1
# define SLEEP 2
# define THINK 3
# define DEAD 4

// Event STR Macros
# define FORK_STR "has taken a fork\n"
# define EAT_STR "is eating\n"
# define SLEEP_STR "is sleeping\n"
# define THINK_STR "is thinking\n"
# define DEAD_STR "died\n"

// STRUCT
typedef struct s_args
{
	int	philo_nbr;
	int	die;
	int	eat;
	int	sleep;
	int	think;
}t_args;

typedef struct s_philo
{
	t_args			arg;
	pthread_t		threads[MAX_PHILO];
	pthread_mutex_t	forks[MAX_PHILO];
	int				age[MAX_PHILO];
}t_philo;

// Prototypes : core
BOOL	t_philo_init(t_philo *philo, char ac, char **av);
void	err_msg(int msg);
void	*philo_routine(void *arg);
void	ft_mutex(t_philo *philo, int id, int event);

//utils
long	ft_atoi(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);

#endif