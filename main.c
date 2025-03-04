/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:32:25 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/03 21:14:41 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"
#include "libft/libft.h"
#include "player.h"
#include "so_long.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_handler_close(t_animation *animation);
int		ft_handler_key_press(int keycode, t_animation *animation);
int		ft_handler_key_release(int keycode, t_engine *engine);

void	ft_render_camera(t_render *render, t_engine *engine)
{
	t_point		*camera;
	t_player	*player;
	t_point		max;

	max.x = engine->map->width * 64 - WINDOW_WIDTH;
	max.y = engine->map->height * 64 - WINDOW_HEIGHT;
	player = engine->player;
	camera = &render->camera;
	camera->x = player->x - WINDOW_WIDTH / 2;
	camera->y = player->y - WINDOW_HEIGHT / 2;
	if (camera->x < 0)
		camera->x = 0;
	if (camera->y < 0)
		camera->y = 0;
	if (camera->x > max.x)
		camera->x = max.x;
	if (camera->y > max.y)
		camera->y = max.y;
}

/*void	draw_react(t_render *image, t_player *player, t_color color)*/
/*{*/
/*	int		j;*/
/*	t_point	p;*/
/**/
/*	ft_player_camera_center(image, player, &p);*/
/*	p.x += -player->width / 2 + player->origin_x;*/
/*	p.y += -player->height / 2 + player->origin_y;*/
/*	j = 0;*/
/*	while (j < player->width)*/
/*	{*/
/*		ft_image_putpixel(image->back, p.x + j, p.y, color);*/
/*		j++;*/
/*	}*/
/*	j = 0;*/
/*	while (j < player->height)*/
/*	{*/
/*		ft_image_putpixel(image->back, p.x, p.y + j, color);*/
/*		ft_image_putpixel(image->back, p.x + player->width - 1, p.y + j,
			color);*/
/*		j++;*/
/*	}*/
/*	j = 0;*/
/*	while (j < player->width)*/
/*	{*/
/*		ft_image_putpixel(image->back, p.x + j, p.y + player->height - 1,*/
/*			color);*/
/*		j++;*/
/*	}*/
/*}*/

int	ft_animation_update(t_animation *animation)
{
	t_engine	*engine;
	t_render	*render;

	engine = animation->engine;
	render = animation->render;
	if (render->stop)
		return (0);
	if (!engine->paused)
		ft_player_move(engine);
    ft_coin_update(animation);
	ft_render_camera(render, engine);
	ft_map_display(render, engine->map);
	ft_player_render(animation);
	ft_hearts_render(animation);
	ft_coin_render(animation);
	ft_counter_render(animation);
	ft_key_debug(animation);
	ft_rupee_render(render,engine);
	ft_render_display(render);
	return (0);
}


void ft_engine_setdata(t_engine * engine,t_point * p)
{ 
    char c;
    t_coin * coin;

    c = engine->map->data[p->y][p->x];
	if (c == 'P')
	{
		engine->player->x = p->x * 64 + 8;
		engine->player->y = p->y * 64 - 8;
	}
	if(c == 'E')
    {
        engine->exit.x = p->x * 64 ;
        engine->exit.y = p->y * 64 ;
    }
    if (c == 'C')
	{
        coin = ft_coin_new(p->x * 64 + 24,p->y* 64 + 16);
        ft_lstadd_front(&engine->coins,ft_lstnew(coin) );
	    engine->coins_total ++;
    }

}

void	ft_engine_player_coord(t_engine *engine)
{
    t_point p;
	t_map		*map;

	map = engine->map;
	if (map == NULL)
		return ;
	p.y = 0;
	while (p.y < map->height)
	{
		p.x = 0;
		while (p.x < map->width)
		{
            ft_engine_setdata(engine,&p);
            p.x++;
		}
		p.y++;
	}
}


int	main(void)
{
	t_animation	game;
	t_engine	*engine;
	t_render	*render;
	char		**map;
	static char *strs[] = {
		"1111111111111111",
		"1CP0000000000001",
		"1100011111111111",
		"1000001111111111",
		"1000000011111111",
		"1000000001111111",
		"1111111100000001",
		"1111111100000001",
		"1111111100000001",
		"1000000000000001",
		"1000000000000001",
		"1011100000011111",
		"1011100000011111",
		"1011100000011111",
		"1000000000000001",
		"1000000000000001",
		"1111111111111111",
		NULL,
	};

	map = ft_strs_dup(strs);
	render = ft_render_new();
	if (render == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	engine = ft_engine_new();
	if (engine == NULL)
	{
		ft_render_clear(&render);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	game.render = render;
	game.engine = engine;
	engine->map = ft_map_new(map);
	render->map_width = engine->map->width;
	render->map_height = engine->map->height;
	ft_engine_player_coord(engine);
	wall_idx(engine->map);
	mlx_do_key_autorepeatoff(render->mlx);
	mlx_hook(render->window, ON_DESTROY, 0, ft_handler_close, &game);
	mlx_hook(render->window, ON_KEYDOWN, 1L << 0, ft_handler_key_press, &game);
	mlx_hook(render->window, ON_KEYUP, 1L << 1, ft_handler_key_release, engine);
	mlx_loop_hook(render->mlx, ft_animation_update, &game);
	mlx_loop(render->mlx);
}
