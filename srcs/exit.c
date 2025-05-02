/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:45:26 by wimam             #+#    #+#             */
/*   Updated: 2025/05/02 13:35:57 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	err_msg(int msg)
{
	if (msg == ERR_ARG_COUNT)
		write(2, "ERR : Too much/little args\n", 27);
	else if (msg == ERR_PHILO_RANGE)
		write(2, "ERR : 0 < philo_nbr <= 200\n", 27);
	else if (msg == ERR_NEGATIVE_ARG)
		write(2, "ERR : some args are negative\n", 29);
	else if (msg == ERR_CREAT_MUTEX)
		write(2, "ERR : failed to create a mutex\n", 31);
	else if (msg == ERR_HEAP_ALLOC_F)
		write(2, "ERR : failed to alocate memory\n", 31);
}

void	ft_free(t_philo *philo)
{
	free(philo->threads);
	free(philo->flag);
	free(philo->locks);
	free(philo->forks);
	free(philo->age);
	free(philo->day_of_birth);
	free(philo->eating_counter);
	free(philo->day);
}

void	ft_exit(t_philo *philo)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&philo->print_lock);
	while (++i < philo->arg.philo_nbr)
		pthread_mutex_destroy(&philo->locks[i]);
	ft_free(philo);
	return ;
}
