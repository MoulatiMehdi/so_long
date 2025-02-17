/*#include "key.h"*/
/*#include "mlx.h"*/
/*#include "so_long.h"*/
/**/
/*void ft_frame_putimage(t_frame *frame,t_data * img,int x , int y)*/
/*{*/
/*    int dy;*/
/*    int dx;*/
/*    int color;*/
/*    int height;*/
/*    int width;*/
/**/
/**/
/*    height = img->height;*/
/*    width = img->width;*/
/**/
/*    if(img->width + x > frame->width)*/
/*        width = frame->width - x;*/
/*    if(img->height + y > frame->height)*/
/*        height = frame->height - y;*/
/*    dy = (y < 0) * (-y);*/
/*    while(dy < height)*/
/*    {*/
/*        dx = (x < 0) * (-x);*/
/*        while(dx < width)*/
/*        {*/
/*            color = ft_data_getcolor(img, dx, dy);*/
/*            ft_data_putpixel(frame->img_next, x + dx, y + dy,color);*/
/*            dx++;*/
/*        }*/
/*        dy++;*/
/*    }*/
/*}*/
/**/
/*int	ft_window_close(t_frame *frame)*/
/*{*/
/*    ft_frame_clear(frame);*/
/*    exit(1);*/
/*	return (1);*/
/*}*/
/**/
/*int	ft_handler_key_press(int keycode, t_frame *frame)*/
/*{*/
/*	if (keycode == KEY_ESC)*/
/*    {*/
/*        ft_window_close(frame); */
/*        return (1);*/
/*    } */
/*    if(keycode < 256 && keycode >= 0)*/
/*        frame->keys[keycode] = 1;*/
/*    if(keycode == KEY_LEFT)*/
/*        frame->keys[KEY_A] = 1;*/
/*     if(keycode == KEY_RIGHT)*/
/*        frame->keys[KEY_D] = 1;*/
/*     if(keycode == KEY_UP)*/
/*        frame->keys[KEY_W] = 1;*/
/*     if(keycode == KEY_DOWN)*/
/*        frame->keys[KEY_S] = 1;*/
/*    printf("%d Pressed\n",keycode);*/
/*    return (0);*/
/*}*/
/**/
/*int	ft_handler_key_release(int keycode, t_frame *frame)*/
/*{*/
/*    if(keycode < 256 && keycode >= 0)*/
/*        frame->keys[keycode] = 0;*/
/*    if(keycode == KEY_LEFT)*/
/*        frame->keys[KEY_A] = 0;*/
/*     if(keycode == KEY_RIGHT)*/
/*        frame->keys[KEY_D] = 0;*/
/*     if(keycode == KEY_UP)*/
/*        frame->keys[KEY_W] = 0;*/
/*     if(keycode == KEY_DOWN)*/
/*        frame->keys[KEY_S] = 0;*/
/*    printf("%d Released\n",keycode);*/
/*    return (0);*/
/*}*/
/**/
/**/
/*t_frame* ft_frame_new(char * title,int width,int height)*/
/*{*/
/*    t_frame * frame;*/
/**/
/*    frame = malloc(sizeof(t_frame));*/
/*    if(!frame)*/
/*        return NULL;*/
/*    frame->mlx = mlx_init();*/
/*    if(!frame->mlx)*/
/*    {*/
/*        free(frame);*/
/*        return NULL;*/
/*    }*/
/*    frame->window = mlx_new_window(frame->mlx, width,height,title);*/
/*    if(!frame->window)*/
/*    {*/
/*        mlx_destroy_display(frame->mlx);*/
/*        free(frame);*/
/*        return NULL;*/
/*    }*/
/*	mlx_hook(frame->window, ON_DESTROY, 0, ft_window_close, frame);*/
/*	mlx_hook(frame->window, ON_KEYDOWN, 1L << 0, ft_handler_key_press, frame);*/
/*	mlx_hook(frame->window, ON_KEYUP, 1L << 1, ft_handler_key_release, frame);*/
/*    mlx_do_key_autorepeatoff(frame->mlx);*/
/*    ft_bzero(frame->keys,256);*/
/*    frame->img_curr = ft_data_new(frame->mlx,width,height);*/
/*    frame->img_next = ft_data_new(frame->mlx,width,height);*/
/*    frame->width = width;*/
/*    frame->height = height;*/
/*    frame->title = title;*/
/*    return frame;*/
/*}*/
/**/
/*void ft_frame_display(t_frame *frame)*/
/*{*/
/*    if(frame == NULL)*/
/*        return ;*/
/*    mlx_put_image_to_window(frame->mlx, frame->window, frame->img_curr->img, 0, 0);*/
/*}*/
/**/
/*void ft_frame_clear(t_frame * frame)*/
/*{*/
/*    ft_data_clear(frame->mlx,&frame->img_curr);*/
/*    mlx_destroy_window(frame->mlx, frame->window);*/
/*    mlx_destroy_display(frame->mlx);*/
/*    free(frame->mlx);*/
/*    free(frame);*/
/*}*/
