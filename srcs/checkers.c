/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:52:14 by wimam             #+#    #+#             */
/*   Updated: 2025/05/03 10:53:41 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

BOOL	death_checker(t_philo *philo, int id)
{
	long			age;

	age = get_time() - philo->day_of_birth[id];
	if (philo->e_o_prog == TRUE)
		return (TRUE);
	if ((age > philo->age[id] + 5 && philo->eating_counter[id] < 2)
		|| philo->day[id] > philo->arg.die)
		return (ft_print(philo, id, DEAD), philo->e_o_prog = TRUE, TRUE);
	return (FALSE);
}

BOOL	eating_counter_checker(t_philo *philo)
{
	int				i;
	int				eat_count;

	if (philo->e_o_prog == TRUE)
		return (TRUE);
	if (philo->arg.stop >= 0)
	{
		i = -1;
		eat_count = 0;
		while (++i < philo->arg.philo_nbr)
		{
			if (philo->eating_counter[i] >= philo->arg.stop)
				eat_count++;
		}
		if (eat_count == philo->arg.philo_nbr)
			return (philo->e_o_prog = TRUE, TRUE);
	}
	return (FALSE);
}

BOOL	can_philo_eat(t_philo *philo, int id)
{
	int	next_id;

	if (philo->flag[id].eat == FALSE || philo->arg.philo_nbr <= 1)
		return (FALSE);
	next_id = (id + 1) % philo->arg.philo_nbr;
	fork_mutex(philo, id, LOCK);
	fork_mutex(philo, next_id, LOCK);
	if (philo->forks[id] == 1 && philo->forks[next_id] == 1)
		return (TRUE);
	fork_mutex(philo, id, UNLOCK);
	fork_mutex(philo, next_id, UNLOCK);
	return (FALSE);
}
