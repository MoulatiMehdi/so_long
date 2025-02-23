#include "key.h"
#include "player.h"
#include "so_long.h"

int	ft_handler_close(t_engine *engine)
{
	ft_engine_destroy(&engine);
	exit(1);
	return (1);
}

int	ft_handler_key_press(int keycode, t_engine *engine)
{
	printf("%d Pressed\n", keycode);
	if (keycode == KEY_ESC)
	{
		ft_handler_close(engine);
		return (1);
	}
	if (keycode == KEY_X && (engine->player->state == STATE_LOADING
			|| engine->player->state == STATE_ATTACK))
	{
		engine->player->is_loaded = false;
		engine->player->is_state_fixed = false;
		ft_player_state_set(engine->player, STATE_IDLE);
	}
	if (keycode == KEY_SPACE)
		engine->paused = !engine->paused;
	if (engine->player->state == STATE_DYING)
		engine->paused = false;
	if (keycode < KEYS_TOTAL && keycode >= 0)
		engine->keys[keycode] = 1;
	if (keycode == KEY_LEFT)
		engine->keys[KEY_A] = 1;
	if (keycode == KEY_RIGHT)
		engine->keys[KEY_D] = 1;
	if (keycode == KEY_UP)
		engine->keys[KEY_W] = 1;
	if (keycode == KEY_DOWN)
		engine->keys[KEY_S] = 1;
	return (0);
}

int	ft_handler_key_release(int keycode, t_engine *engine)
{
	printf("%d Released\n", keycode);
	if (keycode < KEYS_TOTAL && keycode >= 0)
		engine->keys[keycode] = 0;
	if (keycode == KEY_LEFT)
		engine->keys[KEY_A] = 0;
	if (keycode == KEY_RIGHT)
		engine->keys[KEY_D] = 0;
	if (keycode == KEY_UP)
		engine->keys[KEY_W] = 0;
	if (keycode == KEY_DOWN)
		engine->keys[KEY_S] = 0;
	return (0);
}
