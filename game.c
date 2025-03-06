/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:52:16 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/06 21:15:48 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

int			ft_handler_key_press(int keycode, t_animation *animation);
int			ft_handler_key_release(int keycode, t_engine *engine);

t_animation	*ft_game_new(char **map)
{
	t_animation	*game;

	game = ft_calloc(sizeof(t_animation), 1);
	if (game == NULL)
		return (NULL);
	game->render = ft_render_new();
	game->engine = ft_engine_new();
	if (game->render == NULL)
	{
		ft_render_clear(&game->render);
		ft_engine_destroy(&game->engine);
		free(game);
		return (NULL);
	}
	game->engine->map = ft_map_new(map);
	game->render->map_width = game->engine->map->width;
	game->render->map_height = game->engine->map->height;
	engine_parse(game->engine);
	return (game);
}

int	ft_game_destroy(t_animation *game)
{
	mlx_do_key_autorepeaton(game->render->mlx);
	ft_engine_destroy(&game->engine);
	ft_render_clear(&game->render);
	exit(1);
	return (0);
}

int	ft_game_update(t_animation *animation)
{
	t_engine	*engine;
	t_render	*render;

	engine = animation->engine;
	render = animation->render;
	if (render->stop)
		return (0);
	if (!engine->paused)
		ft_engine_update(animation);
	ft_render_update(animation);
	ft_render_display(render);
	return (0);
}

void	ft_game_start(t_animation *game)
{
	t_engine	*engine;
	t_render	*render;

	if (game == NULL)
		return ;
	engine = game->engine;
	render = game->render;
	mlx_do_key_autorepeatoff(render->mlx);
	mlx_hook(render->window, ON_DESTROY, 0, ft_game_destroy, game);
	mlx_hook(render->window, ON_KEYDOWN, 1L << 0, ft_handler_key_press, game);
	mlx_hook(render->window, ON_KEYUP, 1L << 1, ft_handler_key_release, engine);
	mlx_loop_hook(render->mlx, ft_game_update, game);
	mlx_loop(render->mlx);
}
