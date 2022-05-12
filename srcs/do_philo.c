/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:08:37 by jgomes-c          #+#    #+#             */
/*   Updated: 2022/05/11 22:08:37 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void 	status(t_philos *philo, char *message)
{
	long int time;

	pthread_mutex_lock(&philo->actions->print);
	time = get_time() - philo->actions->start_time;
	printf("%-10ld  %-7d %s\n", time, philo->id, message);
	pthread_mutex_unlock(&philo->actions->print);
}

void 	*kill_philo(t_philos *philo)
{
	pthread_mutex_lock(&philo->actions->forks[0]); //a gente bloqueia o unico garfo q o philo pega
	status(philo, "ELE VAI PEGAR UM GARFO");
	pthread_mutex_unlock(&philo->actions->forks[0]);
	status(philo, "E MORREU..");
	return (NULL);
}