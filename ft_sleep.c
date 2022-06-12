/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:21:46 by otoufah           #+#    #+#             */
/*   Updated: 2022/06/05 14:21:47 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_sleep(t_philo *philo)
{
	unsigned long	sleep_time;

	sleep_time = ft_get_time(philo->table->start_time);
	pthread_mutex_lock(&philo->table->state_msg);
	printf("%lu %d is sleep\n", sleep_time, philo->id);
	pthread_mutex_unlock(&philo->table->state_msg);
	ft_usleep(philo->table->time_sleep);
}
