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

int 	start_meal(t_actions *actions)
{
	int i;

	i = -1;
	while (++i < actions->nbr_philo)
	{
		if (pthread_join(actions->all_philos[i].thread, NULL))
			return (0);
		if (actions->all_philos[i].time == -1)
		{
			status(&actions->all_philos[i], "died");
			break;
		}		
	}
	return (1);
}

void	*philo_thread_action(void	*evr_philo)
{
	t_philos *philo;

	philo = evr_philo;
	if (philo->actions->nbr_philo == 1) //se tem um philo, ele n deve comer e deve morrer
		return (kill_philo(philo));
	if (!(philo->id % 2))
		usleep(1000);
	while(!check_deaths(philo))//o philo n morreu
	{
		if(eating(philo) == 0); //ele retorna zero qnd morreu, se n morreu continua o while
			printf("\nalo\n");
		if (check_deaths(philo) || !sleeping(philo))
			break ;
		status(philo, "is thinking");
	}
	return (NULL);
}


int 	set_meals(t_actions *actions)
{
	int i;

	i = -1;
	while (++i < actions->nbr_philo)
	{
		actions->start_time = get_time();
		if(pthread_create(&actions->all_philos[i].thread, NULL,
				philo_thread_action, &actions->all_philos[i]))
			return (0);
		/******
		 * crio a thread
		 * passo null como padrao
		 * passo o que essa thread vai precisar fazer 
		 * e o argumento para essa ação
		****/	
	}
	return (start_meal(actions));	
}