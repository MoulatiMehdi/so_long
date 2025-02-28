#include "so_long.h"
#include <stdio.h>

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

bool ft_map_ismiddle_left(t_map * map,t_point *point)
{
    t_point p;
    int j;
    bool isroof;
   
    if(point->x == map->width - 1)
        return false;
    isroof = true;
    j = -1;
    while(j < 2)
    {
        p.x = point->x + j;
        p.y = point->y ;
        if(is_valid_point(map, &p))
            isroof = isroof && map->data[p.y][p.x] == "110"[j + 1];
        p.x = point->x ;
        p.y = point->y + j;
        if(is_valid_point(map, &p))
            isroof = isroof && map->data[p.y][p.x] == '1';
        j++;
    }
    return isroof;
}


bool ft_map_ismiddle_right(t_map * map,t_point *point)
{
    t_point p;
    int j;
    bool isroof;
   
    if(point->x == 0)
        return false;
    isroof = true;
    j = -1;
    while(j < 2)
    {
        p.x = point->x - j;
        p.y = point->y; 
        if(is_valid_point(map, &p))
            isroof = isroof && map->data[p.y][p.x] == "110"[j + 1];
        p.x = point->x ;
        p.y = point->y+ j;
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
    j = -1;
    while(j < 2)
    {
        p.x = point->x + j;
        p.y = point->y ;
        if(is_valid_point(map, &p))
            isroof = isroof && map->data[p.y][p.x] == "111"[j + 1];
        p.x = point->x + j;
        p.y = point->y + 1;
        if(is_valid_point(map, &p))
            isroof = isroof && map->data[p.y][p.x] == "110"[j + 1];
        j++;
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
    j = -1;
    while(j < 2)
    {
        p.x = point->x + j;
        p.y = point->y ;
        if(is_valid_point(map, &p))
            isroof = isroof && map->data[p.y][p.x] == "111"[j + 1];
        p.x = point->x + j;
        p.y = point->y + 1;
        if(is_valid_point(map, &p))
            isroof = isroof && map->data[p.y][p.x] == "011"[j + 1];
        j++;
    }
    return isroof;
}

void ft_map_grid(t_map * map,t_point *point)
{
    int i = 0;
    int j = 0;
    int c;
    while(i < map->height)
    {
        j = 0;
        while(j < map->width)
        {
            if(i == point->y && j == point->x)
                printf("\033[45;1m%c \033[0m",map->data[i][j]); 
            else 
                printf("%c ",map->data[i][j]); 
            j++;
        }
        printf("\n");
        i++;
    }
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
    j = -1;
    while(j < 2)
    {
        p.x = point->x + j;
        p.y = point->y ;
        if(is_valid_point(map, &p))
            isroof = isroof && map->data[p.y][p.x] == "111"[j + 1];
        p.x = point->x + j;
        p.y = point->y - 1;
        if(is_valid_point(map, &p))
            isroof = isroof && map->data[p.y][p.x] == "011"[j + 1];
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
    j = -1;
    while(j < 2)
    {
        p.x = point->x + j;
        p.y = point->y ;
        if(is_valid_point(map, &p))
            isroof = isroof && map->data[p.y][p.x] == "111"[j + 1];
        p.x = point->x + j;
        p.y = point->y - 1;
        if(is_valid_point(map, &p))
            isroof = isroof && map->data[p.y][p.x] == "110"[j + 1];
        j++;
    }
    return isroof;
}
