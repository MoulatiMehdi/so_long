#include "so_long.h"
#include <stdbool.h>
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
    int test;

    test = 0;
    i = -1;
    while(i < 2)
    {
        j = -1;
        while(j < 2)
        {
            p.x = point->x + i;
            p.y = point->y + j;
            test <<= 1;
            if(is_valid_point(map, &p))
                test +=(map->data[p.y][p.x] == '1');
            else 
                test++;
            j++;
        }
        i++;
    }
    return test == 513;
}


bool ft_map_isleft_top(t_map * map,t_point *point)
{
    int arr [] = {510};
    t_point p;
    int i;
    int j;
    int test;

    test = 0;
    i = -1;
    while(i < 2)
    {
        j = -1;
        while(j < 2)
        {
            p.x = point->x + i;
            p.y = point->y + j;
            test <<= 1;
            if(is_valid_point(map, &p))
                test +=(map->data[p.y][p.x] == '1');
            else 
                test++;
            j++;
        }
        i++;
    }
    size_t k = 0;
    while(k < sizeof(arr))
    {
        if(arr[k] == test)
            return true;
        k++;
    }
    return false;
}

bool ft_map_isright_top(t_map * map,t_point *point)
{
    int arr [] = {447};
    t_point p;
    int i;
    int j;
    int test;

    test = 0;
    i = -1;
    while(i < 2)
    {
        j = -1;
        while(j < 2)
        {
            p.x = point->x + i;
            p.y = point->y + j;
            test <<= 1;
            if(is_valid_point(map, &p))
                test +=(map->data[p.y][p.x] == '1');
            else 
                test++;
            j++;
        }
        i++;
    }
    size_t k = 0;
    while(k < sizeof(arr))
    {
        if(arr[k] == test)
            return true;
        k++;
    }
    return false;
}

bool ft_map_isright_bottom(t_map * map,t_point *point)
{
    int arr [] = {255};
    t_point p;
    int i;
    int j;
    int test;

    test = 0;
    i = -1;
    while(i < 2)
    {
        j = -1;
        while(j < 2)
        {
            p.x = point->x + i;
            p.y = point->y + j;
            test <<= 1;
            if(is_valid_point(map, &p))
                test +=(map->data[p.y][p.x] == '1');
            else 
                test++;
            j++;
        }
        i++;
    }
    size_t k = 0;
    while(k < sizeof(arr))
    {
        if(arr[k] == test)
            return true;
        k++;
    }
    return false;
}


bool ft_map_isleft_bottom(t_map * map,t_point *point)
{
    int arr [] = {507};
    t_point p;
    int i;
    int j;
    int test;

    test = 0;
    i = -1;
    while(i < 2)
    {
        j = -1;
        while(j < 2)
        {
            p.x = point->x + i;
            p.y = point->y + j;
            test <<= 1;
            if(is_valid_point(map, &p))
                test +=(map->data[p.y][p.x] == '1');
            else 
                test++;
            j++;
        }
        i++;
    }
    size_t k = 0;
    while(k < sizeof(arr))
    {
        if(arr[k] == test)
            return true;
        k++;
    }
    return false;
}
