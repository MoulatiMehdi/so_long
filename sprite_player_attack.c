/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animate_attack.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:32:34 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/03 17:32:34 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "so_long.h"

void	ft_player_star_position(t_render *render, t_player *player,
		t_point *point)
{
	ft_camera_player_center(render, player, point);
	if (player->way == WAY_LEFT)
	{
		point->x += -24;
		point->y += +32;
	}
	if (player->way == WAY_RIGHT)
	{
		point->x += +28;
		point->y += +32;
	}
	if (player->way == WAY_DOWN)
	{
		point->x += +12;
		point->y += +46;
	}
	if (player->way == WAY_UP)
	{
		point->x += +8;
		point->y += -12;
	}
}

void	ft_player_star(t_player *player, t_render *render)
{
	t_sprite	*sprite;
	t_point		point;
	bool		is_h;

	is_h = player->way == WAY_LEFT || player->way == WAY_RIGHT;
	ft_player_star_position(render, player, &point);
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
	ft_camera_player_center(render, player, &point);
	point.x += -16;
	point.y += 4;
	ft_render_sprite(render, sprite_sword, &point);
	ft_camera_player_center(render, player, &point);
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
	ft_camera_player_center(render, player, &point);
	point.x += -8;
	ft_render_sprite(render, sprite, &point);
	ft_camera_player_center(render, player, &point);
	point.x += -48;
	point.y += -28;
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
	ft_camera_player_center(render, player, &point);
	point.y += +16;
	ft_render_sprite(render, sprite_spin, &point);
	ft_camera_player_center(render, player, &point);
	point.x += -40;
	point.y += -20;
	ft_render_sprite(render, sprite_sword, &point);
	if (player->frame_on_loop + 1 == sprite_sword->col * sprite_spin->loop)
	{
		player->is_state_fixed = false;
		player->is_loaded = false;
	}
}
