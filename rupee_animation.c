#include "so_long.h"

void	ft_rupee_render(t_render * render,t_engine * engine)
{
	t_sprite	*sprite;
    t_list * head;
    t_coin * coin;
	t_point		point;
	static int			frame = 0;

	sprite = render->sprites[SPRITE_RUPEE];
	sprite->x = (frame / sprite->loop ) * sprite->frame_width;
    head = engine->coins;
    while(head)
    {

        coin = head->content;
	    point.x = coin->x;
	    point.y = coin->y;
        if(ft_camera_is_inview(&render->camera, &point))
        {
	        point.x -= render->camera.x;
	        point.y -= render->camera.y;
	        sprite->y = sprite->frame_height * (coin->type % sprite->row);
            ft_render_sprite(render, sprite, &point);
        }
        head = head->next;
    }
    frame = (frame + 1) % (sprite->col * sprite->loop); 
}
