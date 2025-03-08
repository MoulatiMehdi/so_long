/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solvable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:06:41 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/08 16:32:45 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	ft_check_iseliminited(t_map *map)
{
	t_point	p;

	p.y = 0;
	while (p.y < map->height)
	{
		p.x = 0;
		while (p.x < map->width)
		{
			if (map->data[p.y][p.x] == CHAR_COLLECTABLE
				|| map->data[p.y][p.x] == CHAR_EXIT)
				return (false);
			if (ft_strchr(CHARS_CHAGE, map->data[p.y][p.x]))
				map->data[p.y][p.x] = CHARS_VALID[map->data[p.y][p.x]
					- CHARS_CHAGE[0]];
			p.x++;
		}
		p.y++;
	}
	return (true);
}

static void	ft_check_eliminete(t_map *map, int x, int y)
{
	if (x > map->width || x < 0 || y < 0 || y > map->height)
		return ;
	if (ft_strchr(CHARS_CHAGE, map->data[x][y]))
		return ;
	map->data[x][y] = CHARS_CHAGE[map->data[x][y] - CHARS_VALID[0]];
	ft_check_eliminete(map, y - 1, x);
	ft_check_eliminete(map, y + 1, x);
	ft_check_eliminete(map, y, x - 1);
	ft_check_eliminete(map, y, x + 1);
	return ;
}

bool	ft_check_solvable(t_map *map)
{
	t_point	p;

	p.x = 0;
	p.y = 0;
	while (p.y < map->height)
	{
		if (ft_strchr(map->data[p.y], CHAR_PLAYER))
		{
			p.x = ft_strchr(map->data[p.y], CHAR_PLAYER) - map->data[p.y];
			break ;
		}
		p.y++;
	}
	ft_check_eliminete(map, p.x, p.y);
	return (ft_check_iseliminited(map));
}
