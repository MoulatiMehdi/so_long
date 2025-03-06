/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:32:17 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/03 17:32:17 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

void	ft_engine_init(t_engine *engine)
{
	engine->map = NULL;
	engine->player = ft_player_new();
	engine->paused = false;
	engine->coins = NULL;
	engine->coins_total = 0;
	ft_bzero(engine->keys, KEYS_TOTAL);
}

t_engine	*ft_engine_new(void)
{
	t_engine	*engine;

	engine = malloc(sizeof(t_engine));
	if (engine == NULL)
		return (NULL);
	ft_engine_init(engine);
	return (engine);
}

void	ft_engine_destroy(t_engine **engine)
{
	ft_player_destroy(&(*engine)->player);
	ft_map_destroy(&(*engine)->map);
	ft_lstclear(&(*engine)->coins, free);
	free(*engine);
	*engine = NULL;
}

void	ft_engine_update(t_animation *animation)
{
	t_engine	*engine;
	t_render	*render;

	engine = animation->engine;
	render = animation->render;
	ft_engine_player_update(engine);
	ft_camera_update(render, engine);
	ft_engine_coins_update(animation);
	if (engine->exit.is_on && ft_collision_player_door(engine->player,
			render->sprites[SPRITE_EXIT], &engine->exit))
		ft_player_state_set(engine->player, STATE_VICTORY);
}
