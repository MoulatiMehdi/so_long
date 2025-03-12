/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:32:25 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/11 17:11:18 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	ft_map_isvalid_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (false);
	return (ft_strncmp(&filename[len - 4], ".ber", 5) == 0);
}

int	main(int argc, char *argv[])
{
	t_map		*map;
	t_map_state	state;
	t_game	*game;

	if (argc != 2)
		return (1);
	if (!ft_map_isvalid_extension(argv[1]))
		ft_map_error(NULL, ERR_FILENAME_INVALID);
	map = ft_map_new(argv[1]);
	state = ft_map_state(map);
	if (state != OK)
		ft_map_error(&map, state);
	game = ft_game_new(map);
	ft_game_start(game);
}
