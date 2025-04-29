/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:28:15 by wimam             #+#    #+#             */
/*   Updated: 2025/04/29 14:30:44 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>

# define BOOL unsigned short
# define TRUE 1
# define FALSE 0 

# define ERR_ARG_COUNT 1
# define ERR_PHILO_RANGE 2
# define ERR_NEGATIVE_ARG 3
# define ERR_CREAT_MUTEX 4

# define MAX_PHILO 200

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
}t_philo;

// Prototypes : core
BOOL	t_philo_init(t_philo *philo, char ac, char **av);
void	err_msg(int msg);
void	*philo_routine(void *arg);

//utils
long	ft_atoi(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);

#endif