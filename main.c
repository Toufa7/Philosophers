/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:22:00 by otoufah           #+#    #+#             */
/*   Updated: 2022/06/05 14:22:01 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, const char **av)
{
	t_philo	*philo;

	if (ft_check_args(ac, av) == 1)
		return (0);
	if (ac < 5 || ac > 6)
	{
		printf("Invalid Arguments\n");
		return (0);
	}
	philo = malloc(sizeof(t_philo) * ft_atoi(av[1]));
	if (ft_atoi(av[1]) == 1)
	{
		printf("No second fork avaliable\n");
		return (0);
	}
	creating_philos(philo, av, ac);
	ft_is_dead(philo);
}
