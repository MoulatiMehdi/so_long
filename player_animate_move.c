#include "so_long.h"

void	ft_player_idle(t_player *player, t_render *render)
{
	t_sprite	*sprite;
	t_point		point;

	point.x = player->x;
	point.y = player->y;
	sprite = render->sprites[SPRITE_LINK_IDLE];
	sprite->x = 0;
	sprite->y = sprite->frame_height * player->way;
	ft_render_sprite(render, sprite, &point);
}

void	ft_player_walking(t_player *player, t_render *render)
{
	t_sprite	*sprite;
	t_point		point;

	point.x = player->x;
	point.y = player->y;
	sprite = render->sprites[SPRITE_LINK_WALKING];
	sprite->x = sprite->frame_width * (player->frame_on_loop / sprite->loop);
	sprite->y = sprite->frame_height * player->way;
	ft_render_sprite(render, sprite, &point);
	player->frame_on_loop = (player->frame_on_loop + 1) % (sprite->col
			* sprite->loop);
}

void	ft_player_victory(t_player *player, t_render *render)
{
	static unsigned int	n = 0;
	t_sprite			*sprite;
	t_point				point;

	point.x = player->x;
	point.y = player->y;
	sprite = render->sprites[SPRITE_LINK_VICTORY];
	sprite->x = 0;
	sprite->y = sprite->frame_width * (n / sprite->loop);
	ft_render_sprite(render, sprite, &point);
	if (n < (sprite->col * sprite->loop - 1))
		n++;
}
