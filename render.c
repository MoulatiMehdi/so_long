#include "image.h"
#include "key.h"
#include "mlx.h"
#include "so_long.h"

void	ft_render_sprites(t_render *render)
{
	render->sprites = malloc(sizeof(t_sprite *) * (SPRITE_TOTAL + 1));
	if (render->sprites == NULL)
		return ;
	render->sprites[SPRITE_LINK_HURT] = ft_sprite_new(render->mlx,
			"./textures/xpm/link.hurt.xpm", 1, 4);
	render->sprites[SPRITE_LINK_IDLE] = ft_sprite_new(render->mlx,
			"./textures/xpm/link.idle.xpm", 1, 4);
	render->sprites[SPRITE_LINK_DYING] = ft_sprite_new(render->mlx,
			"./textures/xpm/link.dying.xpm", 10, 1);
	render->sprites[SPRITE_LINK_SPIN] = ft_sprite_new(render->mlx,
			"./textures/xpm/link.spinning.xpm", 22, 4);
	render->sprites[SPRITE_LINK_WALKING] = ft_sprite_new(render->mlx,
			"./textures/xpm/link.walking.xpm", 8, 4);
	render->sprites[SPRITE_LINK_LOADING] = ft_sprite_new(render->mlx,
			"./textures/xpm/link.loading.xpm", 6, 4);
	render->sprites[SPRITE_LINK_VICTORY] = ft_sprite_new(render->mlx,
			"./textures/xpm/link.victory.xpm", 18, 1);
	render->sprites[SPRITE_LINK_ATTACKING] = ft_sprite_new(render->mlx,
			"./textures/xpm/link.attack.xpm", 12, 4);
	render->sprites[SPRITE_SWORD_SPIN] = ft_sprite_new(render->mlx,
			"./textures/xpm/sword.spin.xpm", 22, 4);
	render->sprites[SPRITE_SWORD_ATTACK] = ft_sprite_new(render->mlx,
			"./textures/xpm/sword.attack.xpm", 12, 4);
	render->sprites[SPRITE_SWORD_LOADING] = ft_sprite_new(render->mlx,
			"./textures/xpm/sword.loading.xpm", 6, 4);
	render->sprites[SPRITE_COIN] = ft_sprite_new(render->mlx,
			"./textures/xpm/coin.xpm", 1, 1);
	render->sprites[SPRITE_CAPE] = ft_sprite_new(render->mlx,
			"./textures/xpm/cape.xpm", 2, 1);
	render->sprites[SPRITE_DEBUG] = ft_sprite_new(render->mlx,
			"./textures/xpm/debug.xpm", 9, 1);
	render->sprites[SPRITE_HEARTS] = ft_sprite_new(render->mlx,
			"./textures/xpm/hearts.xpm", 3, 1);
	render->sprites[SPRITE_DIGITS] = ft_sprite_new(render->mlx,
			"./textures/xpm/digits.xpm", 10, 2);
	render->sprites[SPRITE_GAMEOVER] = ft_sprite_new(render->mlx,
			"./textures/xpm/gameover.xpm", 1, 1);
	render->sprites[SPRITE_TOTAL] = NULL;
}

void	ft_render_sprites_loop(t_render *render)
{
	render->sprites[SPRITE_LINK_SPIN]->loop = 2;
	render->sprites[SPRITE_LINK_LOADING]->loop = 4;
	render->sprites[SPRITE_LINK_ATTACKING]->loop = 1;
	render->sprites[SPRITE_LINK_DYING]->loop = 5;
	render->sprites[SPRITE_LINK_VICTORY]->loop = 4;
	render->sprites[SPRITE_LINK_WALKING]->loop = 4;
	render->sprites[SPRITE_SWORD_SPIN]->loop = render->sprites[SPRITE_LINK_SPIN]->loop;
	render->sprites[SPRITE_SWORD_ATTACK]->loop = render->sprites[SPRITE_LINK_ATTACKING]->loop;
	render->sprites[SPRITE_SWORD_LOADING]->loop = render->sprites[SPRITE_LINK_LOADING]->loop;
	render->sprites[SPRITE_CAPE]->loop = 1;
	render->sprites[SPRITE_COIN]->loop = 1;
	render->sprites[SPRITE_DEBUG]->loop = 1;
	render->sprites[SPRITE_DIGITS]->loop = 1;
	render->sprites[SPRITE_HEARTS]->loop = 1;
	render->sprites[SPRITE_GAMEOVER]->loop = 1;
	render->sprites[SPRITE_LINK_HURT]->loop = 1;
	render->sprites[SPRITE_LINK_IDLE]->loop = 1;
}

t_render	*ft_render_new(void *mlx, void *window)
{
	t_render	*render;

	render = malloc(sizeof(t_render));
	if (render == NULL)
		return (NULL);
	render->window = window;
	render->mlx = mlx;
	render->back = ft_image_new(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	render->front = ft_image_new(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	render->stop = false;
	ft_render_sprites(render);
	ft_render_sprites_loop(render);
	return (render);
}

void	ft_render_display(t_render *render)
{
	t_image	*tmp;

	if (render == NULL)
		return ;
	mlx_clear_window(render->mlx, render->window);
	mlx_put_image_to_window(render->mlx, render->window, render->back->address,
		0, 0);
	tmp = render->front;
	render->front = render->back;
	render->back = tmp;
}

void	ft_render_sprite(t_render *render, t_sprite *sprite, t_point *point)
{
	ft_sprite_toimage(render->back, sprite, point);
}

void	ft_render_clear(t_render *render)
{
	ft_image_clear(&render->back);
	ft_image_clear(&render->front);
	free(render);
}
