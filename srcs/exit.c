/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:45:26 by wimam             #+#    #+#             */
/*   Updated: 2025/04/29 12:14:35 by wimam            ###   ########.fr       */
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
}
