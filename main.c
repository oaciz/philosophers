/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaciz <oaciz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:52:31 by oaciz             #+#    #+#             */
/*   Updated: 2023/03/03 15:52:31 by oaciz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error(char *msg)
{
	printf("%s", msg);
	return ;
}

void	free_all(t_ph **ph)
{
	int		i;
	t_data	*data;

	i = -1;
	data = ph[0]->data;
	while (++i < data->fork_size)
		free(ph[i]);
	free(data->forks);
	free(data);
	free(ph);
}

int	main(int ac, char **av)
{
	t_data	*data;
	t_ph	**ph;

	if (ac != 5 && ac != 6)
		error("Error: arguments\n");
	data = data_init(ac, av);
	ph = philo_init(data);
	threading(ph);
}
