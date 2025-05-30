/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_player_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:32:37 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/08 12:30:38 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player_idle(t_player *player, t_render *render)
{
	t_sprite	*sprite;
	t_point		point;

	ft_camera_player_center(render, player, &point);
	sprite = render->sprites[SPRITE_LINK_IDLE];
	sprite->x = 0;
	sprite->y = sprite->frame_height * player->way;
	ft_render_sprite(render, sprite, &point);
}

void	ft_player_walking(t_player *player, t_render *render)
{
	t_sprite	*sprite;
	t_point		point;

	ft_camera_player_center(render, player, &point);
	sprite = ft_sprite_coor_way(player, render, SPRITE_LINK_WALKING);
	ft_render_sprite(render, sprite, &point);
}

void	ft_player_victory(t_player *player, t_render *render)
{
	static unsigned int	n = 0;
	t_sprite			*sprite_player;
	t_sprite			*sprite_sword;
	t_point				point;

	sprite_sword = render->sprites[SPRITE_SWORD_VICTORY];
	sprite_player = render->sprites[SPRITE_LINK_VICTORY];
	ft_camera_player_center(render, player, &point);
	point.x -= 40;
	point.y -= 20;
	sprite_sword->x = sprite_sword->frame_width * ((n / sprite_sword->loop)
			% sprite_sword->col);
	sprite_sword->y = sprite_sword->frame_height * ((n / (sprite_sword->loop
					* sprite_sword->col)) % sprite_sword->row);
	ft_render_sprite(render, sprite_sword, &point);
	ft_camera_player_center(render, player, &point);
	sprite_player->x = sprite_player->frame_width * (n / sprite_player->loop);
	sprite_player->y = 0;
	ft_render_sprite(render, sprite_player, &point);
	if (n < (sprite_player->col * sprite_player->loop - 1))
		n++;
}
