/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 23:32:44 by jgomes-c          #+#    #+#             */
/*   Updated: 2022/05/11 23:32:44 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_deaths(t_philos *philo)
{
	int	y;
	int	limit;

	limit = 0;
	y = -1;
	while (++y < philo->actions->nbr_philo)
	{
		pthread_mutex_lock(&philo->actions->all_philos[y].mutex);
		if (get_time() - philo->actions->all_philos[y].time >= philo->actions->time_to_die)
		{
			pthread_mutex_unlock(&philo->actions->all_philos[y].mutex);
			philo->actions->all_philos[y].time = -1;
			return (1);
		}
		pthread_mutex_unlock(&philo->actions->all_philos[y].mutex);
		if (philo->actions->nbr_meals && philo->counter_meals
			>= philo->actions->nbr_meals)
			limit++;
		if (limit == philo->actions->nbr_philo)
			return (1);
	}
	return (0);
}

int	eating(t_philos *philo)
{
	if (forks(philo) == 0)
		return (0);
	if (check_deaths(philo))
		return (0);
	philo->time = get_time();
	status(philo, "is eating");
	while (get_time() - philo->time < philo->actions->time_to_eat)
	{
		if (check_deaths(philo))
		{
			u_forks(philo);
			return (0);
		}
		usleep(1000);
	}
	u_forks(philo);
	philo->counter_meals++;
	if (check_deaths(philo))
		return (0);
	return (1);
}

int	sleeping(t_philos *philo)
{
	long int	time;

	if (check_deaths(philo))
		return (0);
	time = get_time();
	status(philo, "is sleeping");
	while (get_time() - time < philo->actions->time_to_sleep)
	{
		if (check_deaths(philo))
			return (0);
		usleep(1000);
	}
	if (check_deaths(philo))
		return (0);
	return (1);
}

int	forks(t_philos *philo)
{
	if (check_deaths(philo))
		return (0);
	if (pthread_mutex_lock(&philo->actions->forks[philo->r_fork]) == 0)
	{
		if (check_deaths(philo))
		{
			u_forks(philo);
			return (0);
		}
		status(philo, "has taken right fork");
	}
	if (pthread_mutex_lock(&philo->actions->forks[philo->l_fork]) == 0)
	{
		if (check_deaths(philo))
		{
			u_forks(philo);
			return (0);
		}
		status(philo, "has taken left fork");
	}
	return (1);
}

void	u_forks(t_philos *philo)
{
	pthread_mutex_unlock(&philo->actions->forks[philo->r_fork]);
	pthread_mutex_unlock(&philo->actions->forks[philo->l_fork]);
}
