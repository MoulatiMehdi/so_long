#include "image.h"
#include "key.h"
#include "so_long.h"
#include <stdlib.h>

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
    player->hearts = 0;
    player->speed = 6;
    player->state = STATE_IDLE;
    player->way = WAY_DOWN;
    player->width = 48;
    player->sprite = NULL;
    player->coins = 0;
    player->moves = 0;
    player->height = 64;
    player->x = 0;
    player->y = 0;
    return (player);
}

void	ft_player_destroy(t_player **player)
{
    if ((*player)->sprite != NULL)
        ft_image_clear(&(*player)->sprite);
    free(*player);
    *player = NULL;
}

void	ft_player_rect(t_player *player, t_image *dest, int fac_x)
{
    int	color;
    int	i;
    int	j;
    int	fac_y;

    fac_y = player->way;
    i = 0;
    while (i < player->width)
    {
        j = 0;
        while (j < player->height)
        {
            color = ft_image_getcolor(player->sprite, player->width * fac_x + i,
                                      player->height * fac_y + j);
            ft_image_putpixel(dest, player->x + i, player->y + j, color);
            j++;
        }
        i++;
    }
}

void	ft_player_state(t_player *player, char keys[256])
{
    int	total;

    total = (keys[KEY_A] != keys[KEY_D]) + (keys[KEY_S] != keys[KEY_W]);
    if (total == 0)
        player->state = STATE_IDLE;
    else
        player->state = STATE_WALK;
}

void	ft_player_way(t_player *player, char keys[256])
{
    int	total;

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

void	ft_player_render(t_animation *animation)
{
    static int	n = 0;
    t_player	*player;
    t_render	*render;
    t_engine	*engine;
    char		*keys;

    engine = animation->engine;
    render = animation->render;
    player = engine->player;
    keys = engine->keys;

    if(!engine->paused)
    {
        ft_player_state(player, keys);
        ft_player_way(player, keys);
        ft_player_move(player, keys);
        if (player->state == STATE_IDLE)
        n = 0;
    }
    ft_player_rect(player, render->back, n / PLAYER_FRAME_NBR);
    if(!engine->paused)
        n = (n + 1) % (8 * PLAYER_FRAME_NBR);
}

/*void ft_player_dead_in(t_animation * animation)*/
/*{*/
/*    t_sprite sprite;*/
/*    t_point point;*/
/*    static int n = 0;*/
/**/
/*    sprite.width = 1280;*/
/*    sprite.height = 960;*/
/*    point.x = animation->engine->player->x - sprite.width /2+ animation->engine->player->width / 2;*/
/*    point.y = animation->engine->player->y - sprite.height/2 + animation->engine->player->height / 2;*/
/*    sprite.x = (n/PLAYER_FRAME_NBR) * sprite.width ;*/
/*    sprite.y = 0;*/
/*    ft_sprite_toimage(animation->render->back,animation->sprite_fade,&sprite, &point);*/
/*    n = ft_min(n + 1,6 * PLAYER_FRAME_NBR - 1);*/
/*}*/
/**/
/*void ft_player_dead_out(t_animation * animation)*/
/*{*/
/*    t_sprite sprite;*/
/*    t_point point;*/
/*    static int n = 0;*/
/**/
/*    sprite.width = 1280;*/
/*    sprite.height = 960;*/
/*    point.x = animation->engine->player->x - sprite.width /2+ animation->engine->player->width / 2;*/
/*    point.y = animation->engine->player->y - sprite.height/2 + animation->engine->player->height / 2;*/
/*    sprite.x = (n/PLAYER_FRAME_NBR) * sprite.width ;*/
/*    sprite.y = sprite.height;*/
/*    ft_sprite_toimage(animation->render->back,animation->sprite_fade,&sprite, &point);*/
/*    n = ft_min(n + 1,6 * PLAYER_FRAME_NBR);*/
/*}*/
