/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <aosobliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:41:06 by aosobliv          #+#    #+#             */
/*   Updated: 2017/03/16 14:02:51 by aosobliv         ###   ########.fr       */
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
	if (wolf->ch == 1 && wolf->ch1 == 1 && wolf->ch2 == 1)
		mlx_string_put(wolf->mlx, wolf->win, 500, 730, 0xFF0000, "Cheats ON");
	if (wolf->lvl == 0)
	{
		ft_print_str(wolf, "Test level");
		ft_print_str(wolf, "Check base functional");
	}
	if (wolf->lvl == 1)
	{
		free(tmp);
		free(itoa);
		itoa = ft_itoa(wolf->vov);
		tmp = ft_strjoin(itoa," / 5");
		if (wolf->vov != 5)
		{
			mlx_string_put(wolf->mlx, wolf->win, 945, 30, 0xFFffff, "Find me");
			mlx_string_put(wolf->mlx, wolf->win, 945, 50, 0xFFffff, tmp);
		}
		else
			mlx_string_put(wolf->mlx, wolf->win, 850, 30, 0xFFffff, "Find the way out");
	}
	if (wolf->lvl == 2)
		mlx_string_put(wolf->mlx, wolf->win, 850, 30, 0xFFffff, "Find the way out");
	free(tmp);
	free(itoa);
}
