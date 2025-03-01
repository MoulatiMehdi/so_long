#include "color.h"
#include "image.h"
#include "key.h"
#include "player.h"
#include "so_long.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ft_player_debug(t_player *player)
{
	static t_player	copy;
	char			*state[STATE_TOTAL];
	char			*way[5];

	if (memcmp(&copy, player, sizeof(t_player)) == 0)
		return ;
	state[STATE_IDLE] = "STOPING";
	state[STATE_WALK] = "WALKING";
	state[STATE_DYING] = "DYING";
	state[STATE_ATTACK] = "ATTACKING";
	state[STATE_SPIN] = "SPINING";
	state[STATE_VICTORY] = "VICTORY";
	state[STATE_LOADING] = "LOADING";
	way[WAY_LEFT] = "LEFT";
	way[WAY_RIGHT] = "RIGHT";
	way[WAY_UP] = "UP";
	way[WAY_DOWN] = "DOWN";
	printf(DEBUG "(x,y)      : (%d,%d)\n", copy.x, copy.y);
	printf(DEBUG "(x,y)      : (%d,%d)\n", player->x, player->y);
	printf(DEBUG "state      : %s\n", state[player->state]);
	printf(DEBUG "direction  : %s\n", way[player->way]);
	printf(DEBUG "fixed      : %s\n", player->is_state_fixed ? "Yes" : "No");
	printf(DEBUG "loaded     : %s\n", player->is_loaded ? "Yes" : "No");
	printf(DEBUG "charge     : %d\n", player->charge);
	printf(DEBUG "dead       : %s\n\n", player->is_dead ? "Yes" : "No");
	copy = *player;
}

void	ft_player_state_set(t_player *player, t_state state)
{
	if (player == NULL)
		return ;
	if (player->is_state_fixed && state != STATE_DYING)
		return ;
	if (state == player->state && state != STATE_ATTACK)
		return ;
	player->state = state;
	player->frame_on_loop = 0;
	if (player->state != STATE_LOADING)
		player->charge = 0;
}

t_player	*ft_player_new(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (player == NULL)
		return (NULL);
	player->coins = 0;
	player->charge = 0;
	player->moves = 0;
	player->hearts = 10;
	player->speed = 2;
	player->width = 48;
	player->height = 64;
	player->is_moving = false;
	player->is_loaded = false;
	player->is_dead = false;
	player->is_state_fixed = false;
	player->x = WINDOW_WIDTH / 2;
	player->y = WINDOW_HEIGHT / 2;
	player->way = WAY_DOWN;
	player->state = STATE_IDLE;
	player->frame_on_loop = 0;
    player->origin_y = 48;
    player->origin_x = 24;
	return (player);
}

void	ft_player_destroy(t_player **player)
{
	free(*player);
	*player = NULL;
}
