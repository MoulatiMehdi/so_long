#include "image.h"
#include "libft/libft.h"
#include "so_long.h"
#include <stdio.h>


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

void ft_map_wall_right_bottom(t_render * render,t_point * point)
{
    t_sprite * sprite;

    sprite = render->sprites[SPRITE_WALL];
    sprite->x = sprite->frame_width * 3;
    sprite->y = 0;
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

    sprite->x = sprite->frame_width * 0;
    sprite->y = sprite->frame_height * 3;
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

bool is_valid_point(t_map * map,t_point* point)
{
    return point->x >=0  && point->y >= 0 && point->y < map->height  && point->x < map->width;
}


bool ft_map_isroof(t_map * map,t_point *point)
{
    t_point p;
    int i;
    int j;
    bool isroof;
    isroof = true;
    i = -1;
    while(i < 2)
    {
        j = -1;
        while(j < 2)
        {
            p.x = point->x - i;
            p.y = point->y - j;
            if(is_valid_point(map, &p))
                isroof = isroof && (map->data[p.y][p.x] == '1');
            j++;
        }
        i++;
    }
    return isroof;
}

bool ft_map_ismiddle_top(t_map * map,t_point *point)
{
    t_point p;
    int j;
    bool isroof;
   
    if(point->y == map->height - 1)
        return false;
    isroof = true;
    j = -1;
    while(j < 2)
    {
        p.x = point->x;
        p.y = point->y + j;
        if(is_valid_point(map, &p))
            isroof = isroof && map->data[p.y][p.x] == "110"[j + 1];
        p.x = point->x + j;
        p.y = point->y;
        if(is_valid_point(map, &p))
            isroof = isroof && map->data[p.y][p.x] == '1';
        j++;
    }
    return isroof;
}

bool ft_map_ismiddle_bottom(t_map * map,t_point *point)
{
    t_point p;
    int j;
    bool isroof;
   
    if(point->y == 0)
        return false;
    isroof = true;
    j = -1;
    while(j < 2)
    {
        p.x = point->x;
        p.y = point->y - j;
        if(is_valid_point(map, &p))
            isroof = isroof && map->data[p.y][p.x] == "110"[j + 1];
        p.x = point->x - j;
        p.y = point->y;
        if(is_valid_point(map, &p))
            isroof = isroof && map->data[p.y][p.x] == '1';
        j++;
    }
    return isroof;
}

bool ft_map_isleft_top(t_map * map,t_point *point)
{
    t_point p;
    int j;
    bool isroof;
   
    if(point->y == map->height - 1)
        return false;
    if(point->x == map->width - 1)
        return false;
    isroof = true;
    j = 0;
    while(j < 2)
    {
        p.x = point->x;
        p.y = point->y + j;
        if(is_valid_point(map, &p))
        {
            isroof = isroof && map->data[p.y][p.x] == "11"[j];
        }  
        p.x = point->x + 1;
        p.y = point->y + j;
        if(is_valid_point(map, &p))
        {
            isroof = isroof && map->data[p.y][p.x] == "10"[j];
        }   j++;
    }
    return isroof;
}

bool ft_map_isright_top(t_map * map,t_point *point)
{
    t_point p;
    int j;
    bool isroof;
   
    if(point->x == 0)
        return false;
    if(point->y == map->height - 1)
        return false;
    isroof = true;
    j = 0;

    // j == 0 
    while(j < 2)
    {
        p.x = point->x;
        p.y = point->y + j;
        if(is_valid_point(map, &p))
            isroof = isroof && map->data[p.y][p.x] == "11"[j];
        j++;
    }
    j = 0; 
    while(j < 2)
    {
        p.x = point->x - 1;
        p.y = point->y + j;
        if(is_valid_point(map, &p))
            isroof = isroof && map->data[p.y][p.x] == "10"[j];
        j++;
    }
    return isroof;
}

bool ft_map_isright_bottom(t_map * map,t_point *point)
{
    t_point p;
    int j;
    bool isroof;
  
    if(point->y == 0)
        return false;
    if(point->x == 0)
        return false;
    isroof = true;
    j = 0;
    while(j < 2)
    {
        p.x = point->x;
        p.y = point->y - j;
        if(is_valid_point(map, &p))
            isroof = isroof && map->data[p.y][p.x] == "11"[j];
        p.x = point->x - 1;
        p.y = point->y - j;
        if(is_valid_point(map, &p))
            isroof = isroof && map->data[p.y][p.x] == "10"[j];
        j++;
    }
    return isroof;
}


bool ft_map_isleft_bottom(t_map * map,t_point *point)
{
    t_point p;
    int j;
    bool isroof;
  
    if(point->x == map->width - 1)
        return false;
    if(point->y == 0)
        return false;
    isroof = true;
    j = 0;
    while(j < 2)
    {
        p.x = point->x;
        p.y = point->y - j;
        if(is_valid_point(map, &p))
            isroof = isroof && map->data[p.y][p.x] == "11"[j];
        p.x = point->x + 1;
        p.y = point->y - j;
        if(is_valid_point(map, &p))
            isroof = isroof && map->data[p.y][p.x] == "10"[j];
        j++;
    }
    return isroof;
}
void ft_map_wall_inside(t_render * render,t_map * map)
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
            if(!is_valid_point(map,&idx) || map->data[idx.y][idx.x] == 0)
                break;
            shift.x = WINDOW_WIDTH / 2 - map->width * 32 + idx.x * 64; 
            shift.y = WINDOW_HEIGHT / 2 - map->height * 32 + idx.y * 64; 
            if(ft_map_isroof(map, &idx))
                ft_map_roof(render, &shift);
            else if(ft_map_ismiddle_top(map, &idx))
                ft_map_middle_top(render,&shift);
            else if(ft_map_ismiddle_bottom(map, &idx))
                ft_map_middle_bottom(render,&shift);
            else if(ft_map_isleft_top(map, &idx))
                ft_map_wall_left_top(render,&shift);
            else if(ft_map_isright_top(map, &idx))
                ft_map_wall_right_top(render,&shift);
            else if(ft_map_isright_bottom(map,&idx))
                ft_map_wall_right_bottom(render,&shift);
            else if(ft_map_isleft_bottom(map,&idx))
                ft_map_wall_left_bottom(render,&shift);
            idx.y ++;
        }
        idx.x ++;
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
    idx.x = 0;
    while(idx.y < map->height)
    {
        idx.x = 0;
        while(idx.x  < map->width)
        {
            if(!is_valid_point(map,&idx) || map->data[idx.y][idx.x] == 0)
                break;
            shift.x = WINDOW_WIDTH / 2 - map->width * 32 + idx.x * 64; 
            shift.y = WINDOW_HEIGHT / 2 - map->height * 32 + idx.y * 64; 
            if(ft_map_isroof(map, &idx))
                ft_map_roof(render, &shift);
            else if(ft_map_ismiddle_top(map, &idx))
                ft_map_middle_top(render,&shift);
            else if(ft_map_ismiddle_bottom(map, &idx))
                ft_map_middle_bottom(render,&shift);
            else if(ft_map_isleft_top(map, &idx))
                ft_map_wall_left_top(render,&shift);
            else if(ft_map_isright_top(map, &idx))
                ft_map_wall_right_top(render,&shift);
            else if(ft_map_isright_bottom(map,&idx))
                ft_map_wall_right_bottom(render,&shift);
            else if(ft_map_isleft_bottom(map,&idx))
                ft_map_wall_left_bottom(render,&shift);
            idx.y ++;
        }
        idx.x ++;
    }
}


void ft_map_display(t_render * render,t_map * map)
{
    ft_map_fill_void(render, map);
    ft_map_wall_inside(render, map);
    ft_map_wall_outside(render, map);   
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
