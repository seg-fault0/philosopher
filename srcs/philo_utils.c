/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:53:36 by wimam             #+#    #+#             */
/*   Updated: 2025/04/29 17:01:33 by wimam            ###   ########.fr       */
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
