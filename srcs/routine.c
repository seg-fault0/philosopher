/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:53:55 by wimam             #+#    #+#             */
/*   Updated: 2025/04/29 17:47:39 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_activity(t_philo *philo, int id, int activity)
{
	flag_manager(philo, id, activity);
	if(activity == EAT)
	{
		printf("%d %d %s", philo->age[id], (id + 1), FORK_STR);
		printf("%d %d %s", philo->age[id], (id + 1), FORK_STR);
		ft_fork(philo, id, TAKE);
		printf("%d %d %s", philo->age[id], (id + 1), EAT_STR);
		ft_mutex(philo, id, UNLOCK);
		ft_mutex(philo, (id + 1), UNLOCK);
		usleep(USLEEP_TIME * philo->arg.eat);
		philo->age[id] += philo->arg.eat;
		ft_fork(philo, id, PUT);
	}
	if (activity == SLEEP)
	{
		printf("%d %d %s", philo->age[id], (id + 1), SLEEP_STR);
		philo->age[id] += philo->arg.sleep;
		usleep(USLEEP_TIME * philo->arg.sleep);
	}
	else if (activity == THINK)
	{
		printf("%d %d %s", philo->age[id], (id + 1), THINK_STR);
		philo->age[id] += philo->arg.think;
		usleep(USLEEP_TIME * philo->arg.think);
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
		if (can_philo_eat(philo, id))
			ft_activity(philo, id, EAT);
		else if (philo->flag[id].sleep == TRUE)
			ft_activity(philo, id, SLEEP);
		else if (philo->flag[id].think == TRUE)
			ft_activity(philo, id, THINK);
	}
	return (NULL);
}
