#include "image.h"
#include "so_long.h"

#define SPRITE_SRC "./textures/xpm/"

static void	ft_render_sprite_player(t_render *render)
{
	t_sprite	**sprites;
	void		*mlx;

	sprites = render->sprites;
	mlx = render->mlx;
	sprites[SPRITE_LINK_HURT] = ft_sprite_new(mlx, SPRITE_SRC "link.hurt.xpm",
			1, 4);
	sprites[SPRITE_LINK_IDLE] = ft_sprite_new(mlx, SPRITE_SRC "link.idle.xpm",
			1, 4);
	sprites[SPRITE_LINK_DYING] = ft_sprite_new(mlx, SPRITE_SRC "link.dying.xpm",
			10, 1);
	sprites[SPRITE_LINK_SPIN] = ft_sprite_new(mlx,
			SPRITE_SRC "link.spinning.xpm", 22, 4);
	sprites[SPRITE_LINK_WALKING] = ft_sprite_new(mlx,
			SPRITE_SRC "link.walking.xpm", 8, 4);
	sprites[SPRITE_LINK_LOADING] = ft_sprite_new(mlx,
			SPRITE_SRC "link.loading.xpm", 6, 4);
	sprites[SPRITE_LINK_VICTORY] = ft_sprite_new(mlx,
			SPRITE_SRC "link.victory.xpm", 18, 1);
	sprites[SPRITE_LINK_ATTACKING] = ft_sprite_new(mlx,
			SPRITE_SRC "link.attack.xpm", 12, 4);
}

static void	ft_render_sprite_objects(t_render *render)
{
	t_sprite	**sprites;
	void		*mlx;

	sprites = render->sprites;
	mlx = render->mlx;
	sprites[SPRITE_COIN] = ft_sprite_new(mlx, SPRITE_SRC "coin.xpm", 1, 1);
	sprites[SPRITE_CAPE] = ft_sprite_new(mlx, SPRITE_SRC "cape.xpm", 2, 1);
	sprites[SPRITE_DEBUG] = ft_sprite_new(mlx, SPRITE_SRC "debug.xpm", 9, 1);
	sprites[SPRITE_HEARTS] = ft_sprite_new(mlx, SPRITE_SRC "hearts.xpm", 3, 1);
	sprites[SPRITE_DIGITS] = ft_sprite_new(mlx, SPRITE_SRC "digits.xpm", 10, 2);
	sprites[SPRITE_GAMEOVER] = ft_sprite_new(mlx, SPRITE_SRC "gameover.xpm", 1,
			1);
	sprites[SPRITE_SWORD_SPIN] = ft_sprite_new(mlx, SPRITE_SRC "sword.spin.xpm",
			22, 4);
	sprites[SPRITE_SWORD_ATTACK] = ft_sprite_new(mlx,
			SPRITE_SRC "sword.attack.xpm", 12, 4);
	sprites[SPRITE_SWORD_LOADING] = ft_sprite_new(mlx,
			SPRITE_SRC "sword.loading.xpm", 6, 4);
	sprites[SPRITE_STAR_LOADING_H] = ft_sprite_new(mlx,
			SPRITE_SRC "stars.loading.horizontal.xpm", 28, 4);
	sprites[SPRITE_STAR_LOADING_V] = ft_sprite_new(mlx,
			SPRITE_SRC "starts.loading.vertical.xpm", 19, 6);
}

static void	ft_render_sprites_loop(t_render *render)
{
	t_sprite	**sprites;

	sprites = render->sprites;
	sprites[SPRITE_LINK_SPIN]->loop = 2;
	sprites[SPRITE_LINK_LOADING]->loop = 4;
	sprites[SPRITE_LINK_ATTACKING]->loop = 1;
	sprites[SPRITE_LINK_DYING]->loop = 5;
	sprites[SPRITE_LINK_VICTORY]->loop = 4;
	sprites[SPRITE_LINK_WALKING]->loop = 4;
	sprites[SPRITE_SWORD_SPIN]->loop = sprites[SPRITE_LINK_SPIN]->loop;
	sprites[SPRITE_SWORD_ATTACK]->loop = sprites[SPRITE_LINK_ATTACKING]->loop;
	sprites[SPRITE_SWORD_LOADING]->loop = sprites[SPRITE_LINK_LOADING]->loop;
	sprites[SPRITE_STAR_LOADING_H]->loop = sprites[SPRITE_LINK_LOADING]->loop;
	sprites[SPRITE_STAR_LOADING_V]->loop = sprites[SPRITE_LINK_LOADING]->loop;
	sprites[SPRITE_CAPE]->loop = 1;
	sprites[SPRITE_COIN]->loop = 1;
	sprites[SPRITE_DEBUG]->loop = 1;
	sprites[SPRITE_DIGITS]->loop = 1;
	sprites[SPRITE_HEARTS]->loop = 1;
	sprites[SPRITE_GAMEOVER]->loop = 1;
	sprites[SPRITE_LINK_HURT]->loop = 1;
	sprites[SPRITE_LINK_IDLE]->loop = 1;
}

static void	ft_render_sprites_init(t_render *render)
{
	unsigned int	size;

	if (render == NULL)
		return ;
	size = sizeof(t_sprite *) * (SPRITE_TOTAL + 1);
	render->sprites = malloc(size);
	if (render->sprites == NULL)
		return ;
	ft_bzero(render->sprites, size);
	ft_render_sprite_player(render);
	ft_render_sprite_objects(render);
	ft_render_sprites_loop(render);
	render->sprites[SPRITE_TOTAL] = NULL;
}

t_render	*ft_render_new(void *mlx, void *window)
{
	t_render	*render;

	if (window == NULL || mlx == NULL)
		return (NULL);
	render = malloc(sizeof(t_render));
	if (render == NULL)
		return (NULL);
	render->window = window;
	render->mlx = mlx;
	render->back = ft_image_new(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	render->front = ft_image_new(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (render->back == NULL || render->front == NULL)
	{
		ft_render_clear(&render);
		return (NULL);
	}
	ft_render_sprites_init(render);
	render->stop = false;
	return (render);
}
