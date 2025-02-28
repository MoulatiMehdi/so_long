#include "image.h"
#include "libft/libft.h"
#include "so_long.h"
#include <stdio.h>
#include "wall.h"


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

void ft_map_fill_void(t_render * render,t_map * map)
{
    t_point point;
    t_sprite *sprite;
    int i;
    sprite = render->sprites[SPRITE_FLOOR];

    sprite->x = sprite->frame_width * 1;
    sprite->y = sprite->frame_height * 1;
    i = 0;
    while(i < WINDOW_HEIGHT / 2 - map->height * 32)
    {
        point.x = 0;
        while(point.x < WINDOW_WIDTH)
        {
            point.y = i;
            ft_render_sprite(render,sprite,&point);
            point.y = WINDOW_HEIGHT - i - sprite->frame_height;
            ft_render_sprite(render,sprite,&point);
            point.x += sprite->frame_width;
        }
        i += sprite->frame_height;
    }
    while(i < WINDOW_HEIGHT / 2 + map->height * 32)
    {
        point.x = 0;
        while(point.x < WINDOW_WIDTH / 2 - map->width * 32)
        {
            point.y = i;
            i = point.x;
            ft_render_sprite(render,sprite,&point);
            point.x = WINDOW_WIDTH - i - sprite->frame_width;
            ft_render_sprite(render,sprite,&point);
            point.x = i;
            i = point.y;
            point.x += sprite->frame_width;
        }
        i += sprite->frame_height;
    }

    i = 0;
}



void ft_map_wall_top(t_render * render,t_map * map)
{
    t_point idx;
    t_point shift;
    t_sprite * sprite_wall;    
    t_sprite * sprite_floor;

    sprite_floor = render->sprites[SPRITE_FLOOR];
    sprite_wall = render->sprites[SPRITE_WALL];
    idx.x = 0;
    while(idx.x < map->width)
    {
        idx.y = 0;
        while(idx.y  < map->height)
        {
            shift.x = WINDOW_WIDTH / 2 - map->width * 32 + idx.x * 64; 
            shift.y = WINDOW_HEIGHT / 2 - map->height * 32 + idx.y * 64;
            if(map->data[idx.y][idx.x] == '0')
                break;
            if(ft_map_isroof(map, &idx))
               ft_map_roof(render, &shift);
            else if(ft_map_ismiddle_top(map, &idx))
                ft_map_middle_top(render,&shift);
            else if(ft_map_isleft_top(map, &idx))
                ft_map_wall_left_top(render,&shift);
            else if(ft_map_isright_top(map, &idx))
                ft_map_wall_right_top(render,&shift);
            else 
                break;
            
            /*else if(ft_map_ismiddle_left(map, &idx))*/
            /*    ft_map_middle_left(render,&shift);*/
            /*else if(ft_map_ismiddle_right(map, &idx))*/
            /*    ft_map_middle_right(render,&shift);*/
            /*else if(ft_map_ismiddle_bottom(map, &idx))*/
            /*    ft_map_middle_bottom(render,&shift);*/
            /*if(ft_map_isright_bottom(map,&idx))*/
            /*    ft_map_wall_right_bottom(render,&shift);*/
            /*else if(ft_map_isleft_bottom(map,&idx))*/
            /*    ft_map_wall_left_bottom(render,&shift);*/

            idx.y ++;
        }
        idx.x ++;
    }
}

void ft_map_wall_bottom(t_render * render,t_map * map)
{
    t_point idx;
    t_point shift;
    t_sprite * sprite_wall;    
    t_sprite * sprite_floor;

    sprite_floor = render->sprites[SPRITE_FLOOR];
    sprite_wall = render->sprites[SPRITE_WALL];
    idx.x = 0;
    while(idx.x < map->width)
    {
        idx.y = map->height - 1;
        while(idx.y  >= 0)
        {
            shift.x = WINDOW_WIDTH / 2 - map->width * 32 + idx.x * 64; 
            shift.y = WINDOW_HEIGHT / 2 - map->height * 32 + idx.y * 64;
            if(map->data[idx.y][idx.x] == '0')
                break;
            if(ft_map_isroof(map, &idx))
               ft_map_roof(render, &shift);
            else if(ft_map_ismiddle_bottom(map, &idx))
                ft_map_middle_bottom(render,&shift);
            else if(ft_map_isright_bottom(map,&idx))
                ft_map_wall_right_bottom(render,&shift);
            else if(ft_map_isleft_bottom(map,&idx))
                ft_map_wall_left_bottom(render,&shift);
            else 
                break;
            idx.y --;
        }
        idx.x ++;
    }
}


void ft_map_wall_left(t_render * render,t_map * map)
{
    t_point idx;
    t_point shift;
    t_sprite * sprite_wall;    
    t_sprite * sprite_floor;

    sprite_floor = render->sprites[SPRITE_FLOOR];
    sprite_wall = render->sprites[SPRITE_WALL];
    idx.y = 0;
    while(idx.y < map->height)
    {
        idx.x = 0;
        while(idx.x  < map->width)
        {
            shift.x = WINDOW_WIDTH / 2 - map->width * 32 + idx.x * 64; 
            shift.y = WINDOW_HEIGHT / 2 - map->height * 32 + idx.y * 64;
            if(map->data[idx.y][idx.x] == '0')
                break;
            if(ft_map_isroof(map, &idx))
               ft_map_roof(render, &shift);
            else if(ft_map_ismiddle_left(map, &idx))
                ft_map_middle_left(render,&shift);
            else 
                break;
            idx.x ++;
        }
        idx.y ++;
    }
}

void ft_map_wall_right(t_render * render,t_map * map)
{
    t_point idx;
    t_point shift;
    t_sprite * sprite_wall;    
    t_sprite * sprite_floor;

    sprite_floor = render->sprites[SPRITE_FLOOR];
    sprite_wall = render->sprites[SPRITE_WALL];
    idx.y = 0;
    while(idx.y < map->height)
    {
        idx.x = map->width - 1;
        while(idx.x  >= 0)
        {
            shift.x = WINDOW_WIDTH / 2 - map->width * 32 + idx.x * 64; 
            shift.y = WINDOW_HEIGHT / 2 - map->height * 32 + idx.y * 64;
            if(map->data[idx.y][idx.x] == '0')
                break;
            if(ft_map_isroof(map, &idx))
               ft_map_roof(render, &shift);
            else if(ft_map_ismiddle_right(map, &idx))
                ft_map_middle_right(render,&shift);
            else 
                break;
            idx.x --;
        }
        idx.y ++;
    }
}
void ft_map_wall_outside(t_render * render,t_map * map)
{
    t_point idx;
    t_point shift;
    t_sprite * sprite_wall;    
    t_sprite * sprite_floor;

    sprite_floor = render->sprites[SPRITE_FLOOR];
    sprite_wall = render->sprites[SPRITE_WALL];
    idx.y = 0;
    while(idx.y < map->height)
    {
        idx.x = 0;
        while(idx.x  < map->width)
        {
            shift.x = WINDOW_WIDTH / 2 - map->width * 32 + idx.x * 64; 
            shift.y = WINDOW_HEIGHT / 2 - map->height * 32 + idx.y * 64;
            if(map->data[idx.y][idx.x] == '0')
                break;
            if(map->data[idx.y][idx.x] == '0')
               ft_map_floor_blue(render,&shift); 
            else if(ft_map_outside_isleft_bottom(map, &idx))
                ft_map_outside_left_bottom(render,&shift);
            else if(ft_map_outside_isright_bottom(map, &idx))
                ft_map_outside_right_bottom(render,&shift);
            else if(ft_map_outside_isright_top(map,&idx))
                ft_map_outside_right_top(render,&shift);
            else if(ft_map_outside_isleft_top(map,&idx))
                ft_map_outside_left_top(render,&shift);
            idx.x ++;
        }
        idx.y ++;
    }
}


void ft_map_display(t_render * render,t_map * map)
{
    ft_map_fill_void(render, map);
    ft_map_wall_top(render, map);
    ft_map_wall_bottom(render, map);
    ft_map_wall_left(render, map);
    ft_map_wall_right(render, map);
    /*ft_map_wall_outside(render, map);*/
}

t_map *ft_map_new(char ** array)
{
    t_map * map;
    if(!array)
        return NULL;
    map = malloc(sizeof(t_map));
    if(!map)
        return NULL;
    map->data = array;
    map->width = ft_strlen(array[0]);
    map->height = 0;
    while(array[map->height])
        map->height ++;
    return map;
}
