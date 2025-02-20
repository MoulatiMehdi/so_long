#include "so_long.h"

void	ft_sprite_toimage(t_image *dst,t_image *src,t_sprite *sprite,t_point *o_dest)
{
    int	color;
    int	i;
    int	j;

    i = 0;
    if(o_dest->x < 0)
        i = - o_dest->x;
    while (i < sprite->width)
    {
        if(i + o_dest-> x >= dst->width)
                break;
        j = 0;
        if(o_dest->y < 0)
            j = - o_dest->y;
        while (j < sprite->height)
        {
            if(j + o_dest-> y >= dst->height)
                break;
            color = ft_image_getcolor(src, sprite->x + i, sprite->y + j);
            ft_image_putpixel(dst, o_dest->x + i, o_dest->y + j, color);
            j++;
        }
        i++;
    }
}
