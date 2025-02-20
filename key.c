#include "key.h"
#include "so_long.h"

void	ft_key_debug(t_animation *animation)
{
	t_render	*render;
    int i;
    t_sprite sprite;
    t_point o_dest;

    sprite.height = 16;
    sprite.width = 16;
    sprite.x = 0;
    sprite.y = 0;
    o_dest.y = KEY_DEBUG_Y; 
    o_dest.x = KEY_DEBUG_X; 
	render = animation->render;
	i = 0;
    while(KEY_TRACK[i])
    {
        if (animation->engine->keys[(int)KEY_TRACK[i]] == 1)
            ft_sprite_toimage(render->back, animation->sprite_debug, &sprite, &o_dest);
        o_dest.x += sprite.width;
        sprite.x += sprite.width;
        i++;
    }
    if (animation->engine->paused)
        ft_sprite_toimage(render->back, animation->sprite_debug, &sprite, &o_dest);
}
