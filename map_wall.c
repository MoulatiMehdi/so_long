/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:32:31 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/03 21:31:52 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "wall.h"
#include <stdbool.h>

void	ft_map_fill(t_render *render)
{
	t_point	point;

	point.y = 0;
	while (point.y < WINDOW_HEIGHT)
	{
		point.x = 0;
		while (point.x < WINDOW_WIDTH)
		{
			ft_map_roof(render, &point);
			point.x += 64;
		}
		point.y += 64;
	}
}

void	ft_map_wall(t_render *render, t_map *map)
{
	t_point	idx;
	t_point	count;
	t_point	shift;

	count.x = -1;
	while (count.x <= WINDOW_WIDTH / 64)
	{
		count.y = -1;
		while (count.y <= WINDOW_HEIGHT / 64)
		{
			idx.x = count.x + render->camera.x / 64;
			idx.y = count.y + render->camera.y / 64;
			if (!is_valid_point(map, &idx))
			{
				count.y++;
				continue ;
			}
			shift.x = count.x * 64 - render->camera.x % 64;
			shift.y = count.y * 64 - render->camera.y % 64;
			ft_wall_tile(render, map, &shift, &idx);
			count.y++;
		}
		count.x++;
	}
}

void	ft_render_map(t_render *render, t_map *map)
{
	if (map->width * 64 > WINDOW_WIDTH || map->height * 64 > WINDOW_HEIGHT)
		ft_map_fill(render);
	ft_map_wall(render, map);
}
