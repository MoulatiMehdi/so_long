/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:32:44 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/08 13:59:59 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "so_long.h"

void		ft_render_sprites_init(t_render *render);

void	ft_render_window_init(t_render **render)
{
	(*render)->mlx = mlx_init();
	if ((*render)->mlx == NULL)
	{
		ft_putstr_fd(ERR_MLX_FAILED, 2);
		ft_render_clear(&(*render));
		return ;
	}
	(*render)->window = mlx_new_window((*render)->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, WINDOW_TITLE);
	if ((*render)->window == NULL)
	{
		ft_putstr_fd(ERR_WINDOW_FAILED, 2);
		ft_render_clear(render);
		return ;
	}
	(*render)->stop = false;
}

t_render	*ft_render_new(void)
{
	t_render	*render;

	render = ft_calloc(sizeof(t_render), 1);
	if (render == NULL)
		return (NULL);
	ft_render_window_init(&render);
	if (!render)
		return (NULL);
	render->back = ft_image_new(render->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	render->front = ft_image_new(render->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (render->back == NULL || render->front == NULL)
	{
		ft_putstr_fd(ERR_ALLOC_FAILED, 2);
		ft_render_clear(&render);
		return (NULL);
	}
	ft_render_sprites_init(render);
	if (render->sprites == NULL)
		ft_render_clear(&render);
	return (render);
}

void	ft_render_clear(t_render **render)
{
	if (*render == NULL)
		return ;
	ft_image_clear(&(*render)->back);
	ft_image_clear(&(*render)->front);
	ft_sprites_clear(&(*render)->sprites);
	if ((*render)->window)
		mlx_destroy_window((*render)->mlx, (*render)->window);
	if ((*render)->mlx)
	{
		mlx_destroy_display((*render)->mlx);
		free((*render)->mlx);
	}
	free(*render);
	*render = NULL;
}

void	ft_render_soldier(t_render *render, t_engine *engine)
{
	t_enemy	*enemy;

	if (engine->enemy.is_dead)
		return ;
	enemy = &engine->enemy;
	if (enemy->state == STATE_WALK)
		ft_soldier_walk(render, enemy);
	else if (enemy->state == STATE_IDLE)
		ft_soldier_look(render, enemy);
	else if (enemy->state == STATE_DYING)
		ft_soldier_dying(render, enemy);
}

void	ft_render_update(t_game *game)
{
	t_render	*render;
	t_engine	*engine;

	render = game->render;
	engine = game->engine;
	ft_render_map(render, engine->map);
	ft_render_exit(&engine->exit, render);
	if (engine->player->state != STATE_DYING
		&& engine->player->state != STATE_VICTORY)
	{
		ft_render_coins(render, engine);
		ft_render_soldier(render, engine);
	}
	ft_render_player(engine, render);
	ft_render_hearts_counter(render, engine);
	ft_render_coins_counter(render, engine);
	ft_render_moves_counter(render, engine->player->moves);
	ft_render_keys(render, engine);
}
