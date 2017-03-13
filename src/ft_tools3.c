/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <aosobliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 14:10:13 by aosobliv          #+#    #+#             */
/*   Updated: 2017/03/13 19:59:12 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	free_mass(t_wolf *wolf)
{
	int		i;
	int		j;

	i = -1;
	while (wolf->map_tmp[++i])
	{
		j = -1;
		while (wolf->map_tmp[i][++j])
		{
			wolf->map[i][j] = wolf->map_tmp[i][j];
		}
	}
}

void	ft_swap(double *dist, int i, int j)
{
	double	c;

	c = dist[i];
	dist[i] = dist[j];
	dist[j] = c;
}

void	ft_swap_int(int *dist, int i, int j)
{
	int	c;

	c = dist[i];
	dist[i] = dist[j];
	dist[j] = c;
}

void	sort(int *order, double *dist)
{
	int		gap;
	int		swapped;
	int		i;
	int		j;

	i = -1;
	swapped = 0;
	gap = SPR;
	while (gap > 1 || swapped)
	{
		gap = (gap * 10) / 13;
		if (gap == 9 || gap == 10)
			gap = 11;
		if (gap < 1)
			gap = 1;
		swapped = 0;
		while (++i < SPR - gap)
		{
			j = i + gap;
			if (dist[i] < dist[j])
			{
				ft_swap(dist, i, j);
				ft_swap_int(order, i, j);
				swapped = 1;
			}
		}
	}
}
