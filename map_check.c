/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:53:41 by mmoulati          #+#    #+#             */
/*   Updated: 2025/02/11 23:13:15 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_row(char ***map, size_t i, size_t length, size_t *counts)
{
	size_t	j;
	char	*row;

	row = (*map)[i];
	if (ft_strlen(row) != length)
		ft_map_error(map, ERR_MAP_NOT_RECTANGLE);
	j = 0;
	while (row[j])
	{
		if (ft_strchr(CHARS_VALID, row[j]) == NULL)
			ft_map_error(map, ERR_MAP_CHAR_INVALID);
		counts[0] += row[j] == CHAR_EXIT;
		counts[1] += row[j] == CHAR_PLAYER;
		counts[2] += row[j] == CHAR_COLLECTABLE;
		j++;
	}
}

static bool	ft_check_backtrack(char **map, size_t y, size_t x, size_t range[2])
{
	bool	found;

	found = false;
	if (x >= range[1] || x < 0 || y < 0 || y >= range[0])
		return (false);
	if (map[x][y] == CHAR_EXIT || map[x][y] == CHAR_WALL || map[x][y] == '\0')
		return (map[x][y] == CHAR_EXIT);
	map[x][y] = CHAR_WALL;
	found = ft_check_backtrack(map, y - 1, x, range);
	found = found || ft_check_backtrack(map, y + 1, x, range);
	found = found || ft_check_backtrack(map, y, x - 1, range);
	found = found || ft_check_backtrack(map, y, x + 1, range);
	return (found);
}

static bool	ft_check_closed(char **map)
{
	size_t	width;
	size_t	height;
	size_t	i;

	if (map == NULL || map[0] == NULL)
		return (false);
	width = ft_strlen(map[0]);
	height = 0;
	while (map[height])
		height++;
	i = 0;
	while (i < height)
	{
		if (map[i][0] != CHAR_WALL || map[i][width - 1] != CHAR_WALL)
			return (false);
		i++;
	}
	while (i < width)
	{
		if (map[0][i] != CHAR_WALL || map[height - 1][i] != CHAR_WALL)
			return (false);
		i++;
	}
	return (true);
}

static bool	ft_check_solvable(char **map)
{
	size_t	range[2];
	char	**copy;
	bool	is_solved;
	size_t	x;
	size_t	y;

	if (map == NULL || map[0] == NULL)
		return (false);
	range[0] = ft_strlen(map[0]);
	range[1] = 0;
	while (map[range[1]])
	{
		range[1]++;
		if (ft_strchr(map[range[1]], CHAR_PLAYER))
		{
			y = range[1];
			x = ft_strchr(map[range[1]], CHAR_PLAYER) - map[range[1]];
		}
	}
	copy = ft_strs_dup(map);
	is_solved = ft_check_backtrack(copy, x, y, range);
	ft_split_free(&copy);
	return (is_solved);
}

void	ft_map_valid(char ***map)
{
	size_t	i;
	size_t	count[3];
	size_t	words;

	if (map == NULL || (*map)[0] == NULL)
		ft_map_error(map, ERR_MAP_NOT_CLOSED);
	words = ft_strlen((*map)[0]);
	i = 0;
	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	while ((*map)[i])
		ft_check_row(map, i++, words, count);
	if (count[0] != 1)
		ft_map_error(map, ERR_MAP_ONE_EXIT);
	if (count[1] != 1)
		ft_map_error(map, ERR_MAP_ONE_PLAYER);
	if (count[2] < 1)
		ft_map_error(map, ERR_MAP_COLLECTABLE);
	if (ft_check_closed(*map) == false)
		ft_map_error(map, ERR_MAP_NOT_CLOSED);
	if (!ft_check_solvable(*map))
		ft_map_error(map, ERR_MAP_PATH_INVALID);
}
