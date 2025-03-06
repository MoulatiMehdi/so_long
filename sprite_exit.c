#include "so_long.h"

void	ft_render_exit(t_exit *door, t_render *render)
{
	static int	n = 0;
	t_sprite	*sprite;
	t_point		point;

	sprite = render->sprites[SPRITE_EXIT];
	sprite->x = sprite->frame_width * (n / sprite->loop);
	sprite->y = sprite->frame_height * door->type;
	point.x = door->x - render->camera.x + 16;
	point.y = door->y - render->camera.y + 16;
	ft_render_sprite(render, sprite, &point);
	if (!door->is_on)
		n = 3 * sprite->loop;
	else
		n = (n + 1) % ((sprite->col - 1) * sprite->loop);
}
