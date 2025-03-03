#include "wall.h"

/*void	ft_map_fill_void(t_render *render, t_map *map)*/
/*{*/
/*    t_point		point;*/
/*    t_sprite	*sprite;*/
/*    int			i;*/
/**/
/*    sprite = render->sprites[SPRITE_FLOOR];*/
/*    sprite->x = sprite->frame_width * 1;*/
/*    sprite->y = sprite->frame_height * 1;*/
/*    i = 0;*/
/*    while (i < WINDOW_HEIGHT / 2 - map->height * 32)*/
/*    {*/
/*        point.x = 0;*/
/*        while (point.x < WINDOW_WIDTH)*/
/*        {*/
/*            point.y = i;*/
/*            ft_render_sprite(render, sprite, &point);*/
/*            point.y = WINDOW_HEIGHT - i - sprite->frame_height;*/
/*            ft_render_sprite(render, sprite, &point);*/
/*            point.x += sprite->frame_width;*/
/*        }*/
/*        i += sprite->frame_height;*/
/*    }*/
/*    while (i < WINDOW_HEIGHT / 2 + map->height * 32)*/
/*    {*/
/*        point.x = 0;*/
/*        while (point.x < WINDOW_WIDTH / 2 - map->width * 32)*/
/*        {*/
/*            point.y = i;*/
/*            i = point.x;*/
/*            ft_render_sprite(render, sprite, &point);*/
/*            point.x = WINDOW_WIDTH - i - sprite->frame_width;*/
/*            ft_render_sprite(render, sprite, &point);*/
/*            point.x = i;*/
/*            i = point.y;*/
/*            point.x += sprite->frame_width;*/
/*        }*/
/*        i += sprite->frame_height;*/
/*    }*/
/*    i = 0;*/
/*}*/
