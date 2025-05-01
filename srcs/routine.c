/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:53:55 by wimam             #+#    #+#             */
/*   Updated: 2025/05/01 10:08:47 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

BOOL	death_checker(t_philo *philo, int id)
{
	struct timeval	current_date;
	long			age;

	gettimeofday(&current_date, NULL);
	age = (current_date.tv_usec - philo->day_of_birth[id].tv_usec) / 1000;
	if (age > philo->age[id] + 50)
	{
		printf("%d %d %s", philo->age[id], (id + 1), DEAD_STR);
		printf("age = %ld | philo->age = %d\n", age, philo->age[id]);
		exit(0);
	}
}

void	ft_activity(t_philo *philo, int id, int activity)
{
	flag_manager(philo, id, activity);
	if (activity == EAT)
	{
		printf("%d %d %s", philo->age[id], (id + 1), FORK_STR);
		printf("%d %d %s", philo->age[id], (id + 1), FORK_STR);
		ft_fork(philo, id, TAKE);
		printf("%d %d %s", philo->age[id], (id + 1), EAT_STR);
		ft_mutex(philo, id, UNLOCK);
		ft_mutex(philo, (id + 1), UNLOCK);
		philo->age[id] += philo->arg.eat;
		usleep(USLEEP_TIME * philo->arg.eat);
		death_checker(philo, id);
		ft_fork(philo, id, PUT);
	}
	if (activity == SLEEP)
	{
		printf("%d %d %s", philo->age[id], (id + 1), SLEEP_STR);
		philo->age[id] += philo->arg.sleep;
		usleep(USLEEP_TIME * philo->arg.sleep);
		death_checker(philo, id);
	}
	else if (activity == THINK)
	{
		printf("%d %d %s", philo->age[id], (id + 1), THINK_STR);
		philo->age[id] += philo->arg.think;
		usleep(USLEEP_TIME * philo->arg.think);
		death_checker(philo, id);
	}
}

void	*philo_routine(void *arg)
{
	t_philo		*philo;
	static int	id_gen;
	int			id;

	philo = (t_philo *) arg;
	id = id_gen++;
	gettimeofday(&philo->day_of_birth[id], NULL);
	while (TRUE)
	{
		if (can_philo_eat(philo, id))
			ft_activity(philo, id, EAT);
		else if (philo->flag[id].sleep == TRUE)
			ft_activity(philo, id, SLEEP);
		else if (philo->flag[id].think == TRUE && philo->arg.think > 0)
			ft_activity(philo, id, THINK);
	}
	return (NULL);
}
