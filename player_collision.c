#include "so_long.h"

static bool	ft_player_is_collision_h(t_player *player, t_map *map, int dx)
{
	t_point	p;
	int		i;

	i = 0;
	p.x = player->x - WINDOW_WIDTH / 2 + map->width * 32 + player->origin_x;
	p.x += dx * player->width / 2;
	p.x += dx * player->speed;
	p.x /= 64;
	while (i < 2)
	{
		p.y = player->y - WINDOW_HEIGHT / 2 + map->height * 32
			+ player->origin_y;
		p.y += (2 * i - 1) * player->height / 2;
		p.y /= 64;
		if (!is_valid_point(map, &p) || map->data[p.y][p.x] != WALL_EMPTY)
			return (false);
		i++;
	}
	return (true);
}

static bool	ft_player_is_collision_v(t_player *player, t_map *map, int dy)
{
	t_point	p;
	int		i;

	i = 0;
	p.y = player->y - WINDOW_HEIGHT / 2 + map->height * 32 + player->origin_y;
	p.y += dy * player->height / 2;
	p.y += dy * player->speed;
	p.y /= 64;
	i = 0;
	while (i < 2)
	{
		p.x = player->x - WINDOW_WIDTH / 2 + map->width * 32 + player->origin_x;
		p.x += (2 * i - 1) * player->width / 2;
		p.x /= 64;
		if (!is_valid_point(map, &p) || map->data[p.y][p.x] != WALL_EMPTY)
			return (false);
		i++;
	}
	return (true);
}

bool	ft_player_is_collision(t_player *player, t_map *map, int dx, int dy)
{
	if (!ft_player_is_collision_h(player, map, dx))
		return (true);
	if (!ft_player_is_collision_v(player, map, dy))
		return (true);
	return (false);
}
