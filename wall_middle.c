#include "so_long.h"

bool ft_map_ismiddle_top(t_map * map,t_point *point)
{
    int arr [] = {503,502,446,439,438};
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

bool ft_map_ismiddle_bottom(t_map * map,t_point *point)
{
    int arr [] = {251, 219,223,479,475};
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

bool ft_map_ismiddle_right(t_map * map,t_point *point)
{
    int arr [] = {383,191,63,319,127};
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


bool ft_map_ismiddle_left(t_map * map,t_point *point)
{
    int arr [] = {506,509,504,505,508};
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
