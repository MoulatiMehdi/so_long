/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_idx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:32:48 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/03 17:32:48 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "wall.h"
#include <stdio.h>

bool	ft_is_roof_touch(t_map *map, t_point *point)
{
	int		i;
	int		j;
	bool	istrue;
	t_point	p;

	istrue = false;
	i = -1;
	while (i < 2)
	{
		j = -1;
		while (j < 2)
		{
			p.x = point->x + i;
			p.y = point->y + j;
			if (is_valid_point(map, &p))
			{
				istrue = istrue || ft_wall_isroof(map, &p);
			}
			else
				return (true);
			j++;
		}
		i++;
	}
	return (istrue);
}

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
			if (map->data[p.y][p.x] == '0')
			{
				p.x++;
				continue ;
			}
			if (!ft_is_roof_touch(map, &p))
			{
				strs[p.y][p.x] = WALL_OBSTACLE;
				map->data[p.y][p.x] = '0';
			}
			else if (ft_wall_ismiddle_top(map, &p))
				strs[p.y][p.x] = WALL_IN_MID_TOP;
			else if (ft_wall_ismiddle_right(map, &p))
				strs[p.y][p.x] = WALL_IN_MID_RIGHT;
			else if (ft_wall_ismiddle_bottom(map, &p))
				strs[p.y][p.x] = WALL_IN_MID_BOTTOM;
			else if (ft_wall_ismiddle_left(map, &p))
				strs[p.y][p.x] = WALL_IN_MID_LEFT;
			else if (ft_wall_isleft_top(map, &p))
				strs[p.y][p.x] = WALL_IN_LEFT_TOP;
			else if (ft_wall_isright_top(map, &p))
				strs[p.y][p.x] = WALL_IN_RIGHT_TOP;
			else if (ft_wall_isright_bottom(map, &p))
				strs[p.y][p.x] = WALL_IN_RIGHT_BOTTOM;
			else if (ft_wall_isleft_bottom(map, &p))
				strs[p.y][p.x] = WALL_IN_LEFT_BOTTOM;
			else if (ft_wall_outside_isright_bottom(map, &p))
				strs[p.y][p.x] = WALL_OUT_RIGHT_BOTTOM;
			else if (ft_wall_outside_isright_top(map, &p))
				strs[p.y][p.x] = WALL_OUT_RIGHT_TOP;
			else if (ft_wall_outside_isleft_top(map, &p))
				strs[p.y][p.x] = WALL_OUT_LEFT_TOP;
			else if (ft_wall_outside_isleft_bottom(map, &p))
				strs[p.y][p.x] = WALL_OUT_LEFT_BOTTOM;
			else if (ft_wall_inter_isdiagonal(map, &p))
				strs[p.y][p.x] = WALL_INTER_DIAGONAL;
			else if (ft_wall_inter_isantidiagonal(map, &p))
				strs[p.y][p.x] = WALL_INTER_ANTIDIAGONAL;
			p.x++;
		}
		p.y++;
	}
	ft_split_free(&map->data);
	map->data = strs;
}
