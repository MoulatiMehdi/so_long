/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:53:41 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/08 16:43:09 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	ft_check_closed(t_map *map)
{
	int		i;
	char	**strs;

	strs = map->data;
	if (strs == NULL || strs[0] == NULL)
		return (false);
	i = 0;
	while (i < map->height)
	{
		if (strs[i][0] != CHAR_WALL || strs[i][map->width - 1] != CHAR_WALL)
			return (false);
		i++;
	}
	i = 0;
	while (i < map->width)
	{
		if (strs[0][i] != CHAR_WALL || strs[map->height - 1][i] != CHAR_WALL)
			return (false);
		i++;
	}
	return (true);
}

t_map_state	ft_map_valid(t_map *map)
{
	int			i;
	t_map_state	state;

	if (map == NULL || map->data == NULL)
		return (ERR_MAP_MALLOC);
	if (map->data[0] == NULL)
		return (ERR_MAP_NOT_CLOSED);
	i = 0;
	state = ft_check_row(map);
	if (state != OK)
		return (state);
	if (!ft_check_closed(map))
		return (ERR_MAP_NOT_CLOSED);
	if (!ft_check_solvable(map))
		return (ERR_MAP_PATH_INVALID);
	return (OK);
}
