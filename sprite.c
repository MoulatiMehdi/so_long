#include "so_long.h"

void	ft_sprite_toimage(t_gui * gui,t_sprite *sprite,t_point *dest)
{
    int	color;
    int	i;
    int	j;

    i = 0;
    while (i < sprite->width)
    {
        j = 0;
        while (j < sprite->height)
        {
            color = ft_image_getcolor(gui->sprite_square, sprite->x + i, sprite->y + j);
            ft_image_putpixel(gui->menu, dest->x + i, dest->y + j, color);
            j++;
        }
        i++;
    }
}
