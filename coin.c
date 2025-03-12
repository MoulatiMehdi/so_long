/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:50:22 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/08 07:59:32 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	ft_engine_coins_update(t_game *game)
{
	t_list		*lst;
	t_coin		*coin;
	t_sprite	*sprite;
	t_engine	*engine;

	engine = game->engine;
	sprite = game->render->sprites[SPRITE_RUPEE];
	lst = engine->coins;
	while (lst)
	{
		coin = lst->content;
		lst = lst->next;
		if (ft_collision_player_coin(engine->player, sprite, coin))
		{
			engine->player->coins++;
			ft_lst_remove(&engine->coins, coin, free);
			engine->exit.is_on = engine->player->coins >= engine->coins_total;
		}
	}
}
