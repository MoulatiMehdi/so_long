#include "player.h"
#include "so_long.h"

void	ft_player_state(t_player *player, char keys[256])
{
	int	total;

	if (player->state == STATE_DYING)
		return ;
	if (player->state == STATE_HURT && player->is_loaded)
	{
		player->is_loaded = false;
		player->is_state_fixed = false;
	}
	if (player->hearts <= 0)
		return (ft_player_state_set(player, STATE_DYING));
	if (player->is_state_fixed)
		return ;
	if (keys[KEY_X] == 1 && player->state == STATE_ATTACK)
		return (ft_player_state_set(player, STATE_LOADING));
	if (keys[KEY_X] == 1 && player->state != STATE_LOADING)
	{
		ft_player_state_set(player, STATE_ATTACK);
		player->is_state_fixed = true;
		return ;
	}
	if (keys[KEY_X] == 1)
		return ;
	if (keys[KEY_X] == 0 && player->is_loaded)
	{
		ft_player_state_set(player, STATE_SPIN);
		player->is_state_fixed = true;
		return ;
	}
	total = (keys[KEY_A] != keys[KEY_D]) + (keys[KEY_S] != keys[KEY_W]);
	if (total == 0)
		return (ft_player_state_set(player, STATE_IDLE));
	else
		return (ft_player_state_set(player, STATE_WALK));
	return ;
}

void	ft_player_way(t_player *player, char keys[256])
{
	int	total;

	if (player->state == STATE_DYING)
		return ;
	total = (keys[KEY_A] != keys[KEY_D]) + (keys[KEY_S] != keys[KEY_W]);
	if (total == 0)
		return ;
	if (total == 1)
	{
		if (keys[KEY_A] == 1 && keys[KEY_D] == 0)
			player->way = WAY_LEFT;
		if (keys[KEY_A] == 0 && keys[KEY_D] == 1)
			player->way = WAY_RIGHT;
		if (keys[KEY_W] == 1 && keys[KEY_S] == 0)
			player->way = WAY_UP;
		if (keys[KEY_W] == 0 && keys[KEY_S] == 1)
			player->way = WAY_DOWN;
		return ;
	}
	if (keys[KEY_S] == 1 && player->way != WAY_LEFT && player->way != WAY_RIGHT)
		player->way = WAY_DOWN;
	if (keys[KEY_W] == 1 && player->way != WAY_LEFT && player->way != WAY_RIGHT)
		player->way = WAY_UP;
}

void	ft_player_coor(t_player *player, int dx, int dy)
{
	player->x += dx * player->speed;
	player->y += dy * player->speed;
	if (player->x > WINDOW_WIDTH - player->width)
		player->x = WINDOW_WIDTH - player->width;
	if (player->y > WINDOW_HEIGHT - player->height)
		player->y = WINDOW_HEIGHT - player->height;
	if (dx != 0 || dy != 0)
	{
		player->moves++;
		player->is_moving = true;
	}
}

void	ft_player_move(t_player *player, char keys[256])
{
	player->is_moving = false;
	if (player->state != STATE_WALK && player->state != STATE_LOADING)
		return ;
	if (keys[KEY_A] == 0 && keys[KEY_D] == 1)
		ft_player_coor(player, 1, 0);
	if (keys[KEY_A] == 1 && keys[KEY_D] == 0)
		ft_player_coor(player, -1, 0);
	if (keys[KEY_W] == 0 && keys[KEY_S] == 1)
		ft_player_coor(player, 0, 1);
	if (keys[KEY_W] == 1 && keys[KEY_S] == 0)
		ft_player_coor(player, 0, -1);
}

void	ft_player_render(t_animation *animation)
{
	t_player	*player;
	t_render	*render;
	t_engine	*engine;

	engine = animation->engine;
	render = animation->render;
	player = engine->player;
	if (!engine->paused)
	{
		ft_player_state(player, engine->keys);
		ft_player_way(player, engine->keys);
		ft_player_move(player, engine->keys);
    }
	if (player->state == STATE_WALK)
		ft_player_walking(player, render);
	if (player->state == STATE_IDLE)
		ft_player_idle(player, render);
	if (player->state == STATE_DYING)
		ft_player_dying(player, render);
	if (player->state == STATE_ATTACK)
		ft_player_attack(player, render);
	if (player->state == STATE_SPIN)
		ft_player_spinning(player, render);
	if (player->state == STATE_VICTORY)
		ft_player_victory(player, render);
	if (player->state == STATE_LOADING)
		ft_player_loading(player, render);
}
