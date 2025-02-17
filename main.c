#include "mlx.h"
#include "so_long.h"


void draw_rectangle(t_image * img, int x, int y, int width, int height, int color)
{
    int i, j;

    if(x  + width > img->width)
        width = img->width - x;
    if(y  + height > img->height)
        height = img->height - y;

    for (i = x * (x > 0); i < x + width; i++)
    {
        for (j = y * (y > 0); j < y + height; j++)
        {
            ft_image_putpixel(img, i, j, color);
        }
    }
}
       

typedef struct s_square
{
    int x;
    int y;
    t_frame * frame;
    t_image *image;
}t_square;


int	main(void)
{
    t_engine * engine;

    engine = ft_engine_new();
    /*t_square square;*/
    /*t_frame *frame;*/
    /**/
    /*square.x = 0;*/
    /*square.y = 0;*/
    /*frame = ft_frame_new("Hello World", 1000, 500);*/
    /*square.frame = frame;*/
    /**/
    /*draw_rectangle(square.image,0, 0, 100, 100, 0XFF00FF00);*/

    mlx_loop(engine->mlx);
}
