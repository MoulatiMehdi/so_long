#include "image.h"
#include "mlx.h"
#include "so_long.h"
#include <bits/pthreadtypes.h>
#include <unistd.h>

void	draw_rectangle(t_image *img, int x, int y, int color)
{
	int	width;
	int	height;
	int	i;
	int	j;

	width = img->width;
	height = img->height;
	if (x + width > img->width)
		width = img->width - x;
	if (y + height > img->height)
		height = img->height - y;
	i = x;
	while (i < x + width)
	{
        j = y;
		while (j < y + height)
		{
			ft_image_putpixel(img, i, j, color);
			j++;
		}
		i++;
	}
}

int	ft_animation_update(t_animation *animation)
{
	draw_rectangle(animation->render->curr, 0, 0, 0X0000FFFF);
	ft_key_debug(animation);
	ft_key_conflict(animation->engine->keys);
	ft_player_render(animation);
	ft_image_towindow(animation->render->curr, animation->render, 0, 0);
	return (0);
}

int	main(void)
{
	t_animation	animation;
	t_engine	*engine;
	t_render	*render;

	engine = ft_engine_new();
	render = ft_render_new(engine->mlx, engine->window);
	animation.square = ft_image_from_xpm(engine->mlx,
			"/home/mehdi/shared/hero-walking-export.xpm");
	animation.debug = ft_image_from_xpm(engine->mlx,
			"/home/mehdi/shared/debug_commands.xpm");
	animation.render = render;
	animation.engine = engine;
	mlx_loop_hook(engine->mlx, ft_animation_update, &animation);
	mlx_loop(engine->mlx);
}
