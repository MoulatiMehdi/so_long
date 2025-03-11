/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_is_middle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:32:50 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/03 17:32:50 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wall.h"

bool	ft_wall_ismiddle_top(t_map *map, t_point *point)
{
	static int	arr[] = {503, 502, 446, 439, 438};
	int			test;
	size_t		k;

	test = ft_wall_tonbr(map, point);
	k = 0;
	while (k < 5)
	{
		if (arr[k] == test)
			return (true);
		k++;
	}
	return (false);
}

bool	ft_wall_ismiddle_bottom(t_map *map, t_point *point)
{
	static int	arr[] = {251, 219, 223, 479, 475};
	int			test;
	size_t		k;

	test = ft_wall_tonbr(map, point);
	k = 0;
	while (k < 5)
	{
		if (arr[k] == test)
			return (true);
		k++;
	}
	return (false);
}

bool	ft_wall_ismiddle_right(t_map *map, t_point *point)
{
	static int	arr[] = {383, 191, 63, 319, 127};
	int			test;
	size_t		k;

	test = ft_wall_tonbr(map, point);
	k = 0;
	while (k < 5)
	{
		if (arr[k] == test)
			return (true);
		k++;
	}
	return (false);
}

bool	ft_wall_ismiddle_left(t_map *map, t_point *point)
{
	static int	arr[] = {506, 509, 504, 505, 508};
	int			test;
	size_t		k;

	test = ft_wall_tonbr(map, point);
	k = 0;
	while (k < 5)
	{
		if (arr[k] == test)
			return (true);
		k++;
	}
	return (false);
}
