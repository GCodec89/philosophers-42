/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 07:42:30 by gonolive          #+#    #+#             */
/*   Updated: 2024/12/11 13:56:29 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static pthread_mutex_t	*init_forks(t_table *table)
{
	pthread_mutex_t	*forks;
	unsigned int	i;

	forks = malloc(sizeof(pthread_mutex_t) * table->n_philos);
	if (!forks)
		return (free_table(table));
	i = 0;
	while (i < table->n_philos)
	{
		if (pthread_mutex_init(&forks[i], 0) != 0)
			return (free_table(table));
		i++;
	}
	return (forks);
}

static void	assign_forks(t_philo *philo)
{
	philo->fork[0] = philo->id;
	philo->fork[1] = (philo->id + 1) % philo->table->n_philos;
	if (philo->id % 2)
	{
		philo->fork[0] = (philo->id + 1) % philo->table->n_philos;
		philo->fork[1] = philo->id;
	}
}

static t_philo	**init_philos(t_table *table)
{
	t_philo			**philos;
	unsigned int	i;

	philos = malloc(sizeof(t_philo) * table->n_philos);
	if (!philos)
		return (free_table(table), NULL);
	i = 0;
	while (i < table->n_philos)
	{
		philos[i] = malloc(sizeof(t_philo) * 1);
		if (!philos[i])
			return (free_table(table), NULL);
		if (pthread_mutex_init(&philos[i]->meal_time_lock, 0) != 0)
			return (free_table(table), NULL);
		philos[i]->table = table;
		philos[i]->id = i;
		philos[i]->times_ate = 0;
		assign_forks(philos[i]);
		i++;
	}
	return (philos);
}

static void	init_global_mutexes(t_table *table)
{
	table->fork_locks = init_forks(table);
	if (!table->fork_locks)
	{
		free_table(table);
		return ;
	}
	if (pthread_mutex_init(&table->sim_stop_lock, 0) != 0)
	{
		free_table(table);
		return ;
	}
	if (pthread_mutex_init(&table->write_lock, 0) != 0)
	{
		free_table(table);
		return ;
	}
}

t_table	*init_table(int argc, char *argv[])
{
	t_table	*table;

	table = malloc(sizeof(t_table) * 1);
	if (!table)
	{
		return (free_table(table), NULL);
	}
	table->n_philos = ft_atoi(argv[1]);
	table->time_die = ft_atoi(argv[2]);
	table->time_eat = ft_atoi(argv[3]);
	table->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		table->must_eat = ft_atoi(argv[5]);
	}
	table->philos = init_philos(table);
	if (!table->philos)
		return (free_table(table), NULL);
	init_global_mutexes(table);
	table->sim_stop = false;
	return (table);
}
