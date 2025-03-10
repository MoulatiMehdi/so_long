/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_state.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:23:27 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/10 17:35:29 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

bool		ft_map_issolvable(t_map *map);

bool	ft_map_isclosed(t_map *map)
{
	int		i;
	char	**data;

	data = map->data;
	i = 0;
	while (i < map->height)
	{
		if (data[i][0] != CHAR_WALL || data[i][map->width - 1] != CHAR_WALL)
			return (false);
		i++;
	}
	i = 0;
	while (i < map->width)
	{
		if (data[0][i] != CHAR_WALL || data[map->height - 1][i] != CHAR_WALL)
			return (false);
		i++;
	}
	return (true);
}

bool	ft_map_chars_isvalid(t_map *map, int count[3])
{
	t_point	p;

	p.x = 0;
	ft_bzero(count, 3 * sizeof(int));
	while (p.x < map->width)
	{
		p.y = 0;
		while (p.y < map->height)
		{
			if (ft_strchr(CHARS_VALID, map->data[p.y][p.x]) == NULL)
				return (false);
			count[0] += map->data[p.y][p.x] == CHAR_PLAYER;
			count[1] += map->data[p.y][p.x] == CHAR_EXIT;
			count[2] += map->data[p.y][p.x] == CHAR_COLLECTABLE;
			p.y++;
		}
		p.x++;
	}
	return (true);
}

bool	ft_map_isrectangle(t_map *map)
{
	int	i;
	int	len;

	i = 0;
	while (i < map->height)
	{
		len = ft_strlen(map->data[i]);
		if (len != map->width)
			return (false);
		i++;
	}
	return (true);
}

t_map_state	ft_map_state(t_map *map)
{
	int	count[3];

	if (!ft_map_chars_isvalid(map, count))
		return (ERR_MAP_CHAR_INVALID);
	if (count[0] != 1)
		return (ERR_MAP_ONE_PLAYER);
	if (count[1] != 1)
		return (ERR_MAP_ONE_EXIT);
	if (count[2] < 1)
		return (ERR_MAP_COLLECTABLE);
	if (!ft_map_isrectangle(map))
		return (ERR_MAP_NOT_RECTANGLE);
	if (!ft_map_isclosed(map))
		return (ERR_MAP_NOT_CLOSED);
	if (!ft_map_issolvable(map))
		return (ERR_MAP_PATH_INVALID);
	return (OK);
}
