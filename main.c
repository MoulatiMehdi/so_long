#include "image.h"
#include "mlx.h"
#include "player.h"
#include "so_long.h"
#include <stdio.h>

int	ft_animation_update(t_animation *animation)
{
	if (animation->render->stop)
		return (0);
	ft_image_fill(animation->render->back, 0X0000FF00);
	if (animation->engine->keys['p'] == 1)
		animation->engine->player->hearts = 0;
    ft_player_render(animation);
	ft_player_debug(animation->engine->player);
	/*ft_hearts_render(animation);*/
	/*ft_coin_render(animation);*/
	/*ft_counter_render(animation);*/
    ft_key_debug(animation);
	ft_render_display(animation->render);
    return (0);
}

int	main(void)
{
	t_animation	animation;
	t_engine	*engine;
	t_render	*render;

	engine = ft_engine_new();
	render = ft_render_new(engine->mlx, engine->window);
	animation.render = render;
	animation.engine = engine;
	mlx_loop_hook(engine->mlx, ft_animation_update, &animation);
	mlx_loop(engine->mlx);
}
