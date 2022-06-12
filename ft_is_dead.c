/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:51:12 by otoufah           #+#    #+#             */
/*   Updated: 2022/06/06 13:04:48 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_is_dead(t_philo *philo)
{
	int	diff;
	int	i;

	i = 0;
	while (i < philo->table->nbr_philo)
	{
		diff = ft_get_time(philo[i].table->start_time) - philo[i].last_time_eat;
		if (diff >= philo->table->time_die && !philo[i].is_eating)
		{
			pthread_mutex_lock(&philo->table->state_msg);
			printf("%ld %d is dead\n",
				ft_get_time(philo->table->start_time), philo->id);
			return (1);
		}
		i++;
		if (i == philo->table->nbr_philo)
			i = 0;
	}
	return (0);
}
