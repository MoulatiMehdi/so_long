#include "so_long.h"

void	ft_map_outside_left_top(t_render *render, t_point *point)
{
	t_sprite	*sprite;

	sprite = render->sprites[SPRITE_WALL];
	sprite->x = sprite->frame_width * 0;
	sprite->y = sprite->frame_height * 2;
	ft_render_sprite(render, sprite, point);
}

void	ft_map_outside_left_bottom(t_render *render, t_point *point)
{
	t_sprite	*sprite;

	sprite = render->sprites[SPRITE_WALL];
	sprite->x = sprite->frame_width * 1;
	sprite->y = sprite->frame_height * 2;
	ft_render_sprite(render, sprite, point);
}

void	ft_map_outside_right_bottom(t_render *render, t_point *point)
{
	t_sprite	*sprite;

	sprite = render->sprites[SPRITE_WALL];
	sprite->x = sprite->frame_width * 3;
	sprite->y = sprite->frame_height * 2;
	ft_render_sprite(render, sprite, point);
}

void	ft_map_outside_right_top(t_render *render, t_point *point)
{
	t_sprite	*sprite;

	sprite = render->sprites[SPRITE_WALL];
	sprite->x = sprite->frame_width * 2;
	sprite->y = sprite->frame_height * 2;
	ft_render_sprite(render, sprite, point);
}
