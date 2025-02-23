#include "player.h"
#include "so_long.h"

void	ft_player_star_position(t_player *player, t_point *point)
{
	if (player->way == WAY_LEFT)
	{
		point->x = player->x - 24;
		point->y = player->y + 32;
	}
	if (player->way == WAY_RIGHT)
	{
		point->x = player->x + 28;
		point->y = player->y + 32;
	}
	if (player->way == WAY_DOWN)
	{
		point->x = player->x + 12;
		point->y = player->y + 46;
	}
	if (player->way == WAY_UP)
	{
		point->x = player->x + 8;
		point->y = player->y - 12;
	}
}

void	ft_player_star(t_player *player, t_render *render)
{
	t_sprite	*sprite;
	t_point		point;
	bool		is_h;

	is_h = player->way == WAY_LEFT || player->way == WAY_RIGHT;
	ft_player_star_position(player, &point);
	if (is_h)
		sprite = render->sprites[SPRITE_STAR_LOADING_V];
	else
		sprite = render->sprites[SPRITE_STAR_LOADING_H];
	if (player->is_loaded && player->frame_on_loop >= sprite->loop
		* (sprite->col * (sprite->row / 2) - is_h))
		player->frame_on_loop = 32 * sprite->loop;
	sprite->x = sprite->frame_width * ((player->frame_on_loop / sprite->loop)
			% sprite->col);
	sprite->y = sprite->frame_height * ((player->frame_on_loop / (sprite->loop
					* sprite->col)) % (sprite->row / 2));
	if (player->way == WAY_LEFT || player->way == WAY_DOWN)
		sprite->y += sprite->frame_height * (sprite->row / 2);
	ft_render_sprite(render, sprite, &point);
}

void	ft_player_loading(t_player *player, t_render *render)
{
	t_sprite	*sprite_link;
	t_sprite	*sprite_sword;
	t_point		point;

	sprite_sword = ft_sprite_coor_way(player, render, SPRITE_SWORD_LOADING);
	sprite_link = ft_sprite_coor_way(player, render, SPRITE_LINK_LOADING);
	if (!player->is_moving)
	{
		sprite_sword->x = 0;
		sprite_link->x = 0;
	}
	if (19 * sprite_link->loop > player->charge)
	{
		player->charge++;
		player->is_loaded = false;
	}
	else
		player->is_loaded = true;
	point.x = player->x - 16;
	point.y = player->y + 4;
	ft_render_sprite(render, sprite_sword, &point);
	point.x = player->x;
	point.y = player->y;
	ft_render_sprite(render, sprite_link, &point);
	ft_player_star(player, render);
}

void	ft_player_attack(t_player *player, t_render *render)
{
	t_sprite	*sprite;
	t_sprite	*sprite_sword;
	t_point		point;

	sprite = ft_sprite_coor_way(player, render, SPRITE_LINK_ATTACKING);
	sprite_sword = ft_sprite_coor_way(player, render, SPRITE_SWORD_ATTACK);
	point.x = player->x - 8;
	point.y = player->y;
	ft_render_sprite(render, sprite, &point);
	point.x = player->x - 48;
	point.y = player->y - 28;
	ft_render_sprite(render, sprite_sword, &point);
	if (player->frame_on_loop == sprite->col * sprite->loop - 1)
		player->is_state_fixed = false;
}

void	ft_player_spinning(t_player *player, t_render *render)
{
	t_sprite	*sprite_spin;
	t_sprite	*sprite_sword;
	t_point		point;

	sprite_spin = ft_sprite_coor_way(player, render, SPRITE_LINK_SPIN);
	sprite_sword = ft_sprite_coor_way(player, render, SPRITE_SWORD_SPIN);
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
}
