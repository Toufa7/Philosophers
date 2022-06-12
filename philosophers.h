/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:22:05 by otoufah           #+#    #+#             */
/*   Updated: 2022/06/05 14:22:05 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>

typedef struct s_table
{
	int				nbr_philo;
	int				nbr_eat;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				how_much_eat;
	int				eat;
	unsigned long	start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	state_msg;
}	t_table;

typedef struct s_philo
{
	int				id;
	int				is_eating;
	int				last_time_eat;
	pthread_t		thread;
	t_table			*table;
}	t_philo;

int				ft_atoi(const char *str);
unsigned long	ft_get_time(unsigned long time);
void			ft_mutex_init(t_philo *philo, t_table *table);
void			ft_grab_fork(t_philo *philo);
void			ft_eat(t_philo *philo);
void			ft_usleep(unsigned long time);
void			ft_release_fork(t_philo *philo);
void			ft_think(t_philo *philo);
void			ft_usleep(unsigned long time);
void			ft_sleep(t_philo *philo);
void			creating_philos(t_philo *philo, const char **av, int ac);
int				ft_is_dead(t_philo *philo);
int				ft_check_args(int ac, const char **av);

#endif 
