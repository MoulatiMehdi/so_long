/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:32:25 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/07 21:33:18 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

int	main(void)
{
	t_animation	*game;
	char		**map;

	static char *strs[] = {
		"11111111111111",
		"1PC01110000101",
		"10111110111E11",
		"10000000000001",
		"11111111111111",
		NULL,
	};
	map = ft_strs_dup(strs);
	game = ft_game_new(map);
	ft_game_start(game);
	ft_split_free(&map);
}
