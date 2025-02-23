#include "so_long.h"

void	ft_player_coor(t_player *player, int dx, int dy)
{
	player->x += dx * player->speed;
	player->y += dy * player->speed;
	if (player->x > WINDOW_WIDTH - player->width)
		player->x = WINDOW_WIDTH - player->width;
	if (player->y > WINDOW_HEIGHT - player->height)
		player->y = WINDOW_HEIGHT - player->height;
	if (player->y < 0)
		player->y = 0;
	if (player->x < 0)
		player->x = 0;
	if (dx != 0 || dy != 0)
	{
		player->moves++;
		player->is_moving = true;
	}
}

bool	ft_player_state_attack(t_player *player, bool is_attack)
{
	if (is_attack && player->state == STATE_ATTACK)
	{
		ft_player_state_set(player, STATE_LOADING);
		return (1);
	}
	if (is_attack && player->state != STATE_LOADING)
	{
		ft_player_state_set(player, STATE_ATTACK);
		player->is_state_fixed = true;
		return (1);
	}
	if (is_attack)
		return (1);
	if (!is_attack && player->is_loaded)
	{
		ft_player_state_set(player, STATE_SPIN);
		player->is_state_fixed = true;
		return (1);
	}
	return (0);
}
