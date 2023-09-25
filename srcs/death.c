/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:36:46 by jsabound          #+#    #+#             */
/*   Updated: 2023/09/25 15:26:59 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// va attendre une mort ou le bon nombre de rotation,
//  puis fermer tout les threads et free
int	join_death(t_philo *philo)
{
	int	i;

	i = -1;
	usleep((philo->time_to_die - 1) * 1000);
	while (is_gameover(philo->data) == 0 && get_rotate_value(philo->data,
			philo->nb_philo) == 0)
	{
		check_death(philo);
		usleep(8000);
	}
	while (++i < philo->nb_philo)
	{
		pthread_join((philo->philo), NULL);
		philo = philo->next;
	}
	return (free_philo(philo, philo->nb_philo));
}

int	check_death(t_philo *philo)
{
	int				i;
	int				ret;
	struct timeval	current;

	i = -1;
	ret = -1;
	while (++i < philo->nb_philo && ret == -1)
	{
		gettimeofday(&(current), NULL);
		pthread_mutex_lock(&(philo->access));
		if (convert_time(philo->time)
			+ philo->time_to_die < convert_time(current))
		{
			pthread_mutex_lock(&(philo->data->death));
			ret = (philo->i);
			philo->data->gameover = 1;
			pthread_mutex_unlock(&(philo->data->death));
		}
		pthread_mutex_unlock(&(philo->access));
		philo = philo->next;
	}
	if (ret != -1)
		print(philo->data, ret, 0, philo->data->start);
	return (ret);
}
