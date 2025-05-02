/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:52:14 by wimam             #+#    #+#             */
/*   Updated: 2025/05/02 10:08:17 by wimam            ###   ########.fr       */
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
	{
		printf("%d %d %s", philo->age[id], (id + 1), DEAD_STR);
		philo->e_o_prog = TRUE;
		return (philo->e_o_prog = TRUE, TRUE);
	}
	if (philo->flag[id].sleep == FALSE && philo->flag[id].think == TRUE)
		philo->day[id] = 0;
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
