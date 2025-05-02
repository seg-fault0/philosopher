/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <walidimam69gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:06:52 by wimam             #+#    #+#             */
/*   Updated: 2025/05/02 09:47:24 by wimam            ###   ########.fr       */
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
	if (!str)
		return (-1);
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

void	*ft_memset(void *b, int c, size_t len)
{
	size_t		i;
	char		*buffer;

	i = 0;
	buffer = (char *) b;
	while (i < len)
	{
		buffer[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*buffer;
	size_t	x;

	if (count == 0 || size == 0)
		return (malloc(0));
	x = count * size;
	if (x / count != size || x / size != count)
		return (NULL);
	buffer = malloc(x);
	if (!buffer)
		return (NULL);
	ft_memset(buffer, 0, x);
	return (buffer);
}
