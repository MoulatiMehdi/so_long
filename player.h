#ifndef PLAYER_H

#define PLAYER_H

#include "image.h"

typedef enum e_way
{
	WAY_RIGHT = 0,
	WAY_UP = 1,
	WAY_LEFT = 2,
	WAY_DOWN = 3,
}			t_way;

typedef enum e_state
{
	STATE_IDLE = 0,
	STATE_WALK = 1,
	STATE_SWIM = 2,
	STATE_GRAB = 3,
}			t_state;

typedef struct s_player
{
	int		x;
	int		y;
    int		speed;
	int width;
    int height;
    t_way	way;
	t_state	state;
	t_image * sprite;

}			t_player;

t_player	*ft_player_new(void);
void		ft_player_debug(t_player *player);

#endif
