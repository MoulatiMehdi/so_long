#include "image.h"
#include "libft/libft.h"
#include "player.h"
#include "so_long.h"
#include <mlx.h>
#include <stdio.h>

int		ft_handler_close(t_animation *animation);
int		ft_handler_key_press(int keycode, t_animation *animation);
int		ft_handler_key_release(int keycode, t_engine *engine);

void ft_render_camera(t_render * render,t_engine * engine)
{
    t_point * camera;
    t_player * player;
    t_point max;

    max.x = engine->map->width  * 64 - WINDOW_WIDTH ;
    max.y = engine->map->height * 64 - WINDOW_HEIGHT ;
    player = engine->player;
    camera = &render->camera;
    camera->x = player->x - WINDOW_WIDTH / 2;
    camera->y = player->y - WINDOW_HEIGHT / 2;
    if(camera->x < 0 )
        camera->x = 0;
    if(camera->y < 0 )
        camera->y = 0;
    if(camera->x > max.x )
        camera->x = max.x;
    if(camera->y > max.y)
        camera->y = max.y;
}

void	draw_react(t_render *image, t_player *player, t_color color)
{
	int	j;
    t_point p;

    ft_player_camera_center(image, player, &p);
	p.x += -player->width / 2 + player->origin_x;
	p.y += - player->height / 2 + player->origin_y;
	j = 0;
	while (j < player->width)
	{
		ft_image_putpixel(image->back, p.x + j, p.y, color);
		j++;
	}
	j = 0;
	while (j < player->height)
	{
		ft_image_putpixel(image->back, p.x, p.y + j, color);
		ft_image_putpixel(image->back, p.x + player->width - 1, p.y + j, color);
		j++;
	}
	j = 0;
	while (j < player->width)
	{
		ft_image_putpixel(image->back, p.x + j, p.y + player->height - 1, color);
		j++;
	}
}

int	ft_animation_update(t_animation *animation)
{
    t_engine * engine;
    t_render* render;

    engine = animation->engine;
    render = animation->render;
	if (render->stop)
		return (0);
	ft_image_fill(render->back, 0X00FFFFFF);
	if (!engine->paused)
		ft_player_move(engine);
    ft_render_camera(render,engine);
	ft_map_display(render, engine->map);
	ft_image_grid(render->back, 64, 64, 0X00FF0000);
	ft_player_render(animation);
	draw_react(render, engine->player, 0X00FF0000);
	// ft_player_debug(animation->engine->player);
	ft_hearts_render(animation);
	ft_coin_render(animation);
	ft_counter_render(animation);
	ft_key_debug(animation);
	ft_render_display(render);
	return (0);
}

void	ft_engine_player_coord(t_engine *engine)
{
	int			i;
	int			j;
	t_map		*map;
	t_player	*player;

	map = engine->map;
	player = engine->player;
	if (map == NULL)
		return ;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->data[i][j] == 'P')
			{
				player->x =  j * 64 + 8;
				player->y =  i * 64 - 8;
                break ;
			}
			j++;
		}
		i++;
	}
}



int	main(void)
{
	t_animation	game;
	t_engine	*engine;
	t_render	*render;
	char		**map;

	char *strs[] = {
		"1111111111111111",
		"1000000000000001",
		"1100011111111111",
		"1000000000000001",
		"1000000000000001",
		"1000000000000001",
		"1000000000000001",
		"1000000000000001",
		"1000000000000001",
		"1000000000000001",
		"1000000000000001",
		"1000000000000001",
		"1000000000000001",
		"1000000000000001",
		"1000000000000001",
		"10000000000000P1",
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
	render->map_width =  engine->map->width;
	render->map_height =  engine->map->height;
    ft_engine_player_coord(engine);
    wall_idx(engine->map);
	mlx_do_key_autorepeatoff(render->mlx);
	mlx_hook(render->window, ON_DESTROY, 0, ft_handler_close, &game);
	mlx_hook(render->window, ON_KEYDOWN, 1L << 0, ft_handler_key_press, &game);
	mlx_hook(render->window, ON_KEYUP, 1L << 1, ft_handler_key_release, engine);
	mlx_loop_hook(render->mlx, ft_animation_update, &game);
	mlx_loop(render->mlx);
}
