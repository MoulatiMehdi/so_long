/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:50:22 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/04 19:54:18 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

t_coin	*ft_coin_new(int x, int y)
{
	t_coin	*coin;

	coin = ft_calloc(sizeof(t_coin), 1);
	if (coin == NULL)
		return (NULL);
	coin->x = x;
	coin->y = y;
	return (coin);
}

bool	ft_collision_player_point(t_player *player, t_point *p)
{
	t_point	min;
	t_point	max;

	min.x = player->x + player->origin_x - player->width / 2;
	min.y = player->y + player->origin_y - player->height / 2;
	max.x = player->x + player->origin_x + player->width / 2;
	max.y = player->y + player->origin_y + player->height / 2;
	if (min.x > p->x || max.x < p->x)
		return (false);
	if (min.y > p->y || max.y < p->y)
		return (false);
	return (true);
}

bool	ft_player_coin_iscollide(t_player *player, t_sprite *sprite, t_coin *p)
{
	t_point	point;

	point.x = p->x;
	point.y = p->y;
	if (ft_collision_player_point(player, &point))
		return (true);
	point.x = p->x + sprite->frame_width;
	point.y = p->y + sprite->frame_height;
	if (ft_collision_player_point(player, &point))
		return (true);
	point.x = p->x + sprite->frame_width;
	point.y = p->y;
	if (ft_collision_player_point(player, &point))
		return (true);
	point.x = p->x;
	point.y = p->y + sprite->frame_height;
	if (ft_collision_player_point(player, &point))
		return (true);
	return (false);
}

void	ft_coin_update(t_animation *animation)
{
	t_list		*lst;
	t_coin		*coin;
	t_sprite	*sprite;
	static int	n = 0;

	sprite = animation->render->sprites[SPRITE_RUPEE];
	lst = animation->engine->coins;
	while (lst)
	{
		coin = lst->content;
		if (ft_player_coin_iscollide(animation->engine->player, sprite, coin))
		{
			animation->engine->player->coins++;
			n++;
		}
		lst = lst->next;
	}
}

void	ft_coin_destroy(t_coin *coin)
{
	free(coin);
}
