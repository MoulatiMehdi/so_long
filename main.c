#include "color.h"
#include "image.h"
#include "key.h"
#include "mlx.h"
#include "so_long.h"
#include <bits/pthreadtypes.h>
#include <stdio.h>
#include <unistd.h>

void	draw_rectangle(t_image *img, int x, int y, t_color color)
{
    int	width;
    int	height;
    int	i;
    int	j;

    width = img->width;
    height = img->height;
    if (x + width > img->width)
        width = img->width - x;
    if (y + height > img->height)
        height = img->height - y;
    i = x;
    while (i < x + width)
    {
        j = y;
        while (j < y + height)
        {
            ft_image_putpixel(img, i, j, color);
            j++;
        }
        i++;
    }
}

void ft_gui_render(t_animation * animation)
{
    t_render	*render;
    t_engine	*engine;
    t_gui * gui;
    char		*keys;

    engine = animation->engine;
    render = animation->render;
    keys = engine->keys;
    gui = engine->gui;

    if(!engine->paused && gui->y == -WINDOW_HEIGHT)
        return ;
    if(engine->paused && gui->y == 0)
        return ;

    draw_rectangle(animation->render->curr, 0, 0, 0X0000FFFF);
    if(!engine->paused)
        gui->y -= 32;
    else
        gui->y += 32;
    if(gui->y > 0)
        gui->y = 0;
    if(gui->y < -WINDOW_HEIGHT)
        gui->y = -WINDOW_HEIGHT;
    ft_image_dup(render->curr, gui->menu,0,gui->y);
}

int	ft_animation_update(t_animation *animation)
{
    t_image * tmp;

    ft_gui_render(animation);
    if(!animation->engine->paused && animation->engine->gui->y == -WINDOW_HEIGHT)
    {
        draw_rectangle(animation->render->curr, 0, 0, 0X0000FFFF);
        ft_key_debug(animation);
        ft_player_render(animation);
        ft_player_debug(animation->engine->player);
    }
    ft_image_towindow(animation->render->curr, animation->render, 0, 0);
    return (0);
}

void ft_grid(t_image * image,int stepx,int stepy,t_color color)
{
    int i;
    int j;

    i = 48;
    while(i < WINDOW_HEIGHT)
    {
        j = 0;
        while(j < WINDOW_WIDTH)
        {
            ft_image_putpixel(image, j, i, color);
            j++;
        }

        i+= stepy;
    }
    
    j = 32;
    while(j < WINDOW_WIDTH)
    {
        i = 0;
        while(i < WINDOW_HEIGHT)
        {
            ft_image_putpixel(image, j, i, color);
            i++;
        }

        j+= stepx;
    }

}


int	main(void)
{
    t_animation	animation;
    t_gui gui;
    t_engine	*engine;
    t_render	*render;

    engine = ft_engine_new();
    render = ft_render_new(engine->mlx, engine->window);
    animation.render = render;
    animation.engine = engine;
    engine->player->sprite = ft_image_from_xpm(engine->mlx,"./textures/xpm/walk.xpm");
    animation.debug = ft_image_from_xpm(engine->mlx,"./textures/xpm/debug.xpm");
    gui.sprite_square = ft_image_from_xpm(engine->mlx, "./textures/xpm/gui.xpm"); 
    gui.sprite_cursor = ft_image_from_xpm(engine->mlx, "./textures/xpm/item_cursor.xpm"); 
    gui.menu = ft_image_new(engine->mlx, WINDOW_WIDTH, WINDOW_HEIGHT); 
    gui.item_x = 0;
    gui.item_y = 0;
    gui.y = -WINDOW_HEIGHT;
    engine->gui = &gui;
    draw_rectangle(gui.menu, 0, 0, 0X0000FFFF);
    ft_gui_draw(&gui);
    mlx_loop_hook(engine->mlx, ft_animation_update,&animation);
    mlx_loop(engine->mlx);
}
