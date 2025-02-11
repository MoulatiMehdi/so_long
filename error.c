/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:37:21 by mmoulati          #+#    #+#             */
/*   Updated: 2025/02/11 23:04:30 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"
#include <stdio.h>

void	ft_error(char *str1)
{
	ft_putstr_fd("\033[31mError\n", 2);
	ft_putstr_fd("      ", 2);
	perror(str1);
}

void	ft_perror(char *str1)
{
	ft_putstr_fd("\033[31mError\n", 2);
	ft_putstr_fd("      ", 2);
	ft_putstr_fd(str1, 2);
	ft_putstr_fd("\033[0m\n", 2);
}

void	ft_map_error(char ***map, t_state state)
{
	if (state == ERR_FILENAME_INVALID)
		ft_perror("Filename invalid");
	else if (state == ERR_MAP_CHAR_INVALID)
		ft_perror("Map with invalid characters");
	else if (state == ERR_MAP_ONE_PLAYER)
		ft_perror("Map must have only one player");
	else if (state == ERR_MAP_ONE_EXIT)
		ft_perror("Map must have only one exit");
	else if (state == ERR_MAP_COLLECTABLE)
		ft_perror("Map should have at least one collectable item");
	else if (state == ERR_MAP_NOT_RECTANGLE)
		ft_perror("Map is not rectangle");
	else if (state == ERR_MAP_NOT_CLOSED)
		ft_perror("Map is not closed");
	else if (state == ERR_MAP_PATH_INVALID)
		ft_perror("Map is not solvable");
	else if (state == ERR_MAP_MALLOC)
		ft_perror("Insufficiant memory");
	if (map)
		ft_split_free(map);
	exit(1);
}
