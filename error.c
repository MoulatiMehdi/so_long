/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:30:51 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/10 23:20:01 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"
#include <stdio.h>

#define ERR_MSG "\033[1;31mError\n\t"

void	ft_perror(char *str)
{
	ft_putstr_fd(ERR_MSG, 2);
	perror(str);
}

void	ft_map_error(t_map **map, t_map_state state)
{
	if (state == OK)
		return ;
	ft_putstr_fd(ERR_MSG, 2);
	if (state == ERR_FILENAME_INVALID)
		ft_putstr_fd("Invalid filename.", 2);
	if (state == ERR_MAP_CHAR_INVALID)
		ft_putstr_fd("The map contains an invalid character.", 2);
	if (state == ERR_MAP_COLLECTABLE)
		ft_putstr_fd("The map must contain at least one collectable.", 2);
	if (state == ERR_MAP_NOT_CLOSED)
		ft_putstr_fd("The map is not closed.", 2);
	if (state == ERR_MAP_PATH_INVALID)
		ft_putstr_fd("The map is not solvable.", 2);
	if (state == ERR_MAP_NOT_RECTANGLE)
		ft_putstr_fd("The map must be rectangular.", 2);
	if (state == ERR_MAP_ONE_EXIT)
		ft_putstr_fd("The map must contain exactly one exit.", 2);
	if (state == ERR_MAP_ONE_PLAYER)
		ft_putstr_fd("The map must contain exactly one player.", 2);
	ft_putstr_fd("\n\033[0m", 2);
	ft_map_destroy(map);
	exit(1);
}
