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
# define WINDOW_HEIGHT 560
# define WINDOW_WIDTH 672
# define WINDOW_TITLE "The legend of zelda : Link to Bengurir"
# define KEYS_TOTAL 256

# include "stdbool.h"
# include "color.h"
# include "image.h"
# include "key.h"
# include "libft/libft.h"
# include "player.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

typedef enum e_event
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
}				t_event;

typedef struct s_point
{
    int x;
    int y;

} t_point;

typedef struct s_gui 
{
    int item_x;
    int item_y;
    int y;
    t_image * menu;
    t_image * sprite_square;
    t_image * sprite_cursor;
} t_gui;

typedef struct s_sprite
{
	int			width;
	int			height;
    int x;
    int y;
}				t_sprite;

typedef struct s_enemy
{
	int			x;
	int			y;
	t_way		way;
	t_state		statue;
}				t_enemy;

typedef struct s_render
{
	void		*mlx;
	void		*window;
	t_image		*curr;
	t_image		*next;

}				t_render;

typedef struct s_engine
{
    bool paused;
	char		keys[KEYS_TOTAL];
	void		*window;
	void		*mlx;
	char		**map;
	t_player	*player;
    t_gui * gui;
}				t_engine;

typedef struct s_game
{
	t_engine	*engine;
	t_render	*frame;
}				t_game;

typedef struct s_animation
{
	t_engine	*engine;
	t_render	*render;
	t_image		*square;
	t_image		*debug;

}				t_animation;

void			ft_player_destroy(t_player **player);
void			ft_engine_destroy(t_engine **engine);

t_engine		*ft_engine_new(void);
t_render		*ft_render_new(void *mlx, void *window);
void			ft_render_display(t_render *render);
void			ft_image_towindow(t_image *image, t_render *render, int x,
					int y);
void			ft_player_render(t_animation *animation);
void			ft_key_debug(t_animation *animation);
void			ft_key_conflict(char keys[256]);
void ft_gui_draw(t_gui * gui);

void	ft_sprite_toimage(t_gui * gui,t_sprite *sprite,t_point *dest);
void ft_image_dup(t_image * dest,t_image * src, int x , int y);
#endif
