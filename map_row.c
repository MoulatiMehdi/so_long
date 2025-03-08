/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_row.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:07:56 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/08 16:39:25 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map_state	ft_check_state(int *count)
{
	if (count[0] != 1)
		return (ERR_MAP_ONE_EXIT);
	if (count[1] != 1)
		return (ERR_MAP_ONE_PLAYER);
	if (count[2] < 1)
		return (ERR_MAP_COLLECTABLE);
	return (OK);
}

t_map_state	ft_check_row(t_map *map)
{
	t_point	p;
	int		count[3];
	char	*row;

	p.y = 0;
	while (p.y < map->height)
	{
		row = map->data[p.y];
		if ((int)ft_strlen(row) != map->width)
			return (ERR_MAP_NOT_RECTANGLE);
		p.x = 0;
		while (row[p.x])
		{
			if (ft_strchr(CHARS_VALID, row[p.x]) == NULL)
				return (ERR_MAP_CHAR_INVALID);
			count[0] += row[p.x] == CHAR_EXIT;
			count[1] += row[p.x] == CHAR_PLAYER;
			count[2] += row[p.x] == CHAR_COLLECTABLE;
			p.x++;
		}
		p.y++;
	}
	return (ft_check_state(count));
}
