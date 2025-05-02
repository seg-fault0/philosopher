/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:52:14 by wimam             #+#    #+#             */
/*   Updated: 2025/05/02 14:06:13 by wimam            ###   ########.fr       */
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
	if (philo->flag[id].eat == FALSE || philo->arg.philo_nbr <= 1)
		return (FALSE);
	ft_mutex(philo, id, LOCK);
	ft_mutex(philo, id + 1, LOCK);
	if (philo->forks[id] == 1)
	{
		if (id == philo->arg.philo_nbr - 1 && philo->forks[0] == 1)
			return (TRUE);
		else if (id != philo->arg.philo_nbr - 1 && philo->forks[id + 1] == 1)
			return (TRUE);
	}
	ft_mutex(philo, id, UNLOCK);
	ft_mutex(philo, id + 1, UNLOCK);
	return (FALSE);
}
