/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 23:38:00 by jgomes-c          #+#    #+#             */
/*   Updated: 2022/04/28 23:38:00 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

struct s_actions;

// typedef struct s_philo
// {
// 	int				nbr_philo;
// 	int				time_to_eat;
// 	int				time_to_die;
// 	int				time_to_sleep;
// }	t_philo;

typedef struct s_actions
{
	int				nbr_philo;
	int				nbr_meals;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
} 	t_actions;

/*
	init functions
*/


/*
	utils functions
*/

int	ft_atoi(const char *nptr);
int	ft_isdigit(int i);

/*
	time functions
*/


/*
	actions functions
*/



#endif