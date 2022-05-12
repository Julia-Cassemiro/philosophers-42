/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meals.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 21:36:22 by jgomes-c          #+#    #+#             */
/*   Updated: 2022/05/11 21:36:22 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


void	*philo_thread_action(void	*evr_philo)
{
	t_philos *philo;

	philo = evr_philo;
	if(philo->actions->nbr_philo == 1) //se tem um philo, ele n deve comer e deve morrer
	{
		return (kill_philo(philo));
	}


}


int 	set_meals(t_actions *actions)
{
	int i;

	i = -1;
	printf("actions->nbr_philo= %d\n", actions->nbr_philo);
	while (++i < actions->nbr_philo)
	{
		printf("i = %d\n", i);
		actions->start_time = get_time();
		if(pthread_create(&actions->all_philos[i].thread, NULL, philo_thread_action, &actions->all_philos[i]))
		/******
		 * crio a thread
		 * passo null como padrao
		 * passo o que essa thread vai precisar fazer 
		 * e o argumento para essa ação
		****/

			return (0);
		pthread_join(actions->all_philos[i].thread, NULL);
	
	}
	
}