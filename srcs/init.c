/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:30:56 by jgomes-c          #+#    #+#             */
/*   Updated: 2022/05/10 11:30:56 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int create_philo(t_actions *actions)
{
	int i;

	i = 0;
	printf("nbr_philo = %d\n\n\n", actions->nbr_philo);
	while (i < actions->nbr_philo)
	{
		actions->all_philos[i].id = i + 1;
		actions->all_philos[i].l_fork = i;
		actions->all_philos[i].r_fork = i + 1;
		actions->all_philos[i].actions = actions;
		actions->all_philos[i].time = get_time();
		if (i + 1 == actions->nbr_philo)
			actions->all_philos[i].r_fork = 0;
		// printf("id = %d\n", actions->all_philos[i].id);
		// printf("l_fork = %d\n", actions->all_philos[i].l_fork);
		// printf("r_fork = %d\n", actions->all_philos[i].r_fork);
		// printf("time = %ld\n", actions->all_philos[i].time);

		//preciso dar free, e retornar
		
		i++;
	}
	return (1);
}


int	init_struct(t_actions *actions)
{
	pthread_mutex_init(&actions->print, NULL);
	actions->forks = ft_calloc(actions->nbr_philo, sizeof(pthread_mutex_t)); //forks para cada philo
	actions->all_philos = ft_calloc(actions->nbr_philo, sizeof(t_philos));
	return (create_philo(actions));
}