/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall_tile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:52:39 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/03 21:52:39 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wall.h"

bool	ft_wall_middle(t_render *render, t_map *map, t_point *shift,
		t_point *idx)
{
	if (map->data[idx->y][idx->x] == WALL_IN_MID_TOP)
	{
		ft_map_middle_top(render, shift);
		return (true);
	}
	if (map->data[idx->y][idx->x] == WALL_IN_MID_BOTTOM)
	{
		ft_map_middle_bottom(render, shift);
		return (true);
	}
	if (map->data[idx->y][idx->x] == WALL_IN_MID_LEFT)
	{
		ft_map_middle_left(render, shift);
		return (true);
	}
	if (map->data[idx->y][idx->x] == WALL_IN_MID_RIGHT)
	{
		ft_map_middle_right(render, shift);
		return (true);
	}
	return (false);
}

bool	ft_wall_inside(t_render *render, t_map *map, t_point *shift,
		t_point *idx)
{
	if (map->data[idx->y][idx->x] == WALL_IN_LEFT_TOP)
	{
		ft_map_wall_left_top(render, shift);
		return (true);
	}
	else if (map->data[idx->y][idx->x] == WALL_IN_LEFT_BOTTOM)
	{
		ft_map_wall_left_bottom(render, shift);
		return (true);
	}
	else if (map->data[idx->y][idx->x] == WALL_IN_RIGHT_BOTTOM)
	{
		ft_map_wall_right_bottom(render, shift);
		return (true);
	}
	else if (map->data[idx->y][idx->x] == WALL_IN_RIGHT_TOP)
	{
		ft_map_wall_right_top(render, shift);
		return (true);
	}
	return (false);
}

bool	ft_wall_outside(t_render *render, t_map *map, t_point *shift,
		t_point *idx)
{
	if (map->data[idx->y][idx->x] == WALL_OUT_LEFT_TOP)
	{
		ft_map_outside_left_top(render, shift);
		return (true);
	}
	else if (map->data[idx->y][idx->x] == WALL_OUT_LEFT_BOTTOM)
	{
		ft_map_outside_left_bottom(render, shift);
		return (true);
	}
	else if (map->data[idx->y][idx->x] == WALL_OUT_RIGHT_BOTTOM)
	{
		ft_map_outside_right_bottom(render, shift);
		return (true);
	}
	else if (map->data[idx->y][idx->x] == WALL_OUT_RIGHT_TOP)
	{
		ft_map_outside_right_top(render, shift);
		return (true);
	}
	return (false);
}

void	ft_wall_tile(t_render *render, t_map *map, t_point *shift, t_point *idx)
{
	if (map->data[idx->y][idx->x] == WALL_EMPTY)
		ft_map_floor_blue(render, shift);
	else if (map->data[idx->y][idx->x] == WALL_ROOF)
		ft_map_roof(render, shift);
	else if (ft_wall_middle(render, map, shift, idx))
		;
	else if (ft_wall_inside(render, map, shift, idx))
		;
	else if (ft_wall_outside(render, map, shift, idx))
		;
	else if (map->data[idx->y][idx->x] == WALL_INTER_ANTIDIAGONAL)
		ft_map_inter_antidiagonal(render, shift);
	else if (map->data[idx->y][idx->x] == WALL_INTER_DIAGONAL)
		ft_map_inter_diagonal(render, shift);
	else if (map->data[idx->y][idx->x] == WALL_OBSTACLE)
		ft_map_obstacle(render, shift);
}
