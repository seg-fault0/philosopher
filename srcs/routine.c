/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:53:55 by wimam             #+#    #+#             */
/*   Updated: 2025/04/29 15:11:52 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_mutex(t_philo *philo, int id, int event)
{
	if (event == LOCK)
	{
		if (id == philo->arg.philo_nbr)
			pthread_mutex_lock(&philo->forks[0]);
		else 
			pthread_mutex_lock(&philo->forks[id]);
	}
	else if (event == UNLOCK)
	{
		if (id == philo->arg.philo_nbr)
			pthread_mutex_unlock(&philo->forks[0]);
		else 
			pthread_mutex_unlock(&philo->forks[id]);
	}
}

void	*philo_routine(void *arg)
{
	t_philo		*philo;
	static int	id_gen;
	int			id;

	philo = (t_philo *) arg;
	id = id_gen++;
	while (TRUE)
	{
		ft_mutex(philo, id, LOCK);
		printf("%d %d %s", philo->age[id], id, FORK_STR);
		ft_mutex(philo, id + 1, LOCK);
		printf("%d %d %s", philo->age[id], id, FORK_STR);
		printf("%d %d %s", philo->age[id], id, EAT_STR);
	}
	return (NULL);
}
