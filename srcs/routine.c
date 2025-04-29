/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:53:55 by wimam             #+#    #+#             */
/*   Updated: 2025/04/29 14:31:37 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo		*philo;
	static int	id_gen;
	int			id;

	philo = (t_philo *) arg;
	id = id_gen++;
	printf("Hello, this is thread %d\n", id + 1);
	return (NULL);
}
