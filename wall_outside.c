#include "so_long.h"

bool ft_map_outside_isleft_top(t_map * map,t_point *point)
{
    int arr [] = {27,91,155,283,59,31,287,95,387,351,347,123,415,351,287};
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

bool ft_map_outside_isright_top(t_map * map,t_point *point)
{
    int arr [] = {472,248,220,218,217,476,474,473,252,250,221,477,254,253};
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
    while(k < sizeof(arr)/sizeof(arr[0]))
    {
        if(arr[k] == test)
            return true;
        k++;
    }
    return false;
}

bool ft_map_outside_isright_bottom(t_map * map,t_point *point)
{
    int arr [] = {432,496,440,434,433,436,497,498,500,441,442,435,437,501,445};
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

bool ft_map_outside_isleft_bottom(t_map * map,t_point *point)
{
    int arr [] = {54,310,182,118,62,55,119,183,311,126,190,318,374,246,375,382};
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
