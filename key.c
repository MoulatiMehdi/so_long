#include "key.h"
#include "so_long.h"

#define  KEY_TRACK "dwascx"

void	ft_key_debug(t_animation *animation)
{
    int i;
	t_render	*render;
    t_sprite *sprite;
    t_point o_dest;

	render = animation->render;
    sprite = render->sprites[SPRITE_DEBUG];
    sprite->x = 0;
    sprite->y = 0;
    o_dest.y = KEY_DEBUG_Y; 
    o_dest.x = KEY_DEBUG_X; 
	i = 0;
    while(KEY_TRACK[i])
    {
        if (animation->engine->keys[(int)KEY_TRACK[i]] == 1)
            ft_sprite_toimage(render->back, sprite, &o_dest);
        o_dest.x += sprite->frame_width;
        sprite->x += sprite->frame_width;
        i++;
    }
    if (animation->engine->paused)
            ft_sprite_toimage(render->back, sprite, &o_dest);
}
