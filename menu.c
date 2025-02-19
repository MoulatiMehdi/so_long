#include "so_long.h"

# define SHIFT_X ((WINDOW_WIDTH - 9.5 * o_sprite.width * 4) / 2)

void ft_menu_row(t_gui * gui ,t_sprite o_sprite,t_point o_img, int len)
{
    int i;
    
    ft_sprite_toimage(gui, &o_sprite , &o_img);
    i = 0;
    o_sprite.x += o_sprite.width; 
    while(i <  len)
    {
        o_img.x += o_sprite.width;
        ft_sprite_toimage(gui, &o_sprite,&o_img);
        i++;
    }
    o_img.x += o_sprite.width;
    o_sprite.x += o_sprite.width; 
    ft_sprite_toimage(gui,&o_sprite, &o_img);
}

void ft_gui_tools(t_gui * gui)
{
    int i;
    t_sprite o_sprite;
    t_point o_img;
  
    o_sprite.width = 16;
    o_sprite.height = 16;
    o_sprite.x = 0;
    o_sprite.y = 0;
    o_img.y = 32;
    o_img.x = SHIFT_X ;
    ft_menu_row(gui,o_sprite,o_img, 20);
    i = 0;
    o_sprite.y +=o_sprite.height;
    while(i < 16)
    {
        o_img.y +=o_sprite.height;
        ft_menu_row(gui,o_sprite,o_img, 20);
        i++;
    }
    o_img.y +=o_sprite.height;
    o_sprite.y +=o_sprite.height;
    ft_menu_row(gui,o_sprite,o_img, 20);
}

void ft_gui_magic(t_gui * gui)
{
    int i;
    t_sprite o_sprite;
    t_point o_img;
   
    o_sprite.width = 16;
    o_sprite.height = 16;
    o_sprite.x = 2 * 16 * 3;
    o_sprite.y = 0;
    o_img.y = 32 + 16 * 20;
    o_img.x = SHIFT_X;
    ft_menu_row(gui,o_sprite,o_img, 20);
    i = 0;
    o_sprite.y +=o_sprite.height;
    while(i < 8)
    {
        o_img.y +=16;
        ft_menu_row(gui,o_sprite,o_img, 20);
        i++;
    }
    o_img.y +=16;
    o_sprite.y +=o_sprite.height;
    ft_menu_row(gui,o_sprite,o_img, 20);
}

void ft_gui_item(t_gui * gui)
{
    int i;
    t_sprite o_sprite;
    t_point o_img;
   
    o_sprite.width = 16;
    o_sprite.height = 16;
    o_sprite.x = 1 * o_sprite.width * 3;
    o_sprite.y = 0;
    o_img.y = 32;
    o_img.x = WINDOW_WIDTH - SHIFT_X - 3.5 * 64;
    ft_menu_row(gui,o_sprite,o_img, 12);
    i = 0;
    o_sprite.y +=o_sprite.height;
    while(i < 16)
    {
        o_img.y +=o_sprite.height;
        ft_menu_row(gui,o_sprite,o_img, 12);
        i++;
    }
    o_img.y +=o_sprite.height;
    o_sprite.y +=o_sprite.height;
    ft_menu_row(gui,o_sprite,o_img, 12);
    
    o_img.y += o_sprite.height * 3;
    o_sprite.x = 1 * o_sprite.width * 3;
    o_sprite.y = 0;
    ft_menu_row(gui,o_sprite,o_img, 12);
    i = 0;
    o_sprite.y +=o_sprite.height;
    while(i < 8)
    {
        o_img.y +=o_sprite.height;
        ft_menu_row(gui,o_sprite,o_img, 12);
        i++;
    }
    o_img.y +=o_sprite.height;
    o_sprite.y +=o_sprite.height;
    ft_menu_row(gui,o_sprite,o_img, 12);
}


void ft_gui_draw(t_gui * gui)
{
    ft_gui_tools(gui); 
    ft_gui_magic(gui);
    ft_gui_item(gui);
   
}

