/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehyan <sehyan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:40:34 by sehyan            #+#    #+#             */
/*   Updated: 2021/12/17 01:21:01 by sehyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	if (argc == 5 || argc == 6)
	{
		if (init(data, philo, argv))
			return (err_int("Init Error\n"));
		if (start_thread(philo))
			return (err_int("Philo Error\n"));
		if (monitor_thread(philo))
			return (err_int ("Monitor Error\m"));
		pthread_mutex_lock(data->mutex_exec);
		exit_philo(philo);
		return (0);
	}
	else
		return (err_int("Input Error\n"));
	return (0);
}
