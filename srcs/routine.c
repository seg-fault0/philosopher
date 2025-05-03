/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:53:55 by wimam             #+#    #+#             */
/*   Updated: 2025/05/03 11:01:18 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_calendar(t_philo *philo, int id, int activity)
{
	if (activity == EAT)
	{
		philo->age[id] += philo->arg.eat;
		philo->day[id] += philo->arg.eat;
		philo->eating_counter[id]++;
	}
	else if (activity == SLEEP)
	{
		philo->age[id] += philo->arg.sleep;
		philo->day[id] += philo->arg.sleep;
	}
	else if (activity == THINK)
	{
		philo->age[id] += philo->arg.think;
		philo->day[id] += philo->arg.think;
	}
	if (philo->flag[id].sleep == FALSE && philo->flag[id].think == TRUE)
		philo->day[id] = 0;
}

void	ft_activity(t_philo *philo, int id, int activity)
{
	int	next_id;

	next_id = (id + 1) % philo->arg.philo_nbr;
	flag_manager(philo, id, activity);
	if (activity == EAT)
	{
		ft_print(philo, id, FORK);
		ft_print(philo, id, FORK);
		ft_fork(philo, id, TAKE);
		ft_print(philo, id, EAT);
		fork_mutex(philo, id, UNLOCK);
		fork_mutex(philo, next_id, UNLOCK);
		ft_calendar(philo, id, EAT);
		usleep(USLEEP_TIME * philo->arg.eat);
		ft_fork(philo, id, PUT);
	}
	else
	{
		ft_print(philo, id, activity);
		ft_calendar(philo, id, activity);
		if (activity == SLEEP)
			usleep(USLEEP_TIME * philo->arg.sleep);
		else if (activity == THINK)
			usleep(USLEEP_TIME * philo->arg.think);
	}
}

void	create_philo(t_philo *philo, int *id)
{
	static int	id_gen;

	*id = id_gen++;
	philo->day_of_birth[*id] = get_time();
}

void	*philo_routine(void *arg)
{
	t_philo		*philo;
	int			id;

	philo = (t_philo *) arg;
	create_philo(philo, &id);
	while (TRUE)
	{
		if (can_philo_eat(philo, id))
			ft_activity(philo, id, EAT);
		else if (philo->flag[id].sleep == TRUE)
			ft_activity(philo, id, SLEEP);
		else if (philo->flag[id].think == TRUE && philo->arg.think > 0)
			ft_activity(philo, id, THINK);
		else
			usleep(5);
		if (death_checker(philo, id) || eating_counter_checker(philo))
			break ;
	}
	return (NULL);
}
