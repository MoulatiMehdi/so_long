#include "so_long.h"

int	ft_handler_close(t_engine *engine)
{
    ft_engine_destroy(&engine);
    exit(1);
	return (1);
}

int	ft_handler_key_press(int keycode, t_engine *engine)
{
	if (keycode == KEY_ESC)
    {
        ft_handler_close(engine); 
        return (1);
    } 
    if(keycode < KEYS_TOTAL && keycode >= 0)
        engine->keys[keycode] = 1;
    if(keycode == KEY_LEFT)
        engine->keys[KEY_A] = 1;
     if(keycode == KEY_RIGHT)
        engine->keys[KEY_D] = 1;
     if(keycode == KEY_UP)
        engine->keys[KEY_W] = 1;
     if(keycode == KEY_DOWN)
        engine->keys[KEY_S] = 1;
    printf("%d Pressed\n",keycode);
    return (0);
}

int	ft_handler_key_release(int keycode, t_engine *engine)
{
    if(keycode < KEYS_TOTAL && keycode >= 0)
        engine->keys[keycode] = 0;
    if(keycode == KEY_LEFT)
        engine->keys[KEY_A] = 0;
     if(keycode == KEY_RIGHT)
        engine->keys[KEY_D] = 0;
     if(keycode == KEY_UP)
        engine->keys[KEY_W] = 0;
     if(keycode == KEY_DOWN)
        engine->keys[KEY_S] = 0;
    printf("%d Released\n",keycode);
    return (0);
}
