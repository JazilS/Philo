/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:37:59 by jsabound          #+#    #+#             */
/*   Updated: 2023/09/25 15:26:12 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long int	update_time(struct timeval start)
{
	struct timeval	time;

	gettimeofday(&(time), NULL);
	return (convert_time(time) - convert_time(start));
}

long int	convert_time(struct timeval time)
{
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
