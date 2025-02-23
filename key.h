/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:19:45 by mmoulati          #+#    #+#             */
/*   Updated: 2025/02/11 16:23:11 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H

# define KEY_H

typedef enum e_key_state
{
    KEY_STATE_RELEASE = 0,
    KEY_STATE_PRESS = 1,
    KEY_STATE_HOLD,
} t_key_state;

typedef enum e_key
{
	KEY_ESC = 65307,
	KEY_X = 'x',
	KEY_C = 'c',
	KEY_A = 'a',
	KEY_S = 's',
	KEY_W = 'w',
	KEY_D = 'd',
	KEY_UP = 65362,
	KEY_DOWN = 65364,
	KEY_LEFT = 65361,
	KEY_RIGHT = 65363,
	KEY_SPACE = ' ',
}	t_key;

#endif
