/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:06:52 by wimam             #+#    #+#             */
/*   Updated: 2025/04/29 11:44:15 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atoi(const char *str)
{
	int					signe;
	long				a;
	int					i;

	a = 0;
	i = 0;
	signe = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			signe = -1;
	}
	if (str[i] < '0' || str[i] > '9')
		return (LONG_MAX);
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = a * 10 + (str[i++] - '0') * signe;
		if (a > INT_MAX || a < INT_MIN)
			return (LONG_MAX);
	}
	if (str[i])
		return (LONG_MAX);
	return (a);
}
