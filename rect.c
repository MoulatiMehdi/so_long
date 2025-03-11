/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 11:13:32 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/08 13:35:23 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
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

void	ft_rect_attack(t_rect *rect, t_player *player)
{
	rect->width = 48;
	rect->height = 48;
	if (player->way == WAY_DOWN)
	{
		rect->center.x = player->x + 26;
		rect->center.y = player->y + 80;
		rect->width = 48;
		rect->height = 48;
	}
	else if (player->way == WAY_UP)
	{
		rect->center.x = player->x + 26;
		rect->center.y = player->y;
		rect->width = 48;
		rect->height = 48;
	}
	else if (player->way == WAY_LEFT)
		rect->center.x = player->x - 16;
	else if (player->way == WAY_RIGHT)
		rect->center.x = player->x + 64;
	if (player->way == WAY_LEFT || player->way == WAY_RIGHT)
		rect->center.y = player->y + 36;
}

void	ft_rect_spin(t_rect *rect, t_player *player)
{
	rect->center.x = player->x + 24;
	rect->center.y = player->y + 40;
	rect->width = 80;
	rect->height = 80;
}
