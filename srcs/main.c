/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:27:49 by wimam             #+#    #+#             */
/*   Updated: 2025/05/03 09:24:00 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_luncher(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->arg.philo_nbr)
		pthread_create(&philo->threads[i], NULL, philo_routine, (void *)philo);
	i = -1;
	while (++i < philo->arg.philo_nbr)
		pthread_join(philo->threads[i], NULL);
}

int	main(int ac, char **av)
{
	t_philo	philo;

	if (t_philo_init(&philo, --ac, ++av) == FALSE)
		return (1);
	ft_luncher(&philo);
	ft_exit(&philo);
	return (0);
}
