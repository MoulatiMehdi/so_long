/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:32:25 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/05 23:16:00 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"
#include "libft/libft.h"
#include "player.h"
#include "so_long.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_handler_close(t_animation *animation);
int	ft_handler_key_press(int keycode, t_animation *animation);
int	ft_handler_key_release(int keycode, t_engine *engine);

int	ft_animation_update(t_animation *animation)
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

int	main(void)
{
	t_animation	game;
	t_engine	*engine;
	t_render	*render;
	char		**map;

	static char *strs[] = {
		"11111111111111",
		"1P00000000EC11",
		"11111111111C11",
		"10000000000CC1",
		"11111111111CC1",
		"1C111111CCCCC1",
		"1CC11111C11111",
		"1CCCCCCCC11111",
		"11111111111111",
		"11111111111111",
		NULL,
	};
	map = ft_strs_dup(strs);
	render = ft_render_new();
	engine = ft_engine_new();
	game.render = render;
	game.engine = engine;
	engine->map = ft_map_new(map);
	render->map_width = engine->map->width;
	render->map_height = engine->map->height;
	mlx_do_key_autorepeatoff(render->mlx);
	mlx_hook(render->window, ON_DESTROY, 0, ft_handler_close, &game);
	mlx_hook(render->window, ON_KEYDOWN, 1L << 0, ft_handler_key_press, &game);
	mlx_hook(render->window, ON_KEYUP, 1L << 1, ft_handler_key_release, engine);
	mlx_loop_hook(render->mlx, ft_animation_update, &game);
	mlx_loop(render->mlx);
}
