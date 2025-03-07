/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:32:38 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/07 21:39:28 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "so_long.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ft_player_state_set(t_player *player, t_state state)
{
	if (player == NULL)
		return ;
	if (player->state == STATE_DYING)
		return ;
	if (player->state == STATE_VICTORY)
		return ;
	if (player->is_state_fixed && (state != STATE_DYING && state != STATE_HURT
			&& state != STATE_VICTORY))
		return ;
	if (state == player->state && state != STATE_ATTACK)
		return ;
	player->state = state;
	player->frame_on_loop = 0;
	if (player->state != STATE_LOADING)
		player->charge = 0;
}

t_player	*ft_player_new(void)
{
	t_player	*player;

	player = ft_calloc(sizeof(t_player), 1);
	if (player == NULL)
		return (NULL);
	player->coins = 0;
	player->charge = 0;
	player->moves = 0;
	player->hearts = 10;
	player->speed = 6;
	player->width = 24;
	player->height = 16;
	player->is_moving = false;
	player->is_loaded = false;
	player->is_dead = false;
	player->is_state_fixed = false;
	player->x = WINDOW_WIDTH / 2;
	player->y = WINDOW_HEIGHT / 2;
	player->way = WAY_DOWN;
	player->state = STATE_IDLE;
	player->frame_on_loop = 0;
	player->origin_y = 52;
	player->origin_x = 24;
	return (player);
}

void	ft_player_destroy(t_player **player)
{
	if (player == NULL || *player == NULL)
		return ;
	free(*player);
	*player = NULL;
}
