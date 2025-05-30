/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_track.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:32:41 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/07 21:05:19 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_player_state(t_player *player, char keys[256])
{
	int	total;

	if (player->state == STATE_DYING || player->state == STATE_VICTORY)
		return ;
	if (player->state == STATE_HURT)
	{
		player->is_loaded = false;
		if (player->frame_on_loop >= 10)
		{
			player->is_state_fixed = false;
			ft_player_state_set(player, STATE_IDLE);
		}
	}
	if (player->hearts <= 0)
		return (ft_player_state_set(player, STATE_DYING));
	if (player->is_state_fixed)
		return ;
	if (ft_player_state_attack(player, keys[KEY_X] == 1))
		return ;
	total = (keys[KEY_A] != keys[KEY_D]) + (keys[KEY_S] != keys[KEY_W]);
	if (total == 0)
		return (ft_player_state_set(player, STATE_IDLE));
	else
		return (ft_player_state_set(player, STATE_WALK));
}

static void	ft_player_way(t_player *player, char keys[256])
{
	int	total;

	if (player->state == STATE_DYING || player->state == STATE_VICTORY)
		return ;
	total = (keys[KEY_A] != keys[KEY_D]) + (keys[KEY_S] != keys[KEY_W]);
	if (total == 0)
		return ;
	if (total == 1)
	{
		if (keys[KEY_A] == 1 && keys[KEY_D] == 0)
			player->way = WAY_LEFT;
		if (keys[KEY_A] == 0 && keys[KEY_D] == 1)
			player->way = WAY_RIGHT;
		if (keys[KEY_W] == 1 && keys[KEY_S] == 0)
			player->way = WAY_UP;
		if (keys[KEY_W] == 0 && keys[KEY_S] == 1)
			player->way = WAY_DOWN;
		return ;
	}
	if (keys[KEY_S] == 1 && player->way != WAY_LEFT && player->way != WAY_RIGHT)
		player->way = WAY_DOWN;
	if (keys[KEY_W] == 1 && player->way != WAY_LEFT && player->way != WAY_RIGHT)
		player->way = WAY_UP;
}

void	ft_engine_player_update(t_engine *engine)
{
	t_player	*player;
	char		*keys;

	keys = engine->keys;
	player = engine->player;
	ft_player_state(player, keys);
	ft_player_way(player, keys);
	player->is_moving = false;
	if (player->state != STATE_WALK && player->state != STATE_LOADING)
		return ;
	if (keys[KEY_A] == 0 && keys[KEY_D] == 1)
		ft_player_coor(engine, 1, 0);
	if (keys[KEY_A] == 1 && keys[KEY_D] == 0)
		ft_player_coor(engine, -1, 0);
	if (keys[KEY_W] == 0 && keys[KEY_S] == 1)
		ft_player_coor(engine, 0, 1);
	if (keys[KEY_W] == 1 && keys[KEY_S] == 0)
		ft_player_coor(engine, 0, -1);
}

void	ft_render_player(t_engine *engine, t_render *render)
{
	t_player	*player;

	player = engine->player;
	if (player->state == STATE_WALK)
		ft_player_walking(player, render);
	if (player->state == STATE_IDLE)
		ft_player_idle(player, render);
	if (player->state == STATE_DYING)
		ft_player_dying(player, render);
	if (player->state == STATE_ATTACK)
		ft_player_attack(player, render);
	if (player->state == STATE_SPIN)
		ft_player_spinning(player, render);
	if (player->state == STATE_VICTORY)
		ft_player_victory(player, render);
	if (player->state == STATE_LOADING)
		ft_player_loading(player, render);
	if (player->state == STATE_HURT)
		ft_player_hurt(player, render);
	player->frame_on_loop += !engine->paused;
}
