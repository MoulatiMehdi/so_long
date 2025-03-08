/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:51:15 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/07 00:16:02 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_engine_enemy_set(t_engine *engine, t_point *p)
{
	int		i;
	t_point	e;

	i = 0;
	while (i < 4)
	{
		e = *p;
		e.x += 2 * (i % 2) - 1;
		e.y += 2 * (i / 2) - 1;
		if (is_valid_point(engine->map, &e)
			&& engine->map->data[e.y][e.x] == WALL_EMPTY)
		{
			engine->enemy.y = e.y * 64 - 32;
			engine->enemy.x = e.x * 64 - 32;
			return ;
		}
	}
}

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
		ft_engine_enemy_set(engine, p);
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
