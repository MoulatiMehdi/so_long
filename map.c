/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:32:27 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/03 17:32:27 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*ft_map_new(char **array)
{
	t_map	*map;

	if (!array)
		return (NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->data = array;
	map->width = ft_strlen(array[0]);
	map->height = 0;
	while (array[map->height])
		map->height++;
	return (map);
}

void	ft_map_destroy(t_map **map)
{
	if (map == NULL || *map == NULL)
		return ;
	ft_split_free(&(*map)->data);
	free(*map);
	*map = NULL;
}
