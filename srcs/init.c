/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:37:09 by wimam             #+#    #+#             */
/*   Updated: 2025/04/29 15:03:00 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

BOOL	get_args(t_philo *philo, char **av)
{
	philo->arg.philo_nbr = ft_atoi(av[0]);
	philo->arg.die = ft_atoi(av[1]);
	philo->arg.eat = ft_atoi(av[2]);
	philo->arg.sleep = ft_atoi(av[3]);
	philo->arg.think = philo->arg.die - (philo->arg.eat + philo->arg.sleep);
	if (philo->arg.philo_nbr <= 0 || philo->arg.philo_nbr > MAX_PHILO)
		return (err_msg(ERR_PHILO_RANGE), FALSE);
	if (philo->arg.die <= 0 || philo->arg.eat <= 0 || philo->arg.sleep <= 0)
		return (err_msg(ERR_NEGATIVE_ARG), FALSE);
	return (TRUE);
}

BOOL	create_forks(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->arg.philo_nbr)
	{
		if (pthread_mutex_init(&philo->forks[i], NULL) != 0)
		{
			while (i >= 0)
				pthread_mutex_destroy(&philo->forks[i--]);
			return (err_msg(ERR_CREAT_MUTEX), FALSE);
		}
	}
	return (TRUE);
}

BOOL	t_philo_init(t_philo *philo, char ac, char **av)
{
	if (ac < 4 || ac > 5)
		return (err_msg(ERR_ARG_COUNT), FALSE);
	if (get_args(philo, av) == FALSE)
		return (FALSE);
	if (create_forks(philo) == FALSE)
		return (FALSE);
	ft_memset(philo->age, 0, philo->arg.philo_nbr * sizeof(int));
	return (TRUE);
}
