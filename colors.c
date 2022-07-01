/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otoufah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:41:32 by otoufah           #+#    #+#             */
/*   Updated: 2022/06/14 11:41:36 by otoufah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	red(void)
{
	printf("\033[1;31m");
}

void	black(void)
{
	printf("\033[0;30m");
}

void	cyan(void)
{
	printf("\033[0;36m");
}

void	green(void)
{
	printf("\033[0;32m");
}

void	reset(void)
{
	printf("\033[0m");
}
