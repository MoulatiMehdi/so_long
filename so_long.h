/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:47:43 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/11 17:08:36 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H
# define KEYS_TOTAL 256
# define WINDOW_HEIGHT 576
# define WINDOW_WIDTH 704
# define WINDOW_TITLE "The Legend Of Zelda"
# define PLAYER_HEARTS_TOTAL 10
# define PLAYER_STATUS_X 208
# define KEY_TRACK "dwascx"
# define KEY_DEBUG_X 528
# define KEY_DEBUG_Y 544
# define ERR_SPRITE_MISSING "Error\n\t\033[91m⚠️  Missing Sprite!\033[0m\n"
# define ERR_ALLOC_FAILED "Error\n\t\033[91m⚠️  Malloc Failed!\033[0m\n"
# define ERR_MLX_FAILED "Error\n\t\033[91m⚠️  MLX Failed!\033[0m\n"
# define ERR_WINDOW_FAILED "Error\n\t\033[91m⚠️  MLX Window Failed!\033[0m\n"

# include "color.h"
# include "image.h"
# include "key.h"
# include "libft/libft.h"
# include "map.h"
# include "player.h"
# include "stdbool.h"
# include <mlx.h>

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

typedef enum e_wall
{
	WALL_EMPTY = '0',
	WALL_WALL = '1',
	WALL_OBSTACLE,
	WALL_ROOF,
	WALL_IN_MID_TOP,
	WALL_IN_MID_BOTTOM,
	WALL_IN_MID_LEFT,
	WALL_IN_MID_RIGHT,
	WALL_IN_LEFT_TOP,
	WALL_IN_LEFT_BOTTOM,
	WALL_IN_RIGHT_BOTTOM,
	WALL_IN_RIGHT_TOP,
	WALL_OUT_LEFT_TOP,
	WALL_OUT_LEFT_BOTTOM,
	WALL_OUT_RIGHT_BOTTOM,
	WALL_OUT_RIGHT_TOP,
	WALL_INTER_DIAGONAL,
	WALL_INTER_ANTIDIAGONAL,
}					t_wall;
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
	SPRITE_STAR_LOADING_H,
	SPRITE_STAR_LOADING_V,
	SPRITE_SWORD_VICTORY,
	SPRITE_FLOOR,
	SPRITE_OBSTACLE,
	SPRITE_WALL,
	SPRITE_RUPEE,
	SPRITE_SMOKE,
	SPRITE_SOLDIER,
	SPRITE_EXIT,
	SPRITE_TOTAL,
}					t_sprite_idx;

typedef struct s_rect
{
	t_point			center;
	int				width;
	int				height;
}					t_rect;

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
	t_point			camera;
	int				map_width;
	int				map_height;
	bool			stop;
}					t_render;

typedef struct s_coin
{
	int				x;
	int				y;
	int				type;
	int				frame;
	bool			is_taken;
}					t_coin;

typedef struct s_enemy
{
	int				x;
	int				y;
	t_way			way;
	t_state			state;
	unsigned int	frame_on_loop;
	bool			is_dead;
	bool			is_fixed;
	int				origin_x;
	int				origin_y;
	int				width;
	int				height;
	int				speed;
}					t_enemy;

typedef struct s_exit
{
	int				x;
	int				y;
	int				type;
	bool			is_on;
}					t_exit;

typedef struct s_engine
{
	bool			paused;
	char			keys[KEYS_TOTAL];
	t_map			*map;
	t_list			*coins;
	t_exit			exit;
	t_player		*player;
	t_enemy			enemy;
	unsigned int	coins_total;
}					t_engine;

typedef struct s_game
{
	t_engine		*engine;
	t_render		*render;
	bool			exit;
}					t_game;

t_engine			*ft_engine_new(void);
void				ft_engine_destroy(t_engine **engine);
void				ft_engine_collision(t_engine *engine, t_render *render);
void				ft_engine_player_update(t_engine *engine);

t_render			*ft_render_new(void);
void				ft_render_player(t_engine *engine, t_render *render);
void				ft_render_keys(t_render *render, t_engine *engine);
void				ft_render_display(t_render *render);
void				ft_render_sprite(t_render *render, t_sprite *sprite,
						t_point *point);
void				ft_render_hearts_counter(t_render *render,
						t_engine *engine);
void				ft_render_moves_counter(t_render *render, int moves);
void				ft_render_coins_counter(t_render *render, t_engine *engine);
void				ft_number_render(t_render *render, t_point *point, int nbr,
						int digits);
void				ft_render_clear(t_render **render);
void				ft_render_map(t_render *render, t_map *map);
void				ft_render_exit(t_exit *door, t_render *render);
void				ft_render_update(t_game *game);
void				ft_render_coins(t_render *render, t_engine *engine);

t_sprite			*ft_sprite_coor_way(t_player *player, t_render *render,
						t_sprite_idx type);
t_sprite			*ft_sprite_new(void *mlx, char *path, unsigned int col,
						unsigned int row);
void				ft_sprite_toimage(t_image *dst, t_sprite *sprite,
						t_point *o_dest);

void				ft_image_grid(t_image *image, int stepx, int stepy,
						t_color color);
void				ft_image_ellipse(t_image *image, t_ellipse *ellipse,
						t_color color);

void				ft_player_state_set(t_player *player, t_state state);
void				ft_player_destroy(t_player **player);
void				ft_player_hurt(t_player *player, t_render *render);
void				ft_player_coor(t_engine *engine, int dx, int dy);
bool				ft_player_state_attack(t_player *player, bool is_attack);
void				ft_player_idle(t_player *player, t_render *render);
void				ft_player_walking(t_player *player, t_render *render);
void				ft_player_spinning(t_player *player, t_render *render);
void				ft_player_attack(t_player *player, t_render *render);
void				ft_player_loading(t_player *player, t_render *render);
void				ft_player_dying(t_player *player, t_render *render);
void				ft_player_victory(t_player *player, t_render *render);
void				ft_player_star(t_player *player, t_render *render);

void				ft_map_grid(t_map *map, t_point *point);
void				ft_map_destroy(t_map **map);

bool				is_valid_point(t_map *map, t_point *point);
void				ft_wall_parse(t_map *map);

bool				ft_camera_is_inview(t_point *camera, t_point *p);
void				ft_camera_player_center(t_render *render, t_player *player,
						t_point *point);

t_coin				*ft_coin_new(int x, int y);

void				ft_camera_update(t_render *render, t_engine *engine);
void				ft_engine_update(t_game *game);
void				engine_parse(t_engine *engine);
void				ft_engine_coins_update(t_game *game);
void				ft_sprite_destroy(t_sprite **sprite);
void				ft_sprites_clear(t_sprite ***sprites);

void				ft_game_start(t_game *game);
t_game				*ft_game_new(t_map *map);
int					ft_game_destroy(t_game *game);

/*void				draw_door_collision(t_engine *engine, t_render *render);*/
/*void				draw_player_collision(t_render *render, t_player *player);*/
/*void				draw_coin_collision(t_render *render, t_point p);*/
/*void				draw_enemy_collision(t_render *render, t_enemy *enemy);*/
/*void				draw_spin_collision(t_engine *engine, t_render *render);*/
/*void				draw_attack_collision(t_engine *engine, t_render *render);*/

void				ft_enemy_init(t_enemy *enemy);

void				ft_soldier_look(t_render *render, t_enemy *enemy);
void				ft_soldier_walk(t_render *render, t_enemy *enemy);
void				ft_soldier_state_set(t_enemy *enemy, t_state state);
void				ft_soldier_dying(t_render *render, t_enemy *enemy);

void				ft_way_init(int *dx, int *dy, t_way way);

bool				ft_collision_player_enemy(t_player *player, t_enemy *enemy);
bool				ft_collision_spin_enemy(t_player *player, t_enemy *enemy);
bool				ft_collision_attack_enemy(t_player *player, t_enemy *enemy);
bool				ft_collision_player_coin(t_player *player, t_sprite *sprite,
						t_coin *coin);
bool				ft_collision_player_door(t_player *player, t_sprite *sprite,
						t_exit *door);
bool				ft_collision_player_wall(t_player *player, t_map *map,
						int dx, int dy);
bool				ft_collision_enemy_wall(t_enemy *enemy, t_map *map, int dx,
						int dy);

void				ft_rect_attack(t_rect *rect, t_player *player);
void				ft_rect_spin(t_rect *rect, t_player *player);
bool				ft_rect_iscollide(t_rect *a, t_rect *b);
t_point				*ft_point_new(int x, int y);
bool				ft_point_isvalid(t_map *map, t_point *p);
#endif
