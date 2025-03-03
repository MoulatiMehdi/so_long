/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:32:31 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/03 17:48:14 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "wall.h"

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
			if (map->data[idx.y][idx.x] == WALL_EMPTY)
				ft_map_floor_blue(render, &shift);
			else if (map->data[idx.y][idx.x] == WALL_ROOF)
				ft_map_roof(render, &shift);
			else if (map->data[idx.y][idx.x] == WALL_IN_MID_TOP)
				ft_map_middle_top(render, &shift);
			else if (map->data[idx.y][idx.x] == WALL_IN_MID_BOTTOM)
				ft_map_middle_bottom(render, &shift);
			else if (map->data[idx.y][idx.x] == WALL_IN_MID_LEFT)
				ft_map_middle_left(render, &shift);
			else if (map->data[idx.y][idx.x] == WALL_IN_MID_RIGHT)
				ft_map_middle_right(render, &shift);
			else if (map->data[idx.y][idx.x] == WALL_IN_LEFT_TOP)
				ft_map_wall_left_top(render, &shift);
			else if (map->data[idx.y][idx.x] == WALL_IN_LEFT_BOTTOM)
				ft_map_wall_left_bottom(render, &shift);
			else if (map->data[idx.y][idx.x] == WALL_IN_RIGHT_BOTTOM)
				ft_map_wall_right_bottom(render, &shift);
			else if (map->data[idx.y][idx.x] == WALL_IN_RIGHT_TOP)
				ft_map_wall_right_top(render, &shift);
			else if (map->data[idx.y][idx.x] == WALL_OUT_LEFT_TOP)
				ft_map_outside_left_top(render, &shift);
			else if (map->data[idx.y][idx.x] == WALL_OUT_LEFT_BOTTOM)
				ft_map_outside_left_bottom(render, &shift);
			else if (map->data[idx.y][idx.x] == WALL_OUT_RIGHT_BOTTOM)
				ft_map_outside_right_bottom(render, &shift);
			else if (map->data[idx.y][idx.x] == WALL_OUT_RIGHT_TOP)
				ft_map_outside_right_top(render, &shift);
			else if (map->data[idx.y][idx.x] == WALL_INTER_ANTIDIAGONAL)
				ft_map_inter_antidiagonal(render, &shift);
			else if (map->data[idx.y][idx.x] == WALL_INTER_DIAGONAL)
				ft_map_inter_diagonal(render, &shift);
			else if (map->data[idx.y][idx.x] == WALL_OBSTACLE)
				ft_map_obstacle(render, &shift);
			count.y++;
		}
		count.x++;
	}
}

void	ft_map_display(t_render *render, t_map *map)
{
	if (map->width * 64 > WINDOW_WIDTH || map->height * 64 > WINDOW_HEIGHT)
		ft_map_fill(render);
	ft_map_wall(render, map);
}
