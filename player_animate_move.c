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
	sprite = ft_sprite_coor_way(player, render, SPRITE_LINK_WALKING);
	ft_render_sprite(render, sprite, &point);
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
