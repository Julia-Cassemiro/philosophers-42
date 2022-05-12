/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:39:56 by jgomes-c          #+#    #+#             */
/*   Updated: 2022/05/10 10:39:56 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


int	ft_isdigit(int i)
{
	if (i >= 48 && i <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_atoi(const char *nptr)
{
	long	result;

	result = 0;
	while (ft_isdigit(*nptr))
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result);
}

void	ft_bzero(void *s, size_t len)
{
	unsigned char	*ns;
	size_t			i;

	i = 0;
	ns = s;
	while (i++ < len)
		*ns++ = 0;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*nn;

	nn = malloc(nmemb * size);
	if (nn == NULL)
		return (NULL);
	ft_bzero(nn, nmemb * size);
	return (nn);
}

long int	get_time(void)
{
	struct timeval	tv;
	long int		milliseconds;

	gettimeofday(&tv, NULL);
	milliseconds = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (milliseconds);
}