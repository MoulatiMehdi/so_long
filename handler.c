/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:32:19 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/03 17:32:19 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"
#include "player.h"
#include "so_long.h"

static void	ft_handler_key_set(int keycode, char keys[256], bool is_pressed)
{
	if (keycode < KEYS_TOTAL && keycode >= 0)
		keys[keycode] = is_pressed;
	if (keycode == KEY_LEFT)
		keys[KEY_A] = is_pressed;
	if (keycode == KEY_RIGHT)
		keys[KEY_D] = is_pressed;
	if (keycode == KEY_UP)
		keys[KEY_W] = is_pressed;
	if (keycode == KEY_DOWN)
		keys[KEY_S] = is_pressed;
}

int	ft_handler_key_press(int keycode, t_animation *animation)
{
	t_engine	*engine;

	engine = animation->engine;
	if (keycode == KEY_ESC)
		ft_game_destroy(animation);
	if (keycode == KEY_X && (engine->player->state == STATE_LOADING
			|| engine->player->state == STATE_ATTACK))
	{
		engine->player->is_loaded = false;
		engine->player->is_state_fixed = false;
		ft_player_state_set(engine->player, STATE_IDLE);
	}
	if (keycode == KEY_SPACE)
		engine->paused = !engine->paused;
	if (engine->player->state == STATE_DYING)
		engine->paused = false;
	ft_handler_key_set(keycode, engine->keys, true);
	return (0);
}

int	ft_handler_key_release(int keycode, t_engine *engine)
{
	ft_handler_key_set(keycode, engine->keys, false);
	return (0);
}
