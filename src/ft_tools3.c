/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <aosobliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 14:10:13 by aosobliv          #+#    #+#             */
/*   Updated: 2017/03/11 14:50:09 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	free_mass(t_wolf *wolf)
{
	int	i;
	int	j;

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
