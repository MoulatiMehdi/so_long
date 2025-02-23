#include "player.h"
#include "so_long.h"

void ft_player_star(t_player *player, t_render *render)
{
    static unsigned int i = 0;
    t_sprite	*sprite;
    t_point		point;
    bool is_h;

    is_h = player->way == WAY_LEFT || player->way == WAY_RIGHT;
    point.x = player->x;
    point.y = player->y;
    if(player->way == WAY_LEFT)
    {
        point.x = player->x - 24;
        point.y = player->y + 28;
    }
    if(player->way == WAY_RIGHT)
    {
        point.x = player->x + 28;
        point.y = player->y + 28;
    }
    if(player->way == WAY_DOWN)
    {
        point.x = player->x + 12;
        point.y = player->y + 46;
    }
    if(is_h)
        sprite = render->sprites[SPRITE_STAR_LOADING_V];
    else 
        sprite = render->sprites[SPRITE_STAR_LOADING_H];

    if(player->is_loaded &&  i  >= sprite->loop * (sprite->col * (sprite->row/2) - is_h))
            i = 22 * sprite->loop  * player->is_loaded;
    if(player->charge == 0)
        i = 0;
    sprite->x = sprite->frame_width * ((i / sprite->loop )% sprite->col);
    sprite->y =  sprite->frame_height * ((i / (sprite->loop * sprite->col) )% (sprite->row /2));
    if(player->way == WAY_LEFT ||  player->way == WAY_DOWN)
        sprite->y += sprite->frame_height * (sprite->row / 2);
    ft_render_sprite(render, sprite, &point);
    i ++;
}

void	ft_player_attack(t_player *player, t_render *render)
{
    t_sprite	*sprite;
    t_sprite	*sprite_sword;
    t_point		point;

    sprite = render->sprites[SPRITE_LINK_ATTACKING];
    sprite_sword = render->sprites[SPRITE_SWORD_ATTACK];
    sprite->x = sprite->frame_width * (player->frame_on_loop / sprite->loop);
    sprite->y = sprite->frame_height * player->way;
    sprite_sword->x = sprite_sword->frame_width * (player->frame_on_loop
        / sprite_sword->loop);
    sprite_sword->y = sprite_sword->frame_height * player->way;
    point.x = player->x - 8;
    point.y = player->y;
    ft_render_sprite(render, sprite, &point);
    point.x = player->x - 48;
    point.y = player->y - 28;
    ft_render_sprite(render, sprite_sword, &point);
    if (player->frame_on_loop == sprite->col * sprite->loop - 1)
        player->is_state_fixed = false;
    player->frame_on_loop = (player->frame_on_loop + 1) % (sprite->col
        * sprite->loop);
}

void	ft_player_spinning(t_player *player, t_render *render)
{
    t_sprite	*sprite_spin;
    t_sprite	*sprite_sword;
    t_point		point;

    sprite_spin = render->sprites[SPRITE_LINK_SPIN];
    sprite_sword = render->sprites[SPRITE_SWORD_SPIN];
    sprite_spin->y = sprite_spin->frame_height * player->way;
    sprite_sword->y = sprite_sword->frame_height * player->way;
    sprite_spin->x = sprite_spin->frame_width * (player->frame_on_loop
        / sprite_spin->loop);
    sprite_sword->x = sprite_sword->frame_width * (player->frame_on_loop
        / sprite_sword->loop);
    point.x = player->x;
    point.y = player->y + 16;
    ft_render_sprite(render, sprite_spin, &point);
    point.x = player->x - 40;
    point.y = player->y - 20;
    ft_render_sprite(render, sprite_sword, &point);
    if (player->frame_on_loop + 1 == sprite_sword->col * sprite_spin->loop)
    {
        player->is_state_fixed = false;
        player->is_loaded = false;
    }
    player->frame_on_loop = (player->frame_on_loop + 1) % (sprite_sword->col
        * sprite_sword->loop);
}

void	ft_player_loading(t_player *player, t_render *render)
{
    t_sprite	*sprite_link;
    t_sprite	*sprite_sword;
    t_point		point;

    sprite_link = render->sprites[SPRITE_LINK_LOADING];
    sprite_sword = render->sprites[SPRITE_SWORD_LOADING];
    sprite_link->x = sprite_link->frame_width * (player->frame_on_loop
        / sprite_link->loop);
    sprite_link->y = sprite_link->frame_height * player->way;
    sprite_sword->x = sprite_sword->frame_width * (player->frame_on_loop
        / sprite_sword->loop);
    sprite_sword->y = sprite_sword->frame_height * player->way;
    if (!player->is_moving)
    {
        sprite_sword->x = 0;
        sprite_link->x = 0;
        player->frame_on_loop = 0;
    }
    if (sprite_link->col * sprite_link->loop > player->charge)
        player->charge++;
    else
        player->is_loaded = true;
    point.x = player->x - 16;
    point.y = player->y + 4;
    ft_render_sprite(render, sprite_sword, &point);
    point.x = player->x;
    point.y = player->y;
    ft_render_sprite(render, sprite_link, &point);
    ft_player_star(player, render);
    player->frame_on_loop = (player->frame_on_loop + 1) % (sprite_link->col
        * sprite_link->loop);
}
