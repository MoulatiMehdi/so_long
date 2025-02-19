#include "key.h"
#include "so_long.h"

void	ft_debug_rect(t_image *dest, t_image *src, int x, int y, int dest_x,
		int dest_y)
{
	int	width;
	int	height;
	int	color;
	int	i;
	int	j;

	width = 16;
	height = 16;
	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			color = ft_image_getcolor(src, x + i, y + j);
			ft_image_putpixel(dest, dest_x + i, dest_y + j, color);
			j++;
		}
		i++;
	}
}

void	ft_key_debug(t_animation *animation)
{
	t_render	*render;
	char		*keys;
    int i;
    char * pressed;

    pressed = "dwascx ";
	keys = animation->engine->keys;
	render = animation->render;
	i = 0;
    while(pressed[i])
    {
        if (keys[(int)pressed[i]] == 1)
		    ft_debug_rect(render->curr, animation->debug, 16 * i, 0, 16 * i,16);
        i++;
    }
}
