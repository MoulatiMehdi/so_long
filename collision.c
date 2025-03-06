/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:55:42 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/06 20:42:36 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	ft_rect_iscollide(t_rect *a, t_rect *b)
{
	t_point	pb[2];
	t_point	pa[2];

	pa[0].x = a->center.x - a->width / 2;
	pa[0].y = a->center.y - a->height / 2;
	pa[1].x = a->center.x + a->width / 2;
	pa[1].y = a->center.y + a->height / 2;
	pb[0].x = b->center.x - b->width / 2;
	pb[0].y = b->center.y - b->height / 2;
	pb[1].x = b->center.x + b->width / 2;
	pb[1].y = b->center.y + b->height / 2;
	return (!(pb[0].x > pa[1].x || pb[1].x < pa[0].x || pb[0].y > pa[1].y
			|| pb[1].y < pa[0].y));
}

bool	ft_collision_player_coin(t_player *player, t_sprite *sprite,
		t_coin *coin)
{
	t_rect	p;
	t_rect	c;

	p.center.x = player->x + player->origin_x;
	p.center.y = player->y + player->origin_y;
	p.width = player->width;
	p.height = player->height;
	c.center.x = coin->x + sprite->frame_width / 2;
	c.center.y = coin->y + sprite->frame_height / 2;
	c.width = sprite->frame_width;
	c.height = sprite->frame_height;
	return (ft_rect_iscollide(&p, &c));
}

bool	ft_collision_player_door(t_player *player, t_sprite *sprite,
		t_exit *door)
{
	t_rect	p;
	t_rect	c;

	p.center.x = player->x + player->origin_x;
	p.center.y = player->y + player->origin_y;
	p.width = player->width;
	p.height = player->height;
	c.center.x = door->x + sprite->frame_width;
	c.center.y = door->y + sprite->frame_height;
	c.width = sprite->frame_width / 2;
	c.height = sprite->frame_height / 2;
	return (ft_rect_iscollide(&p, &c));
}
