/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:19:23 by gonolive          #+#    #+#             */
/*   Updated: 2024/11/19 19:01:15 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_int_max(char *argv[])
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atol(argv[i]) > INT_MAX)
		{
			return (printf(BIG_NUMBER), 1);
		}
		i++;
	}
	return (0);
}

int	check_is_digit(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-')
			return (printf(NO_NEGATIVE), 1);
		if (argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] > 57 || argv[i][j] < 48)
			{
				return (printf(DIGIT_ONLY), 1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_args(int argc, char *argv[])
{
	if (!(argc == 5 || argc == 6))
	{
		return (printf(WRONG_ARGS), 1);
	}
	check_is_digit(argv);
	check_int_max(argv);
	return (0);
}
