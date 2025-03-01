#ifndef PLAYER_H

# define PLAYER_H
# define DEBUG "  \033[1;36m[..DEBUG..]\033[0m\t"
# define PLAYER_SPRITE_WALK "./textures/xpm/walk.xpm"
# define PLAYER_FRAME_NBR 2

# include <stdbool.h>

typedef enum e_way
{
	WAY_RIGHT = 0,
	WAY_UP = 1,
	WAY_LEFT = 2,
	WAY_DOWN = 3,
}					t_way;

typedef enum e_state
{
	STATE_IDLE = 0,
	STATE_WALK = 1,
	STATE_DYING,
	STATE_ATTACK,
	STATE_SPIN,
	STATE_VICTORY,
	STATE_LOADING,
	STATE_HURT,
	STATE_TOTAL
}					t_state;

typedef struct s_player
{
    int origin_x;
    int origin_y;
	int				x;
	int				y;
	int				speed;
	int				width;
	int				height;
	t_way			way;
	t_state			state;
	unsigned int	coins;
	unsigned int	moves;
	unsigned int	hearts;
	unsigned int	frame_on_loop;
	unsigned int	charge;
	bool			is_moving;
	bool			is_state_fixed;
	bool			is_loaded;
	bool			is_dead;
}					t_player;

t_player			*ft_player_new(void);
void				ft_player_debug(t_player *player);
void				ft_player_state_set(t_player *player, t_state state);
#endif
