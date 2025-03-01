#include "so_long.h"

void ft_map_wall_left_top(t_render * render,t_point * point)
{
    t_sprite * sprite;

    sprite = render->sprites[SPRITE_WALL];
    sprite->x = 0;
    sprite->y = 0;
    ft_render_sprite(render, sprite, point);
}

void ft_map_wall_right_top(t_render * render,t_point * point)
{
    t_sprite * sprite;

    sprite = render->sprites[SPRITE_WALL];
    sprite->x = sprite->frame_width * 2;
    sprite->y = 0;
    ft_render_sprite(render, sprite, point);
}

void ft_map_outside_left_top(t_render * render,t_point * point)
{
    t_sprite * sprite;

    sprite = render->sprites[SPRITE_WALL];
    sprite->x = sprite->frame_width * 0;
    sprite->y = sprite->frame_height * 2;
    ft_render_sprite(render, sprite, point);
}

void ft_map_wall_right_bottom(t_render * render,t_point * point)
{
    t_sprite * sprite;

    sprite = render->sprites[SPRITE_WALL];
    sprite->x = sprite->frame_width * 3;
    sprite->y = 0;
    ft_render_sprite(render, sprite, point);
}

void ft_map_outside_left_bottom(t_render * render,t_point * point)
{
    t_sprite * sprite;

    sprite = render->sprites[SPRITE_WALL];
    sprite->x = sprite->frame_width * 1;
    sprite->y = sprite->frame_height * 2;
    ft_render_sprite(render, sprite, point);
}

void ft_map_outside_right_bottom(t_render * render,t_point * point)
{
    t_sprite * sprite;

    sprite = render->sprites[SPRITE_WALL];
    sprite->x = sprite->frame_width * 3;
    sprite->y = sprite->frame_height * 2;
    ft_render_sprite(render, sprite, point);
}

void ft_map_outside_right_top(t_render * render,t_point * point)
{
    t_sprite * sprite;

    sprite = render->sprites[SPRITE_WALL];
    sprite->x = sprite->frame_width * 2;
    sprite->y = sprite->frame_height * 2;
    ft_render_sprite(render, sprite, point);
}


void ft_map_wall_left_bottom(t_render * render,t_point * point)
{
    t_sprite * sprite;

    sprite = render->sprites[SPRITE_WALL];
    sprite->x = sprite->frame_width * 1;
    sprite->y = 0;
    ft_render_sprite(render, sprite, point);
}

void ft_map_middle_top(t_render * render,t_point * point)
{
    t_sprite * sprite;

    sprite = render->sprites[SPRITE_WALL];
    sprite->y = sprite->frame_height * 1;
    sprite->x = sprite->frame_width * 3;
    ft_render_sprite(render, sprite, point);
}

void ft_map_middle_bottom(t_render * render,t_point * point)
{
    t_sprite * sprite;

    sprite = render->sprites[SPRITE_WALL];
    sprite->y = sprite->frame_height * 1;
    sprite->x = sprite->frame_width * 1;
    ft_render_sprite(render, sprite, point);
}

void ft_map_middle_left(t_render * render,t_point * point)
{
    t_sprite * sprite;

    sprite = render->sprites[SPRITE_WALL];
    sprite->y = sprite->frame_height * 1;
    sprite->x = sprite->frame_width * 0;
    ft_render_sprite(render, sprite, point);
}

void ft_map_middle_right(t_render * render,t_point * point)
{
    t_sprite * sprite;

    sprite = render->sprites[SPRITE_WALL];
    sprite->y = sprite->frame_height * 1;
    sprite->x = sprite->frame_width * 2;
    ft_render_sprite(render, sprite, point);
}
void ft_map_floor_blue(t_render * render,t_point * point)
{
    t_point  shift;
    t_sprite * sprite;
    int i;
    int j;

    shift.x = point->x;
    shift.y = point->y;
    sprite = render->sprites[SPRITE_FLOOR];
    sprite->y = sprite->frame_height * 3;
    sprite->x = sprite->frame_width * 1;
    i = 0;
    while(i* sprite->frame_width < 64)
    {
        j = 0;
        while(j * sprite->frame_height< 64)
        {
            shift.x =  point->x + i * sprite->frame_width;
            shift.y =  point->y + j * sprite->frame_height;
            ft_render_sprite(render, sprite, &shift);
            j++;
        }
        i++;
    }
}

void ft_map_roof(t_render * render,t_point * point)
{
    t_point  shift;
    t_sprite * sprite;
    int i;
    int j;

    shift.x = point->x;
    shift.y = point->y;
    sprite = render->sprites[SPRITE_FLOOR];
    sprite->y = sprite->frame_height * 3;
    sprite->x = sprite->frame_width * 2;
    i = 0;
    while(i* sprite->frame_width < 64)
    {
        j = 0;
        while(j * sprite->frame_height< 64)
        {
            shift.x =  point->x + i * sprite->frame_width;
            shift.y =  point->y + j * sprite->frame_height;
            ft_render_sprite(render, sprite, &shift);
            j++;
        }
        i++;
    }
}
