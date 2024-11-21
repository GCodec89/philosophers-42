/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 07:42:30 by gonolive          #+#    #+#             */
/*   Updated: 2024/11/21 16:54:09 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_table	*init_table(int argc, char *argv[])
{
	t_table	*table;

	table = malloc(sizeof(t_table) * 1);
	if (!table)
	{
		return (printf(MALLOC_ERROR), NULL);
	}
	table->n_philos = ft_atoi(argv[1]);
	table->time_die = ft_atoi(argv[2]);
	table->time_eat = ft_atoi(argv[3]);
	table->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		table->must_eat = ft_atoi(argv[5]);
	}
	return (table);
}
