/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaciz <oaciz@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:52:01 by oaciz             #+#    #+#             */
/*   Updated: 2023/03/03 15:52:01 by oaciz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long int	current_time(void)
{
	struct timeval	time;
	long long int	ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}

void	ft_usleep(t_ph *ph, long long time_eat)
{
	long long	start;

	start = current_time();
	while (!(ph->data->is_dead))
	{
		if (current_time() - start >= time_eat)
			break ;
		usleep(50);
	}
}
