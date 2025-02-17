/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:47:43 by mmoulati          #+#    #+#             */
/*   Updated: 2025/02/11 16:45:08 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H
# define WINDOW_HEIGHT 500
# define WINDOW_WIDTH 1000
# define WINDOW_TITLE "The legend of zelda : Link to Bengurir"
# define KEYS_TOTAL 256

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
#include "color.h"
#include "player.h"
#include "data.h"
# include "key.h"
# include "libft/libft.h"

typedef enum e_event
{
    ON_KEYDOWN = 2,
    ON_KEYUP = 3,
    ON_MOUSEDOWN = 4,
    ON_MOUSEUP = 5,
    ON_MOUSEMOVE = 6,
    ON_EXPOSE = 12,
    ON_DESTROY = 17
}						t_event;


typedef struct s_sprite
{
    int width;
    int height;
    t_image * image;
} t_sprite;

typedef struct s_enemy {

    int x;
    int y;
    t_state statue;
    t_way way;
} t_enemy;

typedef struct s_frame
{
    t_image * curr;
    t_image * next;

} t_frame;

typedef struct s_engine
{
    char keys[KEYS_TOTAL];
    void * window;
    void * mlx;
    t_player *player;
    char ** map;
} t_engine;


typedef struct s_game
{
    t_engine * engine;
    t_frame *frame;
} t_game;


t_frame* ft_frame_new(char * title,int width,int height);
void ft_frame_putimage(t_frame *frame,t_image * img,int x , int y);
void ft_frame_display(t_frame *frame);
void ft_frame_clear(t_frame * frame);

void ft_player_destroy(t_player ** player);

void ft_engine_destroy(t_engine** engine);
t_engine * ft_engine_new(void);

#endif
