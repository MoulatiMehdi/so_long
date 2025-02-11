/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:07:55 by mmoulati          #+#    #+#             */
/*   Updated: 2025/02/11 23:09:31 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H

# define SO_LONG_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# define CHAR_PLAYER 'P'
# define CHAR_EXIT 'E'
# define CHAR_EMPTY '0'
# define CHAR_WALL '1'
# define CHAR_COLLECTABLE 'C'
# define CHARS_VALID "01CEP"

typedef enum e_state
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
}		t_state;

void	ft_error(char *str1);
void	ft_perror(char *str1);

char	**ft_map_read(char *filename);

void	ft_map_valid(char ***map);
void	ft_map_error(char ***map, t_state state);
void	ft_map_print(char **map);

#endif
