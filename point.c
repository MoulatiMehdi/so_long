/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:45:13 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/11 17:45:13 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	*ft_point_new(int x, int y)
{
	t_point	*p;

	p = ft_calloc(sizeof(t_point), 1);
	p->x = x;
	p->y = y;
	return (p);
}

bool	ft_point_isvalid(t_map *map, t_point *p)
{
	return (p->x >= 0 && p->y >= 0 && p->y < map->height && p->x < map->width);
}
