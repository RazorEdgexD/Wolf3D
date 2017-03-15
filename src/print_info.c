/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <aosobliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:41:06 by aosobliv          #+#    #+#             */
/*   Updated: 2017/03/15 17:34:44 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_print_str(t_wolf *wolf, char *str)
{
	mlx_string_put(wolf->mlx, wolf->win, 10, wolf->text_y, 0xFFffff, str);
	wolf->text_y += 20;
}

void	ft_print_info(t_wolf *wolf)
{
	char	*tmp;
	char	*itoa;

	itoa = ft_itoa((int)(1.) /
		wolf->frametime);
	tmp = ft_strjoin("FPS = ", itoa);
	wolf->text_y = 10;
	ft_print_str(wolf, tmp);
	free(tmp);
	free(itoa);
	itoa = ft_itoa(wolf->lvl);
	tmp = ft_strjoin("LVL = ", itoa);
	mlx_string_put(wolf->mlx, wolf->win, 945, 10, 0xFFffff, tmp);
	free(tmp);
	free(itoa);
}
