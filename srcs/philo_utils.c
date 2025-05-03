/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:53:36 by wimam             #+#    #+#             */
/*   Updated: 2025/05/03 10:58:25 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fork_mutex(t_philo *philo, int id, int event)
{
	if (event == LOCK)
		pthread_mutex_lock(&philo->locks[id]);
	else if (event == UNLOCK)
		pthread_mutex_unlock(&philo->locks[id]);
}

void	flag_manager(t_philo *philo, int id, int activity)
{
	if (activity == EAT)
	{
		philo->flag[id].eat = FALSE;
		philo->flag[id].sleep = TRUE;
	}
	else if (activity == SLEEP)
	{
		philo->flag[id].sleep = FALSE;
		philo->flag[id].think = TRUE;
		if (philo->arg.think == 0)
			philo->flag[id].eat = TRUE;
	}
	else if (activity == THINK)
	{
		philo->flag[id].think = FALSE;
		philo->flag[id].eat = TRUE;
	}
}

void	ft_fork(t_philo *philo, int id, int act)
{
	int	next_id;

	next_id = (id + 1) % philo->arg.philo_nbr;
	if (act == TAKE)
	{
		philo->forks[id] = 0;
		philo->forks[next_id] = 0;
	}
	else if (act == PUT)
	{
		fork_mutex(philo, id, LOCK);
		fork_mutex(philo, next_id, LOCK);
		philo->forks[id] = 1;
		philo->forks[next_id] = 1;
		fork_mutex(philo, id, UNLOCK);
		fork_mutex(philo, next_id, UNLOCK);
	}
}

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_print(t_philo *philo, int id, int activity)
{
	pthread_mutex_lock(&philo->print_lock);
	if (philo->e_o_prog == FALSE)
	{
		if (activity == EAT)
			printf("%d %d %s", philo->age[id], (id + 1), EAT_STR);
		else if (activity == FORK)
			printf("%d %d %s", philo->age[id], (id + 1), FORK_STR);
		else if (activity == SLEEP)
			printf("%d %d %s", philo->age[id], (id + 1), SLEEP_STR);
		else if (activity == THINK)
			printf("%d %d %s", philo->age[id], (id + 1), THINK_STR);
		else if (activity == DEAD)
			printf("%d %d %s", philo->age[id], (id + 1), DEAD_STR);
	}
	pthread_mutex_unlock(&philo->print_lock);
}
