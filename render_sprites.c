/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:27:34 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/03 21:27:35 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define SPRITE_SRC "./textures/xpm/"
#define FRAME_REPETE 1

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

static void	ft_render_sprite_tiles(t_render *render)
{
	t_sprite	**sprites;
	void		*mlx;

	sprites = render->sprites;
	mlx = render->mlx;
	sprites[SPRITE_FLOOR] = ft_sprite_new(mlx, SPRITE_SRC "floor.xpm", 3, 4);
	sprites[SPRITE_WALL] = ft_sprite_new(mlx, SPRITE_SRC "wall.xpm", 4, 4);
	sprites[SPRITE_OBSTACLE] = ft_sprite_new(mlx, SPRITE_SRC "obstacle.xpm", 5,
			1);
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
	sprites[SPRITE_SWORD_VICTORY] = ft_sprite_new(mlx,
			SPRITE_SRC "sword_red_victory.xpm", 9, 2);
	sprites[SPRITE_STAR_LOADING_H] = ft_sprite_new(mlx,
			SPRITE_SRC "stars.loading.horizontal.xpm", 28, 4);
	sprites[SPRITE_STAR_LOADING_V] = ft_sprite_new(mlx,
			SPRITE_SRC "starts.loading.vertical.xpm", 19, 6);
}

static void	ft_render_sprites_loop(t_render *render)
{
	t_sprite	**sprites;

	sprites = render->sprites;
	sprites[SPRITE_LINK_SPIN]->loop = 1 * FRAME_REPETE;
	sprites[SPRITE_LINK_LOADING]->loop = 2 * FRAME_REPETE;
	sprites[SPRITE_LINK_ATTACKING]->loop = 1 * FRAME_REPETE;
	sprites[SPRITE_LINK_DYING]->loop = 2 * FRAME_REPETE;
	sprites[SPRITE_LINK_VICTORY]->loop = 2 * FRAME_REPETE;
	sprites[SPRITE_LINK_WALKING]->loop = 2 * FRAME_REPETE;
	sprites[SPRITE_SWORD_SPIN]->loop = sprites[SPRITE_LINK_SPIN]->loop;
	sprites[SPRITE_SWORD_ATTACK]->loop = sprites[SPRITE_LINK_ATTACKING]->loop;
	sprites[SPRITE_SWORD_LOADING]->loop = sprites[SPRITE_LINK_LOADING]->loop;
	sprites[SPRITE_SWORD_VICTORY]->loop = sprites[SPRITE_LINK_VICTORY]->loop;
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

void	ft_render_sprites_init(t_render *render)
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
	ft_render_sprite_tiles(render);
	ft_render_sprites_loop(render);
	render->sprites[SPRITE_TOTAL] = NULL;
}
