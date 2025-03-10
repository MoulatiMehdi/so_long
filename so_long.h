/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:07:55 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/10 17:38:47 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define CHAR_PLAYER 'P'
# define CHAR_EXIT 'E'
# define CHAR_EMPTY '0'
# define CHAR_WALL '1'
# define CHAR_COLLECTABLE 'C'
# define CHARS_VALID "01CEP"
# define CHARS_CHAGE " 1cep"

typedef struct s_map
{
	int		width;
	int		height;
	char	**data;
}			t_map;

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

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

t_map		*ft_map_new(char *filename);
void		ft_map_destroy(t_map **map);
t_map_state	ft_map_state(t_map *map);
void		ft_map_error(t_map **map, t_map_state state);

void		ft_map_print(t_map *map);
#endif
