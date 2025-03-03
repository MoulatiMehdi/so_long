#include "image.h"
#include "libft/libft.h"
#include "player.h"
#include "so_long.h"
#include <mlx.h>

int		ft_handler_close(t_animation *animation);
int		ft_handler_key_press(int keycode, t_animation *animation);
int		ft_handler_key_release(int keycode, t_engine *engine);

void	draw_react(t_render *image, t_player *player, t_color color)
{
	int	j;
	int	x;
	int	y;

	x = player->x - player->width / 2 + player->origin_x;
	y = player->y - player->height / 2 + player->origin_y;
	j = 0;
	while (j < player->width)
	{
		ft_image_putpixel(image->back, x + j, y, color);
		j++;
	}
	j = 0;
	while (j < player->height)
	{
		ft_image_putpixel(image->back, x, y + j, color);
		ft_image_putpixel(image->back, x + player->width - 1, y + j, color);
		j++;
	}
	j = 0;
	while (j < player->width)
	{
		ft_image_putpixel(image->back, x + j, y + player->height - 1, color);
		j++;
	}
}

int	ft_animation_update(t_animation *animation)
{
	if (animation->render->stop)
		return (0);
	ft_image_fill(animation->render->back, 0X00FFFFFF);
	ft_map_display(animation->render, animation->engine->map);
	ft_image_grid(animation->render->back, 64, 64, 0X00FF0000);
	ft_player_render(animation);
	draw_react(animation->render, animation->engine->player, 0X00FF0000);
	// ft_player_debug(animation->engine->player);
	ft_hearts_render(animation);
	ft_coin_render(animation);
	ft_counter_render(animation);
	ft_key_debug(animation);
	ft_render_display(animation->render);
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
				player->x = WINDOW_WIDTH / 2 - map->width * 32 + j * 64 + 8;
				player->y = WINDOW_HEIGHT / 2 - map->height * 32 + i * 64 - 8;
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
		"11111111",
		"11111111",
		"111P1111",
		"11111111",
		"11110111",
		"11111111",
		"11011111",
		"11111111",
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
	ft_engine_player_coord(engine);
	wall_idx(engine->map);
	mlx_do_key_autorepeatoff(render->mlx);
	mlx_hook(render->window, ON_DESTROY, 0, ft_handler_close, &game);
	mlx_hook(render->window, ON_KEYDOWN, 1L << 0, ft_handler_key_press, &game);
	mlx_hook(render->window, ON_KEYUP, 1L << 1, ft_handler_key_release, engine);
	mlx_loop_hook(render->mlx, ft_animation_update, &game);
	mlx_loop(render->mlx);
}
