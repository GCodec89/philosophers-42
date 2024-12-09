/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:05:49 by gonolive          #+#    #+#             */
/*   Updated: 2024/12/09 17:54:48 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char *argv[])
{
	t_table	*table;

	table = NULL;
	check_args (argc, argv);
	table = init_table(argc, argv);
	if (!table)
	{
		return (printf(TABLE_ERROR), -1);
	}
	return (0);
}
