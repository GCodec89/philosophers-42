/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:06:02 by gonolive          #+#    #+#             */
/*   Updated: 2024/11/19 19:01:30 by gonolive         ###   ########.fr       */
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

long	ft_atol(const char *str);

int		check_int_max(char *argv[]);
int		check_is_digit(char *argv[]);
int		check_args(int argc, char *argv[]);

#endif