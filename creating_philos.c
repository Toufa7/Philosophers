/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:21:04 by otoufah           #+#    #+#             */
/*   Updated: 2022/06/05 14:21:05 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_routine(void *philos)
{
	int		nbr_eat;
	t_philo	*philo;

	philo = (t_philo *)philos;
	nbr_eat = philo->table->nbr_eat;
	while (nbr_eat)
	{
		ft_grab_fork(philo);
		ft_eat(philo);
		ft_release_fork(philo);
		ft_sleep(philo);
		ft_think(philo);
		nbr_eat--;
	}
	return (NULL);
}

void	creating_evens(t_table *table, t_philo *philo)
{
	int	idx;

	idx = 0;
	while (idx < table->nbr_philo)
	{
		philo[idx].id = idx + 1;
		philo[idx].table = table;
		philo[idx].is_eating = 0;
		philo[idx].last_time_eat = ft_get_time(0);
		pthread_create(&philo[idx].thread, NULL, &philo_routine, &philo[idx]);
		idx += 2;
	}
}

void	creating_odds(t_table *table, t_philo *philo)
{
	int	idx;

	idx = 1;
	while (idx < table->nbr_philo)
	{
		philo[idx].id = idx + 1;
		philo[idx].table = table;
		philo[idx].is_eating = 0;
		philo[idx].last_time_eat = ft_get_time(0);
		pthread_create(&philo[idx].thread, NULL, &philo_routine, &philo[idx]);
		idx += 2;
	}
}

void	creating_philos(t_philo *philo, const char **av, int ac)
{
	int		idx;
	t_table	*table;

	table = malloc(sizeof(t_table));
	table->start_time = ft_get_time(0);
	table->nbr_philo = ft_atoi(av[1]);
	table->time_die = ft_atoi(av[2]);
	table->time_eat = ft_atoi(av[3]);
	table->time_sleep = ft_atoi(av[4]);
	if (av[5])
		table->nbr_eat = ft_atoi(av[5]);
	else
		table->nbr_eat = -1;
	idx = 0;
	ft_mutex_init(philo, table);
	creating_evens(table, philo);
	usleep(300);
	creating_odds(table, philo);
}
