/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsabound <jsabound@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:36:06 by jsabound          #+#    #+#             */
/*   Updated: 2023/09/25 15:24:52 by jsabound         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// parsing pour check les arguments recu
int	check_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if ((ac == 6 && ft_atoi(av[5]) <= 0) || ft_atoi(av[1]) <= 0
		|| ft_atoi(av[2]) <= 0 || ft_atoi(av[3]) <= 0 || ft_atoi(av[4]) <= 0)
		return (0);
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
		}
	}
	return (1);
}
