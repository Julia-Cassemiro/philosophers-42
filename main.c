/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 23:41:20 by jgomes-c          #+#    #+#             */
/*   Updated: 2022/04/28 23:41:20 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int valid_arg(t_actions *actions)
{
	if (actions->nbr_philo < 1 || actions->time_to_die == 0)
		return 0;
	if (actions->nbr_meals != 0 || nbr_meals < 1)
		return 0;
	return 1;
}

static void set_actions(t_actions *actions, int value, int v)
{
/*
	example
	./test 1 200 800

	Se o imput for esse
*/
	if (v == 1) //argv 1 é os philos
		actions->nbr_philo = value; //1 philo
	else if (v == 2) //argv 2 é o time to die
		actions->time_to_die = value; //200 is my time to die
	else if (v == 3) //argv 3 é o time to eat
		actions->time_to_eat = value; //200 is time to eat
	else if (v == 4) //argv 4 é o time to sleep
		actions->time_to_sleep = value; //and 800 is sleep time
	else
		actions->nbr_meals = value;
	printf("nbr_philo = %d\n", actions->nbr_philo);
	printf("time_to_die = %d\n", actions->time_to_die);
	printf("time_to_eat = %d\n", actions->time_to_eat);
	printf("time_to_sleep = %d\n", actions->time_to_sleep);
	printf("nbr_meals = %d\n", actions->nbr_meals);
}

void	ft_check_actions(void)
{
	printf(" ____________________________________________________ \n");
	printf("|            Please enter 4 or 5 arguments           |\n");
	printf("|____________________________________________________|\n");
	printf("|             [1][Numero de philo]                   |\n");
	printf("|             [2][Time to die]                       |\n");
	printf("|             [3][Time to eat]                       |\n");
	printf("|             [4][Time to sleep]                     |\n");
	printf("|             [5][Numero de refeiçoes]               |\n");
	printf("|____________________________________________________|\n");
}

static void		ft_check_valid(int argc, char **argv, t_actions *actions)
{
	int i;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		ft_check_actions();
		exit(1);
	}
	while (argv[i] != NULL)
	{
		set_actions(actions, ft_atoi(argv[i]), i); //sem o atoi n da certo, pq o argv vem como char.
		printf("value = %d, v = %d\n\n\n\n", ft_atoi(argv[i]), i);
		i++;
	}
	if (!valid_arg(actions)) //se for passado valores errados, e as minhas açoes n forem setadas
	{
		ft_check_actions();
		exit(1);
	}
}

int main(int argc, char **argv)
{
	t_actions	actions;

	memset(&actions, 0, sizeof(actions));
	ft_check_valid(argc, argv, &actions);
	return (0);
}