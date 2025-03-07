/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:32:40 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/06 23:45:54 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	ft_enemy_is_collision_h(t_enemy *enemy, t_map *map, int dx)
{
	t_point	p;
	int		i;

	i = 0;
	p.x = enemy->x + enemy->origin_x;
	p.x += dx * enemy->width / 2;
	p.x += dx * enemy->speed;
	p.x /= 64;
	while (i < 2)
	{
		p.y = enemy->y + enemy->origin_y;
		p.y += (2 * i - 1) * enemy->height / 2;
		p.y /= 64;
		if (!is_valid_point(map, &p) || map->data[p.y][p.x] != WALL_EMPTY)
			return (false);
		i++;
	}
	return (true);
}

static bool	ft_enemy_is_collision_v(t_enemy *enemy, t_map *map, int dy)
{
	t_point	p;
	int		i;

	i = 0;
	p.y = enemy->y + enemy->origin_y;
	p.y += dy * enemy->height / 2;
	p.y += dy * enemy->speed;
	p.y /= 64;
	i = 0;
	while (i < 2)
	{
		p.x = enemy->x + enemy->origin_x;
		p.x += (2 * i - 1) * enemy->width / 2;
		p.x /= 64;
		if (!is_valid_point(map, &p) || map->data[p.y][p.x] != WALL_EMPTY)
			return (false);
		i++;
	}
	return (true);
}

bool	ft_collision_enemy_wall(t_enemy *enemy, t_map *map, int dx, int dy)
{
	if (!ft_enemy_is_collision_h(enemy, map, dx))
		return (true);
	if (!ft_enemy_is_collision_v(enemy, map, dy))
		return (true);
	return (false);
}
