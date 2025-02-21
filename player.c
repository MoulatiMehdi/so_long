#include "player.h"
#include "image.h"
#include "key.h"
#include "so_long.h"
#include <stdbool.h>
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
    state[STATE_LOADING] = "LOADING";
    state[STATE_LOADED] = "LOADED";
    way[WAY_LEFT] = "LEFT";
    way[WAY_RIGHT] = "RIGHT";
    way[WAY_UP] = "UP";
    way[WAY_DOWN] = "DOWN";
    printf(DEBUG "(x,y)      : (%d,%d)\n", player->x, player->y);
    printf(DEBUG "state      : %s\n", state[player->state]);
    printf(DEBUG "direction  : %s\n", way[player->way]);
    printf(DEBUG "fixed      : %s\n", player->is_state_fixed? "Yes" : "No");
    printf(DEBUG "loaded     : %s\n\n", player->is_loaded? "Yes" : "No");
}

void ft_player_set_state(t_player* player,t_state state)
{
    if(player->is_state_fixed && state != STATE_DYING)
        return ;
    player->state = state;
    player->frame_on_loop = 0;

}

t_player	*ft_player_new(void)
{
    t_player	*player;

    player = malloc(sizeof(t_player));
    if (player == NULL)
        return (NULL);
    player->hearts = 6;
    player->speed = 6;
    player->way = WAY_DOWN;
    player->width = 48;
    player->coins = 0;
    player->moves = 0;
    player->height = 64;
    player->is_moving = false;
    player->is_loaded= false;
    player->is_dead= false;
    player->is_state_fixed = false;
    player->x = WINDOW_WIDTH / 2;
    player->y = WINDOW_HEIGHT / 2 ;
    ft_player_set_state(player, STATE_IDLE);
    return (player);
}

void	ft_player_destroy(t_player **player)
{
    free(*player);
    *player = NULL;
}


void	ft_player_state(t_player *player, char keys[256])
{
    int	total;

    if(player->state == STATE_DEAD || player->state == STATE_DYING )
        return ;
    if(player->hearts <= 0)
        return ft_player_set_state(player, STATE_DYING);
    if(player->is_state_fixed)
        return ;
    if(keys[KEY_X] == 1 && player->state == STATE_ATTACK)
        return ft_player_set_state(player,STATE_LOADING);
    if(keys[KEY_X] == 1 && player->state != STATE_LOADING)
    {
        ft_player_set_state(player,STATE_ATTACK);
        player->is_state_fixed = true;
        return ;
    }
    if(keys[KEY_X] == 1)
        return ;
    total = (keys[KEY_A] != keys[KEY_D]) + (keys[KEY_S] != keys[KEY_W]);
    if (total == 0)
        return ft_player_set_state(player,STATE_IDLE);
    else
        return ft_player_set_state(player,STATE_WALK);
    return;
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
    player->is_moving = false;
    if(player->state == STATE_DYING || player->state == STATE_DEAD)
        return ;
    if (keys[KEY_A] == 0 && keys[KEY_D] == 1)
    {
        player->x = ft_min(player->x + player->speed, WINDOW_WIDTH
                           - player->width);
        player->moves ++;
        player->is_moving = true;
    }
    if (keys[KEY_A] == 1 && keys[KEY_D] == 0)
    {
        player->x = ft_max(player->x - player->speed, 0);
        player->moves ++;
        player->is_moving = true;
    }
    if (keys[KEY_W] == 0 && keys[KEY_S] == 1)
    {
        player->y = ft_min(player->y + player->speed, WINDOW_HEIGHT
                           - player->height);
        player->moves ++;
        player->is_moving = true;
    }
    if (keys[KEY_W] == 1 && keys[KEY_S] == 0)
    {
        player->y = ft_max(player->y - player->speed, 0);
        player->moves ++;
        player->is_moving = true;
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
    int repeat;
    t_sprite * sprite;
    t_point point;
  
    repeat = 1;
    point.x = player->x - 8;
    point.y = player->y;
    sprite = render->sprites[SPRITE_ATTACKING];
    sprite->x = sprite->frame_width * (player->frame_on_loop / repeat);
    sprite->y = sprite->frame_height * player->way;

    ft_sprite_toimage(render->back, sprite, &point);
    if(player->frame_on_loop == sprite->col * repeat - 1)
        player->is_state_fixed = false;
    player->frame_on_loop = (player->frame_on_loop + 1) % (sprite->col * repeat);

}

void ft_player_spinning(t_player * player,t_render * render)
{
    t_sprite * sprite;
    t_point point;
    int repeat ;
   
    repeat = 1;
    point.x = player->x;
    point.y = player->y + 16;
    sprite = render->sprites[SPRITE_SPINNING];
    sprite->x = sprite->frame_width * (player->frame_on_loop/repeat);
    sprite->y = sprite->frame_height * player->way;

    ft_sprite_toimage(render->back, sprite, &point);
    if(player->frame_on_loop + 1 == sprite->col * repeat)
    {
        player->is_state_fixed = false;
        player->is_loaded = false;
    }
    player->frame_on_loop= (player->frame_on_loop+ 1) % (sprite->col * repeat);

}
void ft_player_loading(t_player * player,t_render * render)
{
    
    t_sprite * sprite;
    t_point point;
    int repeat;

    repeat = 3;
    point.x = player->x;
    point.y = player->y;
    sprite = render->sprites[SPRITE_LOADING];
    sprite->x = sprite->frame_width * (player->frame_on_loop/repeat) * player->is_moving;
    sprite->y = sprite->frame_height * player->way;
   
    if(sprite->col * repeat- 1 == player->frame_on_loop )
        player->is_loaded = true;
    ft_sprite_toimage(render->back, sprite, &point);
    player->frame_on_loop = (player->frame_on_loop + 1) % (sprite->col * repeat);

}

void ft_player_dying(t_player * player,t_render * render)
{
    t_sprite * sprite;
    t_point point;
    int repeat;
   
    repeat = 8;
    point.x = player->x;
    point.y = player->y;
    sprite = render->sprites[SPRITE_DYING];
    sprite->x = sprite->frame_width * (player->frame_on_loop/ repeat);
    if(player->is_dead)
        sprite->x = (sprite->col - 1) * sprite->frame_width;
    sprite->y = 0; 

    if(player->frame_on_loop + 1 == sprite->col * repeat) 
        player->is_dead = true;
    ft_sprite_toimage(render->back, sprite, &point);
    player->frame_on_loop= (player->frame_on_loop+ 1) % (sprite->col * repeat);
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
        if(engine->keys[KEY_X] == 0 && player->is_loaded)
        {
                ft_player_set_state(player, STATE_SPIN);
                player->is_state_fixed = true;
        }
        ft_player_move(player, engine->keys);
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
    if(player->state == STATE_LOADING)
        ft_player_loading(player, render);
    /*if(player->state == STATE_DYING && n + 1 == PLAYER_FRAME_NBR * 8)*/
    /*    player->state = STATE_DEAD;*/
}

