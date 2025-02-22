#include "so_long.h"

void	ft_player_attack(t_player *player, t_render *render)
{
	t_sprite	*sprite;
	t_sprite	*sprite_sword;
	t_point		point;

	sprite = render->sprites[SPRITE_LINK_ATTACKING];
	sprite_sword = render->sprites[SPRITE_SWORD_ATTACK];
	sprite->x = sprite->frame_width * (player->frame_on_loop / sprite->loop);
	sprite->y = sprite->frame_height * player->way;
	sprite_sword->x = sprite_sword->frame_width * (player->frame_on_loop
			/ sprite_sword->loop);
	sprite_sword->y = sprite_sword->frame_height * player->way;
	point.x = player->x - 8;
	point.y = player->y;
	ft_render_sprite(render, sprite, &point);
	point.x = player->x - 48;
	point.y = player->y - 28;
	ft_render_sprite(render, sprite_sword, &point);
	if (player->frame_on_loop == sprite->col * sprite->loop - 1)
		player->is_state_fixed = false;
	player->frame_on_loop = (player->frame_on_loop + 1) % (sprite->col
			* sprite->loop);
}

void	ft_player_spinning(t_player *player, t_render *render)
{
	t_sprite	*sprite_spin;
	t_sprite	*sprite_sword;
	t_point		point;

	sprite_spin = render->sprites[SPRITE_LINK_SPIN];
	sprite_sword = render->sprites[SPRITE_SWORD_SPIN];
	sprite_spin->y = sprite_spin->frame_height * player->way;
	sprite_sword->y = sprite_sword->frame_height * player->way;
	sprite_spin->x = sprite_spin->frame_width * (player->frame_on_loop
			/ sprite_spin->loop);
	sprite_sword->x = sprite_sword->frame_width * (player->frame_on_loop
			/ sprite_sword->loop);
	point.x = player->x;
	point.y = player->y + 16;
	ft_render_sprite(render, sprite_spin, &point);
	point.x = player->x - 40;
	point.y = player->y - 20;
	ft_render_sprite(render, sprite_sword, &point);
	if (player->frame_on_loop + 1 == sprite_sword->col * sprite_spin->loop)
	{
		player->is_state_fixed = false;
		player->is_loaded = false;
	}
	player->frame_on_loop = (player->frame_on_loop + 1) % (sprite_sword->col
			* sprite_sword->loop);
}

void	ft_player_loading(t_player *player, t_render *render)
{
	t_sprite	*sprite_link;
	t_sprite	*sprite_sword;
	t_point		point;

	sprite_link = render->sprites[SPRITE_LINK_LOADING];
	sprite_sword = render->sprites[SPRITE_SWORD_LOADING];
	sprite_link->x = sprite_link->frame_width * (player->frame_on_loop
			/ sprite_link->loop);
	sprite_link->y = sprite_link->frame_height * player->way;
	sprite_sword->x = sprite_sword->frame_width * (player->frame_on_loop
			/ sprite_sword->loop);
	sprite_sword->y = sprite_sword->frame_height * player->way;
	if (!player->is_moving)
	{
		sprite_sword->x = 0;
		sprite_link->x = 0;
		player->frame_on_loop = 0;
	}
	if (sprite_link->col * sprite_link->loop * 10 > player->charge)
		player->charge++;
	else
		player->is_loaded = true;
	point.x = player->x - 16;
	point.y = player->y + 4;
	ft_render_sprite(render, sprite_sword, &point);
	point.x = player->x;
	point.y = player->y;
	ft_render_sprite(render, sprite_link, &point);
	player->frame_on_loop = (player->frame_on_loop + 1) % (sprite_link->col
			* sprite_link->loop);
}
