/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:21:12 by otoufah           #+#    #+#             */
/*   Updated: 2022/06/05 14:21:13 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_eat(t_philo *philo)
{
	unsigned long	time;

	time = ft_get_time(philo->table->start_time);
	pthread_mutex_lock(&philo->table->state_msg);
	green();
	printf("%lu %d is eating\n", time, philo->id);
	philo->is_eating = 1;
	reset();
	philo->eat++;
	if (philo->eat == philo->table->nbr_eat)
	{
		pthread_mutex_lock(&philo->table->how_much);
		philo->table->how_much_eat++;
		pthread_mutex_unlock(&philo->table->how_much);
	}
	pthread_mutex_unlock(&philo->table->state_msg);
	philo->last_time_eat = ft_get_time(philo->table->start_time);
	ft_usleep(philo->table->time_eat);
	philo->is_eating = 0;
}
