/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:53:36 by wimam             #+#    #+#             */
/*   Updated: 2025/04/29 17:38:07 by wimam            ###   ########.fr       */
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
	ft_mutex(philo, id, LOCK);
	ft_mutex(philo, id + 1, LOCK);
	if (philo->forks[id] == 1)
	{
		if(id == philo->arg.philo_nbr - 1 && philo->forks[0] == 1)
			return (TRUE);
		else if (id != philo->arg.philo_nbr - 1 && philo->forks[id + 1] == 1)
			return (TRUE);
	}
	ft_mutex(philo, id, UNLOCK);
	ft_mutex(philo, id + 1, UNLOCK);
	return (FALSE);
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

void	ft_fork(t_philo *philo, int id, int act)
{
	if (act == TAKE)
	{
		philo->forks[id] = 0;
		if (id == philo->arg.philo_nbr - 1)
			philo->forks[0] = 0;
		else
			philo->forks[id + 1] = 0;
	}
	else if (act == PUT)
	{
		ft_mutex(philo, id, LOCK);
		ft_mutex(philo, id + 1, LOCK);
		philo->forks[id] = 1;
		if (id == philo->arg.philo_nbr - 1)
			philo->forks[0] = 1;
		else
			philo->forks[id + 1] = 1;
		ft_mutex(philo, id, UNLOCK);
		ft_mutex(philo, id + 1, UNLOCK);
	}
}