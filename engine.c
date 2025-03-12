/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:32:17 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/08 11:56:26 by mmoulati         ###   ########.fr       */
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
	ft_enemy_init(&engine->enemy);
}

t_engine	*ft_engine_new(void)
{
	t_engine	*engine;

	engine = ft_calloc(sizeof(t_engine), 1);
	if (engine)
	{
		ft_engine_init(engine);
		if (engine->player == NULL)
			ft_engine_destroy(&engine);
	}
	if (engine == NULL)
		ft_putstr_fd(ERR_ALLOC_FAILED, 2);
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

void	ft_engine_solider_update(t_engine *engine)
{
	t_enemy	*enemy;
	int		dx;
	int		dy;

	enemy = &engine->enemy;
	if (enemy->is_fixed || enemy->is_dead || enemy->state == STATE_DYING)
		return ;
	ft_way_init(&dx, &dy, enemy->way);
	if (!ft_collision_enemy_wall(&engine->enemy, engine->map, dx, dy))
	{
		ft_soldier_state_set(enemy, STATE_WALK);
		enemy->x += dx * enemy->speed;
		enemy->y += dy * enemy->speed;
	}
	else if (!enemy->is_fixed && enemy->state == STATE_WALK)
	{
		ft_soldier_state_set(enemy, STATE_IDLE);
		enemy->is_fixed = true;
	}
	else if (enemy->state == STATE_IDLE && !enemy->is_fixed)
		enemy->way = (enemy->way + 1) % WAY_TOTAL;
}

void	ft_engine_update(t_game *game)
{
	t_engine	*engine;
	t_render	*render;
	t_point		d;

	engine = game->engine;
	render = game->render;
	ft_engine_player_update(engine);
	ft_engine_solider_update(engine);
	ft_camera_update(render, engine);
	ft_engine_coins_update(game);
	ft_engine_collision(game->engine, game->render);
	if (engine->player->state == STATE_HURT)
	{
		ft_way_init(&d.x, &d.y, engine->player->way);
		ft_player_coor(engine, -d.x, -d.y);
	}
}
