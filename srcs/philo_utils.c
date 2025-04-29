/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:53:36 by wimam             #+#    #+#             */
/*   Updated: 2025/04/29 17:16:24 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	ft_mutex(t_philo *philo, int id, int event)
{
	if (event == LOCK)
	{
		if (id == philo->arg.philo_nbr)
			pthread_mutex_lock(&philo->locks[0]);
		else 
			pthread_mutex_lock(&philo->locks[id]);
	}
	else if (event == UNLOCK)
	{
		if (id == philo->arg.philo_nbr)
			pthread_mutex_unlock(&philo->locks[0]);
		else 
			pthread_mutex_unlock(&philo->locks[id]);
	}
}

BOOL	can_philo_eat(t_philo *philo, int id)
{
	if (philo->flag[id].eat == FALSE)
		return(FALSE);
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