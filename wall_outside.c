#include "so_long.h"

bool ft_map_outside_isleft_top(t_map * map,t_point *point)
{
    t_point p;
    int j;
    bool isroof;
 
    if(point->x == 0)
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
            isroof = isroof && map->data[p.y][p.x] == "10"[j];
        p.x = point->x - 1;
        p.y = point->y - j;
        if(is_valid_point(map, &p))
            isroof = isroof && map->data[p.y][p.x] == "00"[j];
        j++;
    }
    return isroof;
}

bool ft_map_outside_isright_top(t_map * map,t_point *point)
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
            isroof = isroof && map->data[p.y][p.x] == "10"[j];
        p.x = point->x + 1;
        p.y = point->y - j;
        if(is_valid_point(map, &p))
            isroof = isroof && map->data[p.y][p.x] == "00"[j];
        j++;
    }
    return isroof;
}

bool ft_map_outside_isright_bottom(t_map * map,t_point *point)
{
    t_point p;
    int j;
    bool isroof;
 
    if(point->y ==  map->height - 1)
        return false;
    if(point->x ==  map->width - 1)
        return false;
    isroof = true;
    j = 0;
    while(j < 2)
    {
        p.x = point->x;
        p.y = point->y + j;
        if(is_valid_point(map, &p))
            isroof = isroof && map->data[p.y][p.x] == "10"[j];
        p.x = point->x + 1;
        p.y = point->y + j;
        if(is_valid_point(map, &p))
            isroof = isroof && map->data[p.y][p.x] == "00"[j];
        j++;
    }
    return isroof;
}

bool ft_map_outside_isleft_bottom(t_map * map,t_point *point)
{
    t_point p;
    int j;
    bool isroof;
  
    if(point->x == 0)
        return false;
    if(point->y == map->height  - 1)
        return false;
    isroof = true;
    j = 0;
    while(j < 2)
    {
        p.x = point->x;
        p.y = point->y + j;
        if(is_valid_point(map, &p))
            isroof = isroof && map->data[p.y][p.x] == "10"[j];
        p.x = point->x - 1;
        p.y = point->y + j;
        if(is_valid_point(map, &p))
            isroof = isroof && map->data[p.y][p.x] == "00"[j];
        j++;
    }
    return isroof;
}
