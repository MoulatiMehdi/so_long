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
# define KEYS_TOTAL 256
# define WINDOW_HEIGHT 576
# define WINDOW_WIDTH 672
# define WINDOW_TITLE "The Legend Of Zelda"
# define PLAYER_HEARTS_TOTAL 10
# define PLAYER_STATUS_X 208
# define KEY_TRACK "dwascx"
# define KEY_DEBUG_X 528
# define KEY_DEBUG_Y 544

# include "color.h"
# include "image.h"
# include "key.h"
# include "libft/libft.h"
# include "player.h"
# include "stdbool.h"
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
}					t_event;

typedef enum e_sprite_idx
{
	SPRITE_LINK_SPIN = 0,
	SPRITE_LINK_LOADING = 1,
	SPRITE_LINK_IDLE,
	SPRITE_LINK_VICTORY,
	SPRITE_LINK_WALKING,
	SPRITE_LINK_ATTACKING,
	SPRITE_LINK_DYING,
	SPRITE_LINK_HURT,
	SPRITE_SWORD_ATTACK,
	SPRITE_SWORD_LOADING,
	SPRITE_SWORD_SPIN,
	SPRITE_DEBUG,
	SPRITE_COIN,
	SPRITE_DIGITS,
	SPRITE_CAPE,
	SPRITE_HEARTS,
	SPRITE_GAMEOVER,
	SPRITE_TOTAL,
}					t_sprite_idx;

typedef struct s_point
{
	int				x;
	int				y;

}					t_point;

typedef struct s_sprite
{
	int				x;
	int				y;
	int				frame_width;
	int				frame_height;
	unsigned int	loop;
	unsigned int	row;
	unsigned int	col;
	t_image			*image;

}					t_sprite;

typedef struct s_render
{
	void			*mlx;
	void			*window;
	t_image			*back;
	t_image			*front;
	t_sprite		**sprites;
	bool			stop;
}					t_render;

typedef struct s_engine
{
	bool			paused;
	void			*window;
	void			*mlx;
	char			**map;
	t_player		*player;
	char			keys[KEYS_TOTAL];
}					t_engine;

typedef struct s_animation
{
	t_engine		*engine;
	t_render		*render;
}					t_animation;

typedef struct s_ellipse
{
	t_point			center;
	int				raduis_x;
	int				raduis_y;
}					t_ellipse;

void				ft_player_destroy(t_player **player);
void				ft_engine_destroy(t_engine **engine);

t_engine			*ft_engine_new(void);
t_render			*ft_render_new(void *mlx, void *window);

void				ft_player_render(t_animation *animation);
void				ft_key_debug(t_animation *animation);
void				ft_sprite_toimage(t_image *dst, t_sprite *sprite,
						t_point *o_dest);
void				ft_image_grid(t_image *image, int stepx, int stepy,
						t_color color);
void				ft_image_ellipse(t_image *image, t_ellipse *ellipse,
						t_color color);

t_sprite			*ft_sprite_new(void *mlx, char *path, unsigned int col,
						unsigned int row);

void				ft_render_display(t_render *render);
void				ft_render_sprite(t_render *render, t_sprite *sprite,
						t_point *point);
void				ft_player_state_set(t_player *player, t_state state);

void				ft_player_idle(t_player *player, t_render *render);
void				ft_player_walking(t_player *player, t_render *render);
void				ft_player_spinning(t_player *player, t_render *render);
void				ft_player_attack(t_player *player, t_render *render);
void				ft_player_loading(t_player *player, t_render *render);
void				ft_player_dying(t_player *player, t_render *render);
void				ft_player_victory(t_player *player, t_render *render);

void				ft_key_debug(t_animation *animation);
void				ft_hearts_render(t_animation *animation);
void				ft_counter_render(t_animation *animation);
void				ft_coin_render(t_animation *animation);
void				ft_number_render(t_animation *animation, t_point *point,
						int nbr, int digits);
#endif
