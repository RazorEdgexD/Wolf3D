/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosobliv <aosobliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:20:11 by aosobliv          #+#    #+#             */
/*   Updated: 2017/03/18 12:29:47 by aosobliv         ###   ########.fr       */
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
		}
		if (len_x != tmp_len_x / (wolf->map_height + 1))
			ft_error(1);
		wolf->map_len = len_x;
		len_x = 0;
		wolf->map_height++;
		i = -1;
		ft_strdel(&line);
	}
	ft_strdel(&line);
}

void	make_arr(t_wolf *wolf, int fd)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	wolf->map = (char **)malloc(sizeof(char *) * (wolf->map_height + 1));
	wolf->map_tmp = (char **)malloc(sizeof(char *) * (wolf->map_height + 1));
	wolf->map[wolf->map_height] = NULL;
	wolf->map_tmp[wolf->map_height] = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		wolf->map[i] = (char *)malloc(sizeof(char) * (wolf->map_len + 1));
		wolf->map_tmp[i] = (char *)malloc(sizeof(char) * (wolf->map_len + 1));
		wolf->map[i][wolf->map_len] = '\0';
		wolf->map_tmp[i][wolf->map_len] = '\0';
		j = -1;
		while (++j != wolf->map_len)
		{
			wolf->map[i][j] = line[j];
			wolf->map_tmp[i][j] = line[j];
		}
		i++;
		ft_strdel(&line);
	}
	ft_strdel(&line);
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
	make_arr(wolf, fd2);
}
