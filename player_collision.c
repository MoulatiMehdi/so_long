/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:32:40 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/05 21:57:25 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	ft_player_is_collision_h(t_player *player, t_map *map, int dx)
{
	t_point	p;
	int		i;

	i = 0;
	p.x = player->x + player->origin_x;
	p.x += dx * player->width / 2;
	p.x += dx * player->speed;
	p.x /= 64;
	while (i < 2)
	{
		p.y = player->y + player->origin_y;
		p.y += (2 * i - 1) * player->height / 2;
		p.y /= 64;
		if (!is_valid_point(map, &p) || map->data[p.y][p.x] != WALL_EMPTY)
			return (false);
		i++;
	}
	return (true);
}

static bool	ft_player_is_collision_v(t_player *player, t_map *map, int dy)
{
	t_point	p;
	int		i;

	i = 0;
	p.y = player->y + player->origin_y;
	p.y += dy * player->height / 2;
	p.y += dy * player->speed;
	p.y /= 64;
	i = 0;
	while (i < 2)
	{
		p.x = player->x + player->origin_x;
		p.x += (2 * i - 1) * player->width / 2;
		p.x /= 64;
		if (!is_valid_point(map, &p) || map->data[p.y][p.x] != WALL_EMPTY)
			return (false);
		i++;
	}
	return (true);
}

bool	ft_player_is_collision(t_player *player, t_map *map, int dx, int dy)
{
	if (!ft_player_is_collision_h(player, map, dx))
		return (true);
	if (!ft_player_is_collision_v(player, map, dy))
		return (true);
	return (false);
}
