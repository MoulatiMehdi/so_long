#include "so_long.h"
#include <stdio.h>


bool ft_player_move_isvalid(t_engine * engine,int dx, int dy)
{
    t_point p;
    t_player * player;
    t_map * map;

    player = engine->player;
    map = engine->map;

    p.x = player->x - WINDOW_WIDTH / 2 + map->width * 32  + player->origin_x ;
    p.y = player->y - WINDOW_HEIGHT / 2 + map->height * 32 + player->origin_y;
    
    /*p.x += player->width * (dx > 0);*/
    p.x += dx * player->speed; 
    p.x /=64;
    p.y /=64;
    if(!is_valid_point(map,&p))
        return false;
    if(map->data[p.y][p.x] != WALL_EMPTY)
        return false;
    p.x = player->x - WINDOW_WIDTH / 2 + map->width * 32  + player->origin_x ;
    p.y = player->y - WINDOW_HEIGHT / 2 + map->height * 32 + player->origin_y;
    /*p.y += player->height * (dy > 0);*/
    p.y += dy * player->speed; 
    p.x /=64;
    p.y /=64;
    if(!is_valid_point(map,&p))
        return false;
    if(map->data[p.y][p.x] != WALL_EMPTY)
        return false;
    return true;
}

void	ft_player_coor(t_engine *engine, int dx, int dy)
{
    t_player * player;
t_map * map;
    t_point p;

    map = engine->map;
    player = engine->player;
    if (dx == 0 && dy == 0)
        return ;
    player->moves++;
	player->is_moving = true;

    p.x = player->x - WINDOW_WIDTH / 2 + map->width * 32; 
    p.y = player->y - WINDOW_HEIGHT / 2 + map->height * 32; 
    
    p.x /=64;
    p.y /=64;
    ft_map_grid(map, &p);
    if(!ft_player_move_isvalid(engine, dx, dy))
        return ;
    player->x += dx * player->speed;
	player->y += dy * player->speed;
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
