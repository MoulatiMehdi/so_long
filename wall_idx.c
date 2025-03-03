/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_idx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:32:48 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/03 22:14:39 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "wall.h"
#include <stdio.h>

void	ft_map_grid(t_map *map, t_point *point)
{
	t_point	p;

	p.y = 0;
	printf("\n");
	while (p.y < map->height)
	{
		p.x = 0;
		while (p.x < map->width)
		{
			if (point && point->x == p.x && point->y == p.y)
				printf("\033[42m%c\033[0m", map->data[p.y][p.x]);
			else
				printf("%c", map->data[p.y][p.x]);
			p.x++;
		}
		printf("\n");
		p.y++;
	}
	printf("\n");
}

void	ft_wall_only_wall(t_map *map, char **strs)
{
	t_point	p;

	p.y = 0;
	while (p.y < map->height)
	{
		p.x = 0;
		while (p.x < map->width)
		{
			if (ft_wall_isroof(map, &p))
			{
				strs[p.y][p.x] = WALL_ROOF;
			}
			else if (map->data[p.y][p.x] != '1')
			{
				strs[p.y][p.x] = WALL_EMPTY;
				map->data[p.y][p.x] = '0';
			}
			p.x++;
		}
		p.y++;
	}
}

void	ft_wall_ignore_obstacle(t_map *map, char **strs)
{
	t_point	p;

	p.y = 0;
	while (p.y < map->height)
	{
		p.x = 0;
		while (p.x < map->width)
		{
			if (map->data[p.y][p.x] == '1' && !ft_is_roof_touch(map, &p))
			{
				strs[p.y][p.x] = WALL_OBSTACLE;
				map->data[p.y][p.x] = '0';
			}
			p.x++;
		}
		p.y++;
	}
}

void	wall_idx(t_map *map)
{
	char	**strs;
	t_point	p;

	strs = ft_strs_dup(map->data);
	ft_wall_only_wall(map, strs);
	ft_wall_ignore_obstacle(map, strs);
	p.y = 0;
	while (p.y < map->height)
	{
		p.x = 0;
		while (p.x < map->width)
		{
			if (map->data[p.y][p.x] != '0')
				ft_wall_tile_type(map, &p, strs);
			p.x++;
		}
		p.y++;
	}
	ft_split_free(&map->data);
	map->data = strs;
}
