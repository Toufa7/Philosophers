/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:21:19 by otoufah           #+#    #+#             */
/*   Updated: 2022/06/05 14:21:21 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned long	ft_get_time(unsigned long time)
{
	struct timeval	start;

	gettimeofday(&start, NULL);
	return ((start.tv_sec * 1000) + (start.tv_usec * 0.001) - time);
}

void	ft_usleep(unsigned long time)
{
	unsigned long	start;

	start = ft_get_time(0);
	while (ft_get_time(start) < time)
		usleep(100);
}
