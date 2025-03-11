/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:00:27 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/11 17:00:27 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H

# define MAP_H
# define CHAR_PLAYER 'P'
# define CHAR_EXIT 'E'
# define CHAR_EMPTY '0'
# define CHAR_WALL '1'
# define CHAR_COLLECTABLE 'C'
# define CHARS_VALID "01CEP"
# define CHARS_CHAGE " 1cep"

# include "libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_map
{
	int		width;
	int		height;
	char	**data;
}			t_map;

typedef enum e_map_state
{
	OK = 0,
	ERR_MAP_CHAR_INVALID,
	ERR_MAP_ONE_PLAYER,
	ERR_MAP_ONE_EXIT,
	ERR_MAP_COLLECTABLE,
	ERR_MAP_NOT_RECTANGLE,
	ERR_MAP_NOT_CLOSED,
	ERR_MAP_MALLOC,
	ERR_MAP_PATH_INVALID,
	ERR_FILENAME_INVALID,
}			t_map_state;

void		ft_error(char *str);
void		ft_perror(char *str);

void		ft_map_destroy(t_map **map);
void		ft_map_error(t_map **map, t_map_state state);
t_map		*ft_map_new(char *filename);
t_map_state	ft_map_state(t_map *map);

#endif
