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

typedef struct s_actions t_actions;

typedef struct s_philos
{
	t_actions 			*actions;
	int					id;
	int					l_fork; //left fork
	int					r_fork; //right fork
	long int			time; //time
	pthread_t			thread; // thread para cada philo
	pthread_mutex_t		mutex; //mutex do fork e philo
	int					counter_meals;
	//int				nbr_philo;
	//int				total_nbr_of_meals;
	//int				total_nbr_of_meals_args;
//	time_t			time_of_last_meal;
//	int				time_to_eat;
//	int				time_to_die;
//	int				time_to_sleep;
//	time_t			limit_of_life;
//	int				stop;
	
}	t_philos;

typedef struct s_actions
{
	int					nbr_philo;
	int					nbr_meals;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	pthread_mutex_t		print;
	pthread_mutex_t		*forks;
	t_philos			*all_philos;
	long int			start_time;

} 	t_actions;

/*
	init struct functions
*/
void	init_struct(t_actions *actions);
void	create_philo(t_actions *actions);

/*
	utils functions
*/

int			ft_atoi(const char *nptr);
int			ft_isdigit(int i);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_bzero(void *s, size_t len);
long int	get_time(void);
int			free_all(t_actions *actions, int i);

/*
	time functions
*/


/*
	actions functions
*/

int 	set_meals(t_actions *actions);
void 	*kill_philo(t_philos *philo);
void 	status(t_philos *philo, char *message);
int		check_deaths(t_philos *philo);
int 	forks(t_philos *philo);
void	u_forks(t_philos *philo);
int		eating(t_philos *philo);
int		sleeping(t_philos *philo);


#endif