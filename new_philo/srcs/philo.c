/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ash <ash@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 16:17:58 by sehyan            #+#    #+#             */
/*   Updated: 2021/12/20 01:43:12 by ash              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	p_sleep(t_philo *philo)
{
	long long	now;

	get_time(&now);
	printf("%lld %d is sleep\n",  now - philo->data->start_t, philo->philo_id);
	s_sleep(philo, philo->data->sleep_t, now);
}

void	p_think(t_philo *philo)
{
	long long	now;

	get_time(&now);
	printf("%lld %d is thinking\n", now - philo->data->start_t, philo->philo_id);
}

void	pickup(pthread_mutex_t *fork, t_philo *philo)
{
	long long	now;

	get_time(&now);
	pthread_mutex_lock(&(*fork));
	printf("%lld %d has taken a fork\n",  now - philo->data->start_t, philo->philo_id);
}

void	p_eat(t_philo *philo)
{
	long long time;

	if (philo->i % 2 == 0)
	{
		pickup(&(philo->data->fork[philo->left]), philo);
		pickup(&(philo->data->fork[philo->right]), philo);
	}
	else
	{
		pickup(&(philo->data->fork[philo->right]), philo);
		pickup(&(philo->data->fork[philo->left]), philo);
	}
	get_time(&time);
	philo->last_eat_time = time;
	printf("%lld %d is eating\n", time - philo->data->start_t, philo->philo_id);
	philo->eat_cnt++;
	s_sleep(philo, philo->data->eat_t, time);
	pthread_mutex_unlock(&(philo->data->fork[philo->right]));
	pthread_mutex_unlock(&(philo->data->fork[philo->left]));
}

void	*p_routine(void *p)
{
	t_philo *philo;

	philo = (t_philo *)p;
	while(true)
	{
		usleep(50);
		p_eat(philo);
		p_sleep(philo);
		p_think(philo);
	}
	return NULL;
}

int		start_thread(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->data->philo_cnt)
	{
		if (pthread_create(&(philo[i].tid), NULL, p_routine, &(philo[i])))
			return (1);
		pthread_detach(philo[i].tid);
		i++;
	}
	return (0);
}
