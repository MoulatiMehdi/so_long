/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:50:22 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/05 19:25:54 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

t_coin	*ft_coin_new(int x, int y)
{
	t_coin	*coin;

	coin = ft_calloc(sizeof(t_coin), 1);
	if (coin == NULL)
		return (NULL);
	coin->x = x;
	coin->y = y;
	coin->type = rand() % 3;
	return (coin);
}

bool	ft_player_coin_iscollide(t_player *player, t_sprite *sprite,
		t_coin *coin)
{
	t_point	player_lt;
	t_point	player_br;
	t_point	coin_lt;
	t_point	coin_br;

	player_lt.x = player->x + player->origin_x - player->width / 2;
	player_lt.y = player->y + player->origin_y - player->height / 2;
	player_br.x = player->x + player->origin_x + player->width / 2;
	player_br.y = player->y + player->origin_y + player->height / 2;
	coin_lt.x = coin->x;
	coin_lt.y = coin->y;
	coin_br.x = coin->x + sprite->frame_width / 1;
	coin_br.y = coin->y + sprite->frame_height / 1;
	return (!(player_lt.x > coin_br.x || player_br.x < coin_lt.x
			|| player_lt.y > coin_br.y || player_br.y < coin_lt.y));
}

void	ft_coin_update(t_animation *animation)
{
	t_list		*lst;
	t_coin		*coin;
	t_sprite	*sprite;

	sprite = animation->render->sprites[SPRITE_RUPEE];
	lst = animation->engine->coins;
	while (lst)
	{
		coin = lst->content;
		lst = lst->next;
		if (ft_player_coin_iscollide(animation->engine->player, sprite, coin))
		{
			animation->engine->player->coins++;
			ft_lst_remove(&animation->engine->coins, coin, free);
		}
	}
}
