/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:22:00 by otoufah           #+#    #+#             */
/*   Updated: 2022/06/21 09:21:06 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_lenght(const char **av)
{
	size_t	i;

	i = 1;
	while (av[i])
	{
		if (ft_strlen(av[i]) == 0 || ft_atoi(av[1]) == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int ac, const char **av)
{
	t_philo	*philo;

	if (check_lenght(av) == 0)
	{
		printf("Invalid\n");
		return (0);
	}
	if (ft_check_args(ac, av) == 1)
	{
		printf("Not an integer\n");
		return (0);
	}
	if (ac < 5 || ac > 6)
	{
		printf("Invalid Arguments\n");
		return (0);
	}
	philo = malloc(sizeof(t_philo) * ft_atoi(av[1]));
	creating_philos(philo, av, ac);
	ft_is_dead(philo);
}
