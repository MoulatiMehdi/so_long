/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:30:39 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/10 19:30:38 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	ft_map_print(t_map *map)
{
	int	i;

	if (!map)
	{
		printf("Map NULL\n");
		return ;
	}
	printf("\n");
	i = 0;
	while (i < map->height)
	{
		printf("%s\n", map->data[i]);
		i++;
	}
	printf("\n");
}

int	main(int argc, char *argv[])
{
	t_map		*map;
	t_map_state	state;

	if (argc != 2)
		return (1);
	map = ft_map_new(argv[1]);
	state = ft_map_state(map);
	if (state != OK)
		ft_map_error(&map, state);
	ft_map_print(map);
	ft_map_destroy(&map);
	return (EXIT_SUCCESS);
}
