/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:53:55 by wimam             #+#    #+#             */
/*   Updated: 2025/04/29 16:24:00 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_activity(t_philo *philo, int id, int activity)
{
	if(activity == EAT)
	{
		ft_mutex(philo, id, LOCK);
		printf("%d %d %s", philo->age[id], (id + 1), FORK_STR);
		ft_mutex(philo, (id + 1), LOCK);
		printf("%d %d %s", philo->age[id], (id + 1), FORK_STR);
		printf("%d %d %s", philo->age[id], (id + 1), EAT_STR);
		ft_mutex(philo, id, UNLOCK);
		ft_mutex(philo, (id + 1), UNLOCK);
		philo->age[id] += philo->arg.eat;
		usleep(10000 * philo->arg.eat);
	}
	if (activity == SLEEP)
	{
		printf("%d %d %s", philo->age[id], (id + 1), SLEEP_STR);
		philo->age[id] += philo->arg.sleep;
		usleep(10000 * philo->arg.sleep);
	}
	else if (activity == THINK)
	{
		printf("%d %d %s", philo->age[id], (id + 1), THINK_STR);
		philo->age[id] += philo->arg.think;
		usleep(1000 * philo->arg.think);
	}
}

BOOL	death_checker(t_philo *philo, int id)
{
	return (FALSE);
}

void	*philo_routine(void *arg)
{
	t_philo		*philo;
	static int	id_gen;
	int			id;

	philo = (t_philo *) arg;
	id = id_gen++;
	if (id % 2 == 0)
		usleep(10);
	while (TRUE)
	{
		ft_activity(philo, id, EAT);
		death_checker(philo, id);
		ft_activity(philo, id, SLEEP);
		death_checker(philo, id);
		ft_activity(philo, id, THINK);
		death_checker(philo, id);
	}
	return (NULL);
}
