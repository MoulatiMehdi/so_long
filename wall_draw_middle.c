#include "so_long.h"

void	ft_map_middle_top(t_render *render, t_point *point)
{
	t_sprite	*sprite;

	sprite = render->sprites[SPRITE_WALL];
	sprite->y = sprite->frame_height * 1;
	sprite->x = sprite->frame_width * 3;
	ft_render_sprite(render, sprite, point);
}

void	ft_map_middle_bottom(t_render *render, t_point *point)
{
	t_sprite	*sprite;

	sprite = render->sprites[SPRITE_WALL];
	sprite->y = sprite->frame_height * 1;
	sprite->x = sprite->frame_width * 1;
	ft_render_sprite(render, sprite, point);
}

void	ft_map_middle_left(t_render *render, t_point *point)
{
	t_sprite	*sprite;

	sprite = render->sprites[SPRITE_WALL];
	sprite->y = sprite->frame_height * 1;
	sprite->x = sprite->frame_width * 0;
	ft_render_sprite(render, sprite, point);
}

void	ft_map_middle_right(t_render *render, t_point *point)
{
	t_sprite	*sprite;

	sprite = render->sprites[SPRITE_WALL];
	sprite->y = sprite->frame_height * 1;
	sprite->x = sprite->frame_width * 2;
	ft_render_sprite(render, sprite, point);
}
