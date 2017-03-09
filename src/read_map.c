/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:20:11 by aosobliv          #+#    #+#             */
/*   Updated: 2017/03/01 15:20:13 by aosobliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	base_check(int fd, t_wolf *wolf)
{
	int		len_x;
	int		tmp_len_x;
	char	*line;
	int		i;

	i = -1;
	len_x = 0;
	tmp_len_x = 0;
	while (get_next_line(fd, &line) == 1)
	{
		while (line[++i] != '\0')
		{
			len_x++;
			tmp_len_x++;
			if (!(THRUE_CHAR(line[i])))
				ft_error(2);
		}
		if (len_x != tmp_len_x / (wolf->map_height + 1))
			ft_error(1);
		wolf->map_len = len_x;
		len_x = 0;
		wolf->map_height++;
		i = -1;
		free(line);
	}
}

char	**make_arr(t_wolf *wolf, int fd)
{
	int		i;
	int		j;
	char	*line;
	char	**tmp;

	i = 0;
	j = 0;
	tmp = (char **)malloc(sizeof(char *) * (wolf->map_height));
	tmp[wolf->map_height] = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		tmp[i] = (char *)malloc(sizeof(char) * (wolf->map_len));
		tmp[i][wolf->map_len] = '\0';
		while (j != wolf->map_len)
		{
			tmp[i][j] = line[j];
			j++;
		}
		j = 0;
		i++;
		free(line);
	}
	return (tmp);
}

void	side_wall(t_wolf *wolf)
{
	int		i;

	i = -1;
	while (++i != wolf->map_len)
	{
		if (wolf->map[0][i] != '1')
			ft_error(3);
		if (wolf->map[wolf->map_height - 1][i] != '1')
			ft_error(3);
	}
	i = -1;
	while (++i != wolf->map_height)
	{
		if (wolf->map[i][0] != '1')
			ft_error(3);
		if (wolf->map[i][wolf->map_len - 1] != '1')
			ft_error(3);
	}
}

void	wall_check(t_wolf *wolf)
{
	int		i;
	int		j;
	int		all_wall;

	all_wall = 1;
	i = -1;
	j = -1;
	while (++i != wolf->map_height)
	{
		j = -1;
		while (++j != wolf->map_len)
		{
			printf("%c|", wolf->map[i][j]);
			if (wolf->map[i][j] == 'p')
			{
				wolf->plr.pos.x = j + 0.5;
				wolf->plr.pos.y = i + 0.5;
				wolf->map[i][j] = '0';
			}
			if (wolf->map[i][j] != '1')
				all_wall = 0;
		}
		printf("\n");
	}
	printf("Player pos = (%f;%f)\n", wolf->plr.pos.x, wolf->plr.pos.y);
	if (all_wall == 1)
		ft_error(3);
	side_wall(wolf);
}

void	read_map(char *map, t_wolf *wolf)
{
	int		fd;
	int		fd2;

	if ((fd = open(map, O_RDONLY)) < 1)
		ft_error(4);
	if ((fd2 = open(map, O_RDONLY)) < 1)
		ft_error(4);
	base_check(fd, wolf);
	if (wolf->map_len < 3 && wolf->map_height < 3)
		ft_error(1);
	wolf->map = make_arr(wolf, fd2);
	wall_check(wolf);
	printf("len_x=%d len_y=%d\n", wolf->map_len, wolf->map_height);
}
