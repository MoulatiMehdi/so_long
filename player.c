#include "so_long.h"

void ft_player_walk(t_player * player)
{

}

void ft_player_destroy(t_player ** player)
{
    free(*player);
    *player = NULL;
}
