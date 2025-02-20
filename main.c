#include "color.h"
#include "image.h"
#include "libft/libft.h"
#include "mlx.h"
#include "so_long.h"
#include <unistd.h>
#include "player.h"

#define PLAYER_HEARTS_TOTAL 6
#define PLAYER_STATUS_X (WINDOW_WIDTH / 2 - 128)

void ft_number_render(t_animation* animation,t_point * point,int nbr,int digits)
{
    int i;
    t_sprite sprite;
    
    sprite.x = 0;
    sprite.y = 0;
    sprite.width = 16;
    sprite.height = 16;
    i = 0;
    while(i < digits)
    {
        sprite.x =(nbr % 10)* sprite.width; 
        ft_sprite_toimage(animation->render->back,animation->sprite_digits, &sprite, point);
        point->x -= sprite.width;
        nbr /=10;
        i++;
    }
}

void ft_coin_render(t_animation * animation)
{
    t_sprite sprite;
    t_point point;
    int coin;

    point.x = PLAYER_STATUS_X ;
    point.y = 32;
    sprite.x = 0;
    sprite.y = 0;
    sprite.width = 16;
    sprite.height = 16;
    ft_sprite_toimage(animation->render->back,animation->sprite_coin,&sprite, &point);
    point.y += sprite.height + 8;
    point.x += sprite.width;
    coin = animation->engine->player->coins;
    if(coin > 999)
        coin = 999;
    ft_number_render(animation, &point,coin , 3);
}

void ft_moves_render(t_animation * animation)
{
    t_sprite sprite;
    t_point point;
    int coin;

    point.x = PLAYER_STATUS_X + 6 * 16;
    point.y = 32;
    sprite.x = 0;
    sprite.y = 0;
    sprite.width = 16;
    sprite.height = 16;
    ft_sprite_toimage(animation->render->back,animation->sprite_shoes,&sprite, &point);
    point.y += sprite.height + 8;
    point.x += sprite.width * 3;
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
    
    /*sprite.width = 1280;*/
    /*sprite.height = 960;*/
    /*point.x = animation->engine->player->x - sprite.width /2+ animation->engine->player->width / 2;*/
    /*point.y = animation->engine->player->y - sprite.height/2 + animation->engine->player->height / 2;*/
    /*sprite.x = (n/PLAYER_FRAME_NBR) * sprite.width ;*/
    /*sprite.y = 0;*/
    /*ft_sprite_toimage(animation->render->back,animation->sprite_fade,&sprite, &point);*/
    /*n = (n + 1) %(8 * PLAYER_FRAME_NBR);*/
    point.x = animation->engine->player->x + animation->engine->player->width /2; 
    point.y = animation->engine->player->y + animation->engine->player->height /2;
    sprite.width = (6 - n / PLAYER_FRAME_NBR - 1) * animation->engine->player->width;
    sprite.height = (6 - n / PLAYER_FRAME_NBR - 1) * animation->engine->player->height/2;
    ft_image_ellipse(animation->render->back,&sprite,&point, 0X0000FF00);    
    n = ft_min(n + 1,6 * PLAYER_FRAME_NBR - 1);
}

void ft_hearts_render(t_animation * animation)
{
    t_sprite sprite;
    t_point point;
    int heart;
    int i;

    heart = animation->engine->player->hearts;
    point.x = WINDOW_WIDTH / 2 + 48 * 3;
    point.y = 48;
    sprite.width = 16;
    sprite.height = 16;
    sprite.y = 0;
    i = 0; 
    while(i < PLAYER_HEARTS_TOTAL/2)
    {

        sprite.x = sprite.width* (2 - ft_min(2,heart));
        ft_sprite_toimage(animation->render->back,animation->sprite_hearts,&sprite, &point);
        point.x +=sprite.width;
        heart = ft_max(heart - 2,0);
        i ++;
    }
}
int	ft_animation_update(t_animation *animation)
{

    ft_image_fill(animation->render->back, 0X00FFFFFF);
    
    ft_player_dead(animation);
    ft_player_render(animation);
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
    animation.sprite_debug = ft_image_from_xpm(engine->mlx,"./textures/xpm/debug.xpm");
    animation.sprite_coin = ft_image_from_xpm(engine->mlx,"./textures/xpm/coin.xpm");
    animation.sprite_digits = ft_image_from_xpm(engine->mlx,"./textures/xpm/digits.xpm");
    animation.sprite_shoes = ft_image_from_xpm(engine->mlx,"./textures/xpm/cape.xpm");
    animation.sprite_hearts = ft_image_from_xpm(engine->mlx,"./textures/xpm/hearts.xpm");
    animation.sprite_fade = ft_image_from_xpm(engine->mlx,"./textures/xpm/fade.xpm");
    mlx_loop_hook(engine->mlx, ft_animation_update,&animation);
    mlx_loop(engine->mlx);
}
