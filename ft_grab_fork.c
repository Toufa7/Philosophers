/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grab_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:21:26 by otoufah           #+#    #+#             */
/*   Updated: 2022/06/05 14:21:27 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
/**
 * ! by using mutex_unlock we can safely use shared resource
*/

void	ft_grab_fork(t_philo *philo)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->id - 1;
	right_fork = (philo->id) % philo->table->nbr_philo;
	pthread_mutex_lock(&(philo->table->forks[left_fork]));
	pthread_mutex_lock(&(philo->table->state_msg));
	printf("%lu %d has taken left fork\n",
		ft_get_time(philo->table->start_time), philo->id);
	pthread_mutex_unlock(&(philo->table->state_msg));
	pthread_mutex_lock(&(philo->table->forks[right_fork]));
	pthread_mutex_lock(&(philo->table->state_msg));
	printf("%lu %d has taken right fork\n",
		ft_get_time(philo->table->start_time), philo->id);
	pthread_mutex_unlock(&(philo->table->state_msg));
}
