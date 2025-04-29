/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:53:55 by wimam             #+#    #+#             */
/*   Updated: 2025/04/29 16:07:21 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_activity(t_philo *philo, int id, int activity)
{
	if(activity == EAT)
	{
		ft_mutex(philo, id, LOCK);
		printf("%d %d %s", philo->age[id], id, FORK_STR);
		ft_mutex(philo, id + 1, LOCK);
		printf("%d %d %s", philo->age[id], id, FORK_STR);
		printf("%d %d %s", philo->age[id], id, EAT_STR);
		ft_mutex(philo, id, UNLOCK);
		ft_mutex(philo, id + 1, UNLOCK);
		philo->age[id] += philo->arg.eat;
	}
	else if (activity == SLEEP || activity == THINK)
	{
		printf("%d %d %s", philo->age[id], id, activity);
		if (activity == SLEEP)
			philo->age[id] += philo->arg.sleep;
		else if (activity)
			philo->age[id] += philo->arg.think;
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
