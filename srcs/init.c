/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:37:09 by wimam             #+#    #+#             */
/*   Updated: 2025/05/08 09:54:06 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

BOOL	get_args(t_philo *philo, char **av)
{
	philo->arg.philo_nbr = ft_atoi(av[0]);
	philo->arg.die = ft_atoi(av[1]);
	philo->arg.eat = ft_atoi(av[2]);
	philo->arg.sleep = ft_atoi(av[3]);
	philo->arg.stop = ft_atoi(av[4]);
	philo->arg.think = philo->arg.die - (philo->arg.eat + philo->arg.sleep);
	if (philo->arg.think < 0)
		philo->arg.think = 0;
	else if (philo->arg.think > 200)
		philo->arg.think = 200;
	if (philo->arg.stop == 0)
		return (FALSE);
	if (philo->arg.philo_nbr <= 0 || philo->arg.philo_nbr > MAX_PHILO)
		return (err_msg(ERR_PHILO_RANGE), FALSE);
	if (philo->arg.die <= 0 || philo->arg.eat <= 0 || philo->arg.sleep <= 0
		|| (philo->arg.stop < 0 && av[4]))
		return (err_msg(ERR_NEGATIVE_ARG), FALSE);
	return (TRUE);
}

BOOL	create_forks(t_philo *philo)
{
	int	i;

	i = -1;
	if (pthread_mutex_init(&philo->print_lock, NULL) != 0)
		return (FALSE);
	while (++i < philo->arg.philo_nbr)
	{
		if (pthread_mutex_init(&philo->locks[i], NULL) != 0)
		{
			while (i >= 0)
				pthread_mutex_destroy(&philo->locks[i--]);
			return (err_msg(ERR_CREAT_MUTEX), FALSE);
		}
	}
	return (TRUE);
}

BOOL	struct_allocator(t_philo *philo)
{
	philo->threads = malloc(philo->arg.philo_nbr * sizeof(pthread_t));
	philo->flag = malloc(philo->arg.philo_nbr * sizeof(t_flag));
	philo->locks = malloc (philo->arg.philo_nbr * sizeof(pthread_mutex_t));
	philo->forks = malloc(philo->arg.philo_nbr * sizeof(int));
	philo->age = ft_calloc(philo->arg.philo_nbr, sizeof(int));
	philo->day_of_birth = malloc(philo->arg.philo_nbr * sizeof(long));
	philo->eating_counter = ft_calloc(philo->arg.philo_nbr, sizeof(int));
	philo->day = ft_calloc(philo->arg.philo_nbr, sizeof(int));
	if (!philo->flag || !philo->threads || !philo->locks || !philo->forks
		|| !philo->day || !philo->eating_counter || !philo->day_of_birth
		|| !philo->age)
		return (err_msg(ERR_HEAP_ALLOC_F), FALSE);
	return (TRUE);
}

BOOL	t_philo_init(t_philo *philo, char ac, char **av)
{
	int	i;

	if (ac < 4 || ac > 5)
		return (err_msg(ERR_ARG_COUNT), FALSE);
	if (get_args(philo, av) == FALSE)
		return (FALSE);
	if (struct_allocator(philo) == FALSE)
		return (ft_free(philo), FALSE);
	if (create_forks(philo) == FALSE)
		return (ft_free(philo), FALSE);
	philo->e_o_prog = FALSE;
	i = -1;
	while (++i < philo->arg.philo_nbr)
		philo->forks[i] = 1;
	i = -1;
	while (++i < philo->arg.philo_nbr)
	{
		philo->flag[i].eat = TRUE;
		philo->flag[i].sleep = TRUE;
		philo->flag[i].think = TRUE;
	}
	return (TRUE);
}
