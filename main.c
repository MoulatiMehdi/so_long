#include "image.h"
#include "libft/libft.h"
#include <mlx.h>
#include "player.h"
#include "so_long.h"


int	ft_animation_update(t_animation *animation)
{
	if (animation->render->stop)
		return (0);
	ft_image_fill(animation->render->back, 0X00FFFFFF);
    ft_map_display(animation->render,animation->engine->map);
	ft_image_grid(animation->render->back, 64, 64, 0X00FF0000);
	/*if (animation->engine->keys['p'] == 1)*/
	/*	animation->engine->player->hearts = 0;*/
	/*if (animation->engine->keys['v'] == 1)*/
	/*{*/
	/*	animation->engine->player->state = STATE_VICTORY;*/
	/*}*/
	ft_player_render(animation);
	//ft_player_debug(animation->engine->player);
	/*ft_hearts_render(animation);*/
	/*ft_coin_render(animation);*/
	/*ft_counter_render(animation);*/
	/*ft_key_debug(animation);*/
    ft_render_display(animation->render);
	return (0);
}

int	ft_handler_close(t_animation *animation);
int	ft_handler_key_press(int keycode, t_animation *animation);
int	ft_handler_key_release(int keycode, t_engine *engine);


void ft_engine_player_coord(t_engine * engine)
{
    int i;
    int j;
    t_map * map;
    map = engine->map;
    if(map == NULL)
        return ;
    i = 0;
    while(i < map->height)
    {
        j = 0;
        while(j < map->width)
        {
            if(map->data[i][j] == 'P')
            {
                engine->player->x = WINDOW_WIDTH / 2 - map->width * 32 + j * 64;
                engine->player->y = WINDOW_HEIGHT / 2 - map->height * 32 + i * 64;
                break;
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
    char * strs[] = {
        "1111111",
        "1111111",
        "1101011",
        "1100011",
        "111P111",
        "1101011",
        "1111111",
        "1111111",
        NULL
    };
    char ** map;

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
    	
    wall_idx(engine->map);
	mlx_do_key_autorepeatoff(render->mlx);
	mlx_hook(render->window, ON_DESTROY, 0, ft_handler_close, &game);
	mlx_hook(render->window, ON_KEYDOWN, 1L << 0, ft_handler_key_press, &game);
	mlx_hook(render->window, ON_KEYUP, 1L << 1, ft_handler_key_release, engine);
	mlx_loop_hook(render->mlx, ft_animation_update, &game);
	mlx_loop(render->mlx);
}
