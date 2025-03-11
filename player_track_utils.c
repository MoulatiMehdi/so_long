/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_track_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:32:43 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/03 17:32:43 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player_coor(t_engine *engine, int dx, int dy)
{
	t_player	*player;
	t_map		*map;

	map = engine->map;
	player = engine->player;
	if (dx == 0 && dy == 0)
		return ;
	player->is_moving = true;
	if (ft_collision_player_wall(player, map, dx, dy))
		return ;
	if (player->state != STATE_HURT)
		player->moves++;
	player->x += dx * player->speed;
	player->y += dy * player->speed;
}

bool	ft_player_state_attack(t_player *player, bool is_attack)
{
	if (is_attack && player->state == STATE_ATTACK)
	{
		ft_player_state_set(player, STATE_LOADING);
		return (true);
	}
	if (is_attack && player->state != STATE_LOADING)
	{
		ft_player_state_set(player, STATE_ATTACK);
		player->is_state_fixed = true;
		return (true);
	}
	if (is_attack)
		return (true);
	if (!is_attack && player->is_loaded)
	{
		ft_player_state_set(player, STATE_SPIN);
		player->is_state_fixed = true;
		return (true);
	}
	return (false);
}
