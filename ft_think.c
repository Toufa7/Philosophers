/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_think.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:21:55 by otoufah           #+#    #+#             */
/*   Updated: 2022/06/05 14:21:56 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_think(t_philo *philo)
{
	unsigned long	thiking_time;

	thiking_time = ft_get_time(philo->table->start_time);
	pthread_mutex_lock(&philo->table->state_msg);
	printf("%lu %d is thinking\n", thiking_time, philo->id);
	pthread_mutex_unlock(&philo->table->state_msg);
}
