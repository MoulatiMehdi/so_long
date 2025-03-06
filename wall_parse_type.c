/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_idx_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:14:59 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/03 22:14:59 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wall.h"

bool	ft_is_roof_touch(t_map *map, t_point *point)
{
	int		i;
	int		j;
	bool	istrue;
	t_point	p;

	istrue = false;
	i = -1;
	while (i < 2)
	{
		j = -1;
		while (j < 2)
		{
			p.x = point->x + i;
			p.y = point->y + j;
			if (is_valid_point(map, &p))
			{
				istrue = istrue || ft_wall_isroof(map, &p);
			}
			else
				return (true);
			j++;
		}
		i++;
	}
	return (istrue);
}

bool	ft_wall_ismiddle(t_map *map, t_point *p, char **strs)
{
	if (ft_wall_ismiddle_top(map, p))
	{
		strs[p->y][p->x] = WALL_IN_MID_TOP;
		return (true);
	}
	else if (ft_wall_ismiddle_right(map, p))
	{
		strs[p->y][p->x] = WALL_IN_MID_RIGHT;
		return (true);
	}
	else if (ft_wall_ismiddle_bottom(map, p))
	{
		strs[p->y][p->x] = WALL_IN_MID_BOTTOM;
		return (true);
	}
	else if (ft_wall_ismiddle_left(map, p))
	{
		strs[p->y][p->x] = WALL_IN_MID_LEFT;
		return (true);
	}
	return (false);
}

bool	ft_wall_isinside(t_map *map, t_point *p, char **strs)
{
	if (ft_wall_isleft_top(map, p))
	{
		strs[p->y][p->x] = WALL_IN_LEFT_TOP;
		return (true);
	}
	else if (ft_wall_isright_top(map, p))
	{
		strs[p->y][p->x] = WALL_IN_RIGHT_TOP;
		return (true);
	}
	else if (ft_wall_isright_bottom(map, p))
	{
		strs[p->y][p->x] = WALL_IN_RIGHT_BOTTOM;
		return (true);
	}
	else if (ft_wall_isleft_bottom(map, p))
	{
		strs[p->y][p->x] = WALL_IN_LEFT_BOTTOM;
		return (true);
	}
	return (false);
}

bool	ft_wall_isoutside(t_map *map, t_point *p, char **strs)
{
	if (ft_wall_outside_isright_bottom(map, p))
	{
		strs[p->y][p->x] = WALL_OUT_RIGHT_BOTTOM;
		return (true);
	}
	else if (ft_wall_outside_isright_top(map, p))
	{
		strs[p->y][p->x] = WALL_OUT_RIGHT_TOP;
		return (true);
	}
	else if (ft_wall_outside_isleft_top(map, p))
	{
		strs[p->y][p->x] = WALL_OUT_LEFT_TOP;
		return (true);
	}
	else if (ft_wall_outside_isleft_bottom(map, p))
	{
		strs[p->y][p->x] = WALL_OUT_LEFT_BOTTOM;
		return (true);
	}
	return (false);
}

void	ft_wall_tile_type(t_map *map, t_point *p, char **strs)
{
	if (!ft_is_roof_touch(map, p))
	{
		strs[p->y][p->x] = WALL_OBSTACLE;
		map->data[p->y][p->x] = '0';
	}
	else if (ft_wall_ismiddle(map, p, strs))
		;
	else if (ft_wall_isinside(map, p, strs))
		;
	else if (ft_wall_isoutside(map, p, strs))
		;
	else if (ft_wall_inter_isdiagonal(map, p))
		strs[p->y][p->x] = WALL_INTER_DIAGONAL;
	else if (ft_wall_inter_isantidiagonal(map, p))
		strs[p->y][p->x] = WALL_INTER_ANTIDIAGONAL;
}
