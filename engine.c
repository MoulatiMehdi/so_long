#include "libft/libft.h"
#include "mlx.h"
#include "so_long.h"
#include <stdlib.h>

int			ft_handler_close(t_engine *engine);
int			ft_handler_key_release(int keycode, t_engine *engine);
int			ft_handler_key_press(int keycode, t_engine *engine);

t_engine	*ft_engine_new(void)
{
	t_engine	*engine;

	engine = malloc(sizeof(t_engine));
	if (engine == NULL)
		return (NULL);
	engine->mlx = mlx_init();
	mlx_do_key_autorepeatoff(engine->mlx);
	engine->window = mlx_new_window(engine->mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
			WINDOW_TITLE);
	engine->map = NULL;
	engine->player = ft_player_new();
	engine->paused = false;
    ft_bzero(engine->keys, KEYS_TOTAL);
	mlx_hook(engine->window, ON_DESTROY, 0, ft_handler_close, engine);
	mlx_hook(engine->window, ON_KEYDOWN, 1L << 0, ft_handler_key_press, engine);
	mlx_hook(engine->window, ON_KEYUP, 1L << 1, ft_handler_key_release, engine);
	return (engine);
}

void	ft_engine_destroy(t_engine **engine)
{
	ft_player_destroy(&(*engine)->player);
	ft_split_free(&(*engine)->map);
	mlx_destroy_window((*engine)->mlx, (*engine)->window);
	mlx_destroy_display((*engine)->mlx);
	free((*engine)->mlx);
	free(*engine);
	*engine = NULL;
}
