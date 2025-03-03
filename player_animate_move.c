#include "so_long.h"
#include <stdio.h>

void ft_player_camera_center(t_render * render,t_player * player,t_map * map,t_point * point)
{
    printf("%d %d\n",render->camera.x,render->camera.y);
    point->x = player->x ;
    point->y = player->y ;
    if(render->camera.x > 0 && render->camera.x < (map->width - 1) * 64)
        point->x = WINDOW_WIDTH / 2;
    if(render->camera.y > 0 && render->camera.y < (map->height - 1) * 64)
        point->y = WINDOW_HEIGHT /2;
}


void	ft_player_idle(t_player *player, t_render *render,t_map * map)
{
	t_sprite	*sprite;
	t_point		point;
    
    ft_player_camera_center(render,player,map, &point);
	sprite = render->sprites[SPRITE_LINK_IDLE];
	sprite->x = 0;
	sprite->y = sprite->frame_height * player->way;
	ft_render_sprite(render, sprite, &point);
}

void	ft_player_walking(t_player *player, t_render *render,t_map * map)
{
	t_sprite	*sprite;
	t_point		point;

    ft_player_camera_center(render,player,map, &point);
	sprite = ft_sprite_coor_way(player, render, SPRITE_LINK_WALKING);
	ft_render_sprite(render, sprite, &point);
}

void	ft_player_victory(t_player *player, t_render *render,t_map * map)
{
	static unsigned int	n = 0;
	t_sprite			*sprite_player;
	t_sprite			*sprite_sword;
	t_point				point;

	sprite_sword = render->sprites[SPRITE_SWORD_VICTORY];
	sprite_player = render->sprites[SPRITE_LINK_VICTORY];
    ft_player_camera_center(render,player,map, &point);
	point.x -= 40;
	point.y -= 20;
	sprite_sword->x = sprite_sword->frame_width * ((n / sprite_sword->loop)
			% sprite_sword->col);
	sprite_sword->y = sprite_sword->frame_height * ((n / (sprite_sword->loop
					* sprite_sword->col)) % sprite_sword->row);
	ft_render_sprite(render, sprite_sword, &point);
	point.x = player->x;
	point.y = player->y;
	sprite_player->x = sprite_player->frame_width * (n / sprite_player->loop);
	sprite_player->y = 0;
	ft_render_sprite(render, sprite_player, &point);
	if (n < (sprite_player->col * sprite_player->loop - 1))
		n++;
}
