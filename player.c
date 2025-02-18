#include "so_long.h"
#include <stdlib.h>
#define DEBUG "  \033[1;36m[..DEBUG..]\033[0m\t"

void	ft_player_debug(t_player *player)
{
	char	*state[5];
	char	*way[5];

	state[STATE_IDLE] = "IDLE";
	state[STATE_WALK] = "WALK";
	state[STATE_SWIM] = "SWIM";
	state[STATE_GRAB] = "SWIM";
	way[WAY_LEFT] = "LEFT";
	way[WAY_RIGHT] = "RIGHT";
	way[WAY_UP] = "UP";
	way[WAY_DOWN] = "DOWN";
	printf(DEBUG "x     : %d\n", player->x);
	printf(DEBUG "y     : %d\n", player->y);
	printf(DEBUG "state : %s\n", state[player->state]);
	printf(DEBUG "way   : %s\n\n", way[player->way]);
}

t_player	*ft_player_new(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (player == NULL)
		return (NULL);
	player->speed = 3;
	player->state = STATE_IDLE;
	player->way = WAY_DOWN;
	player->x = 0;
	player->y = 0;
	return (player);
}

void	ft_player_destroy(t_player **player)
{
	free(*player);
	*player = NULL;
}

void	ft_player_rect(t_image *dest, t_image *src, int src_x, int src_y,
		int dest_x, int dest_y)
{
	int	width;
	int	height;
	int	color;
	int	i;
	int	j;

	width = 48;
	height = 64;
	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			color = ft_image_getcolor(src, src_x + i, src_y + j);
			ft_image_putpixel(dest, dest_x + i, dest_y + j, color);
			j++;
		}
		i++;
	}
}

void	ft_player_way(t_engine *engine)
{
	char		*keys;
	t_player	*player;
	int			total;

	keys = engine->keys;
	player = engine->player;
	total = keys[KEY_A] + keys[KEY_D] + keys[KEY_S] + keys[KEY_W];
	if (total == 0)
	{
		player->state = STATE_IDLE;
		return ;
	}
	player->state = STATE_WALK;
	if (total == 1)
	{
		if (keys[KEY_A] == 1)
			player->way = WAY_LEFT;
		if (keys[KEY_D] == 1)
			player->way = WAY_RIGHT;
		if (keys[KEY_W] == 1)
			player->way = WAY_UP;
		if (keys[KEY_S] == 1)
			player->way = WAY_DOWN;
		return ;
	}
	if (keys[KEY_S] == 1 && player->way != WAY_LEFT)
		player->way = WAY_DOWN;
	if (keys[KEY_W] == 1 && player->way != WAY_LEFT)
		player->way = WAY_UP;
}

void	ft_player_move(t_engine *engine)
{
	if (engine->keys[KEY_D] == 1)
	{
		if (engine->player->x + engine->player->speed < WINDOW_WIDTH - 48)
			engine->player->x += engine->player->speed;
		else
			engine->player->x = WINDOW_WIDTH - 48;
	}
	if (engine->keys[KEY_A] == 1)
	{
		if (engine->player->x >= engine->player->speed)
			engine->player->x -= engine->player->speed;
		else
			engine->player->x = 0;
	}
	if (engine->keys[KEY_S] == 1)
	{
		if (engine->player->y + engine->player->speed < WINDOW_HEIGHT - 64)
			engine->player->y += engine->player->speed;
		else
			engine->player->y = WINDOW_HEIGHT - 64;
	}
	if (engine->keys[KEY_W] == 1)
	{
		if (engine->player->y > engine->player->speed)
			engine->player->y -= engine->player->speed;
		else
			engine->player->y = 0;
	}
}

void	ft_player_render(t_animation *animation)
{
	static int	n = 0;
	t_player	*player;
	t_render	*render;

	render = animation->render;
	player = animation->engine->player;
	ft_player_way(animation->engine);
	ft_player_move(animation->engine);
	if (player->state == STATE_IDLE)
		n = 0;
	ft_player_rect(render->curr, animation->square, 48 * (n / 3), 64
		* player->way, player->x, player->y);
	ft_player_debug(player);
	n = (n + 1) % (8 * 3);
}
