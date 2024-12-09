/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:06:02 by gonolive          #+#    #+#             */
/*   Updated: 2024/12/09 17:52:53 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

# define WRONG_ARGS "Error. Must use:\nPlease enter: ./philo <no. of philos> \
<time_to_die> <time_to_eat> <time_to_sleep> <max_meals> (optional)\n"

# define DIGIT_ONLY "Error.\nAll arguments must be digits only.\n"

# define BIG_NUMBER "Error.\nAll arguments must be less than 2147483647.\n"

# define NO_NEGATIVE "Error.\nNo negative energies.\n"

# define MALLOC_ERROR "Error.\nCould not allocate memory.\n"

# define MUTEX_ERROR "Error.\nCould not create mutex.\n"

# define TABLE_ERROR "Error.\nCould not create table.\n"

typedef struct s_table	t_table;
typedef struct s_philo
{
	unsigned int	id;
	pthread_mutex_t	meal_time_lock;
	t_table			*table;
	unsigned int	times_ate;
	unsigned int	fork[2];
}	t_philo;

typedef struct s_table
{
	unsigned int	n_philos;
	time_t			time_die;
	time_t			time_eat;
	time_t			time_sleep;
	int				must_eat;
	t_philo			**philos;
}	t_table;

t_table	*init_table(int argc, char *argv[]);

int		ft_atoi(const char *str);
long	ft_atol(const char *str);

int		check_int_max(char *argv[]);
int		check_is_digit(char *argv[]);
int		check_args(int argc, char *argv[]);

#endif