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
	if (animation->engine->keys['p'] == 1)
		animation->engine->player->hearts = 0;
	if (animation->engine->keys['v'] == 1)
	{
		animation->engine->player->state = STATE_VICTORY;
	}
	ft_player_render(animation);
	ft_player_debug(animation->engine->player);
	ft_hearts_render(animation);
	ft_coin_render(animation);
	ft_counter_render(animation);
	ft_key_debug(animation);
	ft_render_display(animation->render);
	return (0);
}

int	ft_handler_close(t_animation *animation);
int	ft_handler_key_press(int keycode, t_animation *animation);
int	ft_handler_key_release(int keycode, t_engine *engine);

int	main(void)
{
	t_animation	game;
	t_engine	*engine;
	t_render	*render;

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
	mlx_do_key_autorepeatoff(render->mlx);
	mlx_hook(render->window, ON_DESTROY, 0, ft_handler_close, &game);
	mlx_hook(render->window, ON_KEYDOWN, 1L << 0, ft_handler_key_press, &game);
	mlx_hook(render->window, ON_KEYUP, 1L << 1, ft_handler_key_release, engine);
	mlx_loop_hook(render->mlx, ft_animation_update, &game);
	mlx_loop(render->mlx);
}
