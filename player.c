#include "player.h"
#include "image.h"
#include "key.h"
#include "so_long.h"
#include <stdlib.h>

void	ft_player_debug(t_player *player)
{
    char	*state[STATE_TOTAL];
    char	*way[5];

    state[STATE_IDLE] = "STOPING";
    state[STATE_WALK] = "WALKING";
    state[STATE_SWIM] = "SWIMING";
    state[STATE_GRAB] = "GRABING";
    state[STATE_DYING] = "DYING";
    state[STATE_ATTACK] = "ATTACKING";
    state[STATE_SPIN] = "SPINING";
    state[STATE_VICTORY] = "POSING";
    state[STATE_DEAD] = "DEAD";
    way[WAY_LEFT] = "LEFT";
    way[WAY_RIGHT] = "RIGHT";
    way[WAY_UP] = "UP";
    way[WAY_DOWN] = "DOWN";
    printf(DEBUG "x     : %d\n", player->x);
    printf(DEBUG "y     : %d\n", player->y);
    printf(DEBUG "state : %s\n", state[player->state]);
    printf(DEBUG "way   : %s\n", way[player->way]);
    printf(DEBUG "count : %d\n\n", player->moves);
}

t_player	*ft_player_new(void)
{
    t_player	*player;

    player = malloc(sizeof(t_player));
    if (player == NULL)
        return (NULL);
    player->hearts = 6;
    player->speed = 6;
    player->state = STATE_IDLE;
    player->way = WAY_DOWN;
    player->width = 48;
    player->coins = 0;
    player->moves = 0;
    player->height = 64;
    player->x = 0;
    player->y = 0;
    return (player);
}

void	ft_player_destroy(t_player **player)
{
    free(*player);
    *player = NULL;
}

/*void	ft_player_rect(t_player *player, t_image *dest, int fac_x)*/
/*{*/
/*    int	color;*/
/*    int	i;*/
/*    int	j;*/
/*    int	fac_y;*/
/**/
/*    fac_y = player->way;*/
/*    i = 0;*/
/*    while (i < player->width)*/
/*    {*/
/*        j = 0;*/
/*        while (j < player->height)*/
/*        {*/
/*            color = ft_image_getcolor(player->sprite, player->width * fac_x + i,*/
/*                                      player->height * fac_y + j);*/
/*            ft_image_putpixel(dest, player->x + i, player->y + j, color);*/
/*            j++;*/
/*        }*/
/*        i++;*/
/*    }*/
/*}*/

int	ft_player_state(t_player *player, char keys[256])
{
    int	total;

    if(player->state == STATE_DEAD || player->state == STATE_DYING )
        return 0;
    if(player->hearts <= 0)
        return player->state = STATE_DYING;
    if(keys[KEY_X] == 1)
        return player->state = STATE_ATTACK;
    total = (keys[KEY_A] != keys[KEY_D]) + (keys[KEY_S] != keys[KEY_W]);
    if (total == 0)
        player->state = STATE_IDLE;
    else
        player->state = STATE_WALK;
    return 0;
}

void	ft_player_way(t_player *player, char keys[256])
{
    int	total;

    if(player->state == STATE_DYING || player->state == STATE_DEAD)
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

void	ft_player_move(t_player *player, char keys[256])
{
    if(player->state == STATE_DYING || player->state == STATE_DEAD)
        return ;
    if (keys[KEY_A] == 0 && keys[KEY_D] == 1)
    {
        player->x = ft_min(player->x + player->speed, WINDOW_WIDTH
                           - player->width);
        player->moves ++;
    }
    if (keys[KEY_A] == 1 && keys[KEY_D] == 0)
    {
        player->x = ft_max(player->x - player->speed, 0);
        player->moves ++;
    }
    if (keys[KEY_W] == 0 && keys[KEY_S] == 1)
    {
        player->y = ft_min(player->y + player->speed, WINDOW_HEIGHT
                           - player->height);
        player->moves ++;
    }
    if (keys[KEY_W] == 1 && keys[KEY_S] == 0)
    {
        player->y = ft_max(player->y - player->speed, 0);
        player->moves ++;
    }
}

void ft_player_walking(t_player * player,t_render * render)
{
    static int n = 0;
    t_sprite * sprite;
    t_point point;
   
    point.x = player->x;
    point.y = player->y;
    sprite = render->sprites[SPRITE_WALKING];
    sprite->x = sprite->frame_width * n;
    sprite->y = sprite->frame_height * player->way;

    ft_sprite_toimage(render->back, sprite, &point);
    n = (n + 1) % sprite->col;
}

void ft_player_idle(t_player * player,t_render * render)
{
    t_sprite * sprite;
    t_point point;
   
    point.x = player->x;
    point.y = player->y;
    sprite = render->sprites[SPRITE_IDLE];
    sprite->x = 0;
    sprite->y = sprite->frame_height * player->way;

    ft_sprite_toimage(render->back, sprite, &point);
}

void ft_player_attack(t_player * player,t_render * render)
{
    static int n = 0;
    t_sprite * sprite;
    t_point point;
   
    point.x = player->x;
    point.y = player->y;
    sprite = render->sprites[SPRITE_ATTACKING];
    sprite->x = sprite->frame_width * n;
    sprite->y = sprite->frame_height * player->way;

    ft_sprite_toimage(render->back, sprite, &point);
    n = (n + 1) % sprite->col;
}

void ft_player_spinning(t_player * player,t_render * render)
{
    static int n = 0;
    t_sprite * sprite;
    t_point point;
   
    point.x = player->x;
    point.y = player->y;
    sprite = render->sprites[SPRITE_SPINNING];
    sprite->x = sprite->frame_width * n;
    sprite->y = sprite->frame_height * player->way;

    ft_sprite_toimage(render->back, sprite, &point);
    n = (n + 1) % sprite->col;

}
void ft_player_loading(t_player * player,t_render * render)
{
    static int n = 0;
    t_sprite * sprite;
    t_point point;
   
    point.x = player->x;
    point.y = player->y;
    sprite = render->sprites[SPRITE_LOADING];
    sprite->x = sprite->frame_width * n;
    sprite->y = sprite->frame_height * player->way;

    ft_sprite_toimage(render->back, sprite, &point);
    n = (n + 1) % sprite->col;

}

void ft_player_dying(t_player * player,t_render * render)
{
    static int n = 0;
    t_sprite * sprite;
    t_point point;
   
    point.x = player->x;
    point.y = player->y;
    sprite = render->sprites[SPRITE_DYING];
    sprite->x = 0;
    sprite->y = 0; 

    ft_sprite_toimage(render->back, sprite, &point);
    n = (n + 1) % sprite->col;
}

void ft_player_victory(t_player * player,t_render * render)
{
    static int n = 0;
    t_sprite * sprite;
    t_point point;
   
    point.x = player->x;
    point.y = player->y;
    sprite = render->sprites[SPRITE_VICTORY];
    sprite->x = 0;
    sprite->y = 0; 

    ft_sprite_toimage(render->back, sprite, &point);
    n = (n + 1) % sprite->col;
}

void	ft_player_render(t_animation *animation)
{
    static int	n = 0;
    t_player	*player;
    t_render	*render;
    t_engine	*engine;
 
    engine = animation->engine;
    render = animation->render;
    player = engine->player;
     
    if(!engine->paused)
    {
        ft_player_state(player, engine->keys);
        ft_player_way(player, engine->keys);
        ft_player_move(player, engine->keys);
        n = (n + 1) % (8 * PLAYER_FRAME_NBR);
        if (player->state == STATE_IDLE || player->state == STATE_DEAD)
            n = 0;
    }
    if(player->state == STATE_WALK)
        ft_player_walking(player,render);
    if(player->state == STATE_IDLE)
        ft_player_idle(player,render);
    if(player->state == STATE_DYING)
        ft_player_dying(player, render);
    if(player->state == STATE_ATTACK)
        ft_player_attack(player, render);
    if(player->state == STATE_SPIN)
        ft_player_spinning(player, render);
    if(player->state == STATE_VICTORY)
        ft_player_victory(player, render);
    /*if(player->state == STATE_DYING && n + 1 == PLAYER_FRAME_NBR * 8)*/
    /*    player->state = STATE_DEAD;*/
}

