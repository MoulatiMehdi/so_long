#include "so_long.h"

void	ft_debug_rect(t_image *dest, t_image *src, int x, int y, int dest_x,
		int dest_y)
{
	int	width;
	int	height;
	int	color;
	int	i;
	int	j;

	width = 16;
	height = 16;
	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			color = ft_image_getcolor(src, x + i, y + j);
			ft_image_putpixel(dest, dest_x + i, dest_y + j, color);
			j++;
		}
		i++;
	}
}

void	ft_key_conflict(char keys[256])
{
	keys[KEY_W] *= (keys[KEY_W] != keys[KEY_S]);
	keys[KEY_S] *= (keys[KEY_W] != keys[KEY_S]);
	keys[KEY_A] *= (keys[KEY_A] != keys[KEY_D]);
	keys[KEY_D] *= (keys[KEY_A] != keys[KEY_D]);
}

void	ft_key_debug(t_animation *animation)
{
	t_render	*render;
	char		*keys;

	keys = animation->engine->keys;
	render = animation->render;
	if (keys[KEY_D] == 1)
		ft_debug_rect(render->curr, animation->debug, 16 * 0, 0, WINDOW_WIDTH
			- 16 * 5, WINDOW_HEIGHT - 32);
	if (keys[KEY_W] == 1)
		ft_debug_rect(render->curr, animation->debug, 16 * 1, 0, WINDOW_WIDTH
			- 16 * 4, WINDOW_HEIGHT - 32);
	if (keys[KEY_A] == 1)
		ft_debug_rect(render->curr, animation->debug, 16 * 2, 0, WINDOW_WIDTH
			- 16 * 3, WINDOW_HEIGHT - 32);
	if (keys[KEY_S] == 1)
		ft_debug_rect(render->curr, animation->debug, 16 * 3, 0, WINDOW_WIDTH
			- 16 * 2, WINDOW_HEIGHT - 32);
}
