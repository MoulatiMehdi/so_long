#include "color.h"
#include "image.h"
#include "libft/libft.h"
#include "mlx.h"
#include "so_long.h"
#include <stdlib.h>
#include <unistd.h>
#include "player.h"

#define PLAYER_HEARTS_TOTAL 6
#define PLAYER_STATUS_X (WINDOW_WIDTH / 2 - 128)
#define FADE_FRAME_NBR 8

void ft_number_render(t_animation* animation,t_point * point,int nbr,int digits)
{
    int i;
    t_sprite *sprite;
   
    sprite = animation->render->sprites[SPRITE_DIGITS];
    sprite->y = 0;
    i = 0;
    while(i < digits)
    {
        sprite->x =(nbr % 10)* sprite->frame_width; 
        ft_sprite_toimage(animation->render->back,sprite, point);
        point->x -= sprite->frame_width;
        nbr /=10;
        i++;
    }
}

void ft_coin_render(t_animation * animation)
{
    t_sprite *sprite;
    t_point point;
    int coin;

    sprite = animation->render->sprites[SPRITE_COIN];
    point.x = PLAYER_STATUS_X ;
    point.y = 32;
    sprite->x = 0;
    sprite->y = 0;
    ft_sprite_toimage(animation->render->back,sprite, &point);
    point.y += sprite->frame_height + 8;
    point.x += sprite->frame_width;
    coin = animation->engine->player->coins;
    if(coin > 999)
        coin = 999;
    ft_number_render(animation, &point,coin , 3);
}

void ft_moves_render(t_animation * animation)
{
    t_sprite *sprite;
    t_point point;
    int coin;

    sprite = animation->render->sprites[SPRITE_CAPE];
    point.x = PLAYER_STATUS_X + 6 * 16;
    point.y = 32;
    sprite->x = 0;
    sprite->y = 0;
    ft_sprite_toimage(animation->render->back,sprite, &point);
    point.y += sprite->frame_height + 8;
    point.x += sprite->frame_width * 3;
    coin = animation->engine->player->moves;
    if(coin > 9999999)
        coin = 9999999;
    ft_number_render(animation, &point ,coin,7);
}

void ft_player_dead(t_animation * animation)
{
    t_sprite sprite;
    t_point point;
    static int n = 0;
    int color;

    color = 0X00000000;
    
    /*sprite.width = 1280;*/
    /*sprite.height = 960;*/
    /*point.x = animation->engine->player->x - sprite.width /2+ animation->engine->player->width / 2;*/
    /*point.y = animation->engine->player->y - sprite.height/2 + animation->engine->player->height / 2;*/
    /*sprite.x = (n/PLAYER_FRAME_NBR) * sprite.width ;*/
    /*sprite.y = 0;*/
    /*ft_sprite_toimage(animation->render->back,animation->sprite_fade,&sprite, &point);*/
    /*n = (n + 1) %(8 * PLAYER_FRAME_NBR);*/
    if(n == FADE_FRAME_NBR)
        color = 0X00FF0000;
    point.x = animation->engine->player->x + animation->engine->player->width /2; 
    point.y = animation->engine->player->y + animation->engine->player->height *3 /4;
    sprite.frame_width = (FADE_FRAME_NBR - n) * animation->engine->player->width;
    sprite.frame_height = ( FADE_FRAME_NBR - n) * animation->engine->player->height/2;
    ft_image_ellipse(animation->render->back,&sprite,&point, color);    
    n = ft_min(n + 1,FADE_FRAME_NBR);
}

void ft_hearts_render(t_animation * animation)
{
    t_sprite *sprite;
    t_point point;
    int heart;
    int i;

    sprite = animation->render->sprites[SPRITE_HEARTS];
    heart = animation->engine->player->hearts;
    point.x = WINDOW_WIDTH / 2 + 48 * 3;
    point.y = 48;
    sprite->y = 0;
    i = 0; 
    while(i < PLAYER_HEARTS_TOTAL/2)
    {
        sprite->x = sprite->frame_width* (2 - ft_min(2,heart));
        ft_sprite_toimage(animation->render->back,sprite, &point);
        point.x +=sprite->frame_width;
        heart = ft_max(heart - 2,0);
        i ++;
    }
}
int	ft_animation_update(t_animation *animation)
{


    ft_image_fill(animation->render->back, 0X00FF00FF);
    if(animation->engine->player->moves > 200)
        animation->engine->player->hearts = 0;
    ft_player_render(animation);
    ft_player_debug(animation->engine->player);
    ft_hearts_render(animation);
    ft_coin_render(animation);
    ft_moves_render(animation);
    ft_key_debug(animation);
    ft_image_grid(animation->render->back, 16,16, 0x0000FF00);
    ft_render_display(animation->render);
    return (0);
}




int	main(void)
{
    t_animation	animation;
    t_engine	*engine;
    t_render	*render;

    engine = ft_engine_new();
    render = ft_render_new(engine->mlx, engine->window);
    animation.render = render;
    animation.engine = engine;
    mlx_loop_hook(engine->mlx, ft_animation_update,&animation);
    mlx_loop(engine->mlx);
}
