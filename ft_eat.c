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
	printf("%lu %d is eating\n", time, philo->id);
	philo->is_eating = 1;
	pthread_mutex_unlock(&philo->table->state_msg);
	philo->last_time_eat = time;
	ft_usleep(philo->table->time_eat);
	philo->is_eating = 0;
}
