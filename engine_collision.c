/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 06:55:01 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/08 07:18:06 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_engine_collision(t_engine *engine, t_render *render)
{
	if (ft_collision_player_door(engine->player, render->sprites[SPRITE_EXIT],
			&engine->exit))
		return (ft_player_state_set(engine->player, STATE_VICTORY));
	if (engine->player->state != STATE_HURT
		&& ft_collision_player_enemy(engine->player, &engine->enemy))
	{
		ft_player_state_set(engine->player, STATE_HURT);
		engine->player->is_state_fixed = true;
		engine->player->hearts--;
	}
	if (ft_collision_spin_enemy(engine->player, &engine->enemy))
		ft_soldier_state_set(&engine->enemy, STATE_DYING);
	if (ft_collision_attack_enemy(engine->player, &engine->enemy))
		ft_soldier_state_set(&engine->enemy, STATE_DYING);
}
