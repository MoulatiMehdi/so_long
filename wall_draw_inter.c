#include "so_long.h"

void	ft_map_inter_diagonal(t_render *render, t_point *point)
{
	t_sprite	*sprite;

	sprite = render->sprites[SPRITE_WALL];
	sprite->x = sprite->frame_width * 0;
	sprite->y = sprite->frame_height * 3;
	ft_render_sprite(render, sprite, point);
}

void	ft_map_inter_antidiagonal(t_render *render, t_point *point)
{
	t_sprite	*sprite;

	sprite = render->sprites[SPRITE_WALL];
	sprite->x = sprite->frame_width * 1;
	sprite->y = sprite->frame_height * 3;
	ft_render_sprite(render, sprite, point);
}
