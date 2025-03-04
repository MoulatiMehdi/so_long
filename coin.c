#include "so_long.h"

t_coin * ft_coin_new(int x,int y)
{
    t_coin * coin;
    
    coin = ft_calloc(sizeof(t_coin),1);

    if(coin == NULL)
        return NULL;
    coin->x = x;
    coin->y = y;
    return coin;
}

bool ft_player_coin_iscollide(t_player * player,t_coin * p)
{
    if(player->x + player->origin_x - player->width / 2 > p->x && player->x + player->origin_x + player->width / 2  < p->x)
        return false;
    if(player->y + player->origin_y - player->height / 2 > p->y && player->y + player->origin_y + player->height / 2  < p->y)
        return false;
    return true;
}
void ft_coin_update(t_animation * animation)
{
    t_list *lst;
    t_coin * coin;
    t_sprite * sprite;

    sprite = animation->render->sprites[SPRITE_RUPEE];
    lst = animation->engine->coins;
    while(lst)
    {
        coin = lst->content;
        if(coin->x )
            ;

        lst = lst->next;
    }

}

void ft_coin_destroy(t_coin * coin)
{
    free(coin);
}
