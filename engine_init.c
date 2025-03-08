/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:51:15 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/08 11:41:57 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_engine_setdata(t_engine *engine, t_point *p)
{
	char	c;
	t_coin	*coin;

	c = engine->map->data[p->y][p->x];
	if (c == 'P')
	{
		engine->player->x = p->x * 64 + 8;
		engine->player->y = p->y * 64 - 8;
	}
	if (c == 'E')
	{
		engine->exit.x = p->x * 64;
		engine->exit.y = p->y * 64;
		engine->exit.is_on = false;
		engine->exit.type = 1;
		engine->enemy.y = engine->exit.x;
		engine->enemy.x = engine->exit.y;
	}
	if (c == 'C')
	{
		coin = ft_coin_new(p->x * 64 + 24, p->y * 64 + 16);
		ft_lstadd_front(&engine->coins, ft_lstnew(coin));
		engine->coins_total++;
	}
}

void	ft_engine_getdata(t_engine *engine)
{
	t_point	p;
	t_map	*map;

	map = engine->map;
	if (map == NULL)
		return ;
	p.y = 0;
	while (p.y < map->height)
	{
		p.x = 0;
		while (p.x < map->width)
		{
			ft_engine_setdata(engine, &p);
			p.x++;
		}
		p.y++;
	}
}

void	engine_parse(t_engine *engine)
{
	ft_engine_getdata(engine);
	ft_wall_parse(engine->map);
}
