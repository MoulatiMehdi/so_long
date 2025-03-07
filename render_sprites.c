/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 21:27:34 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/06 23:39:12 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

#define SPRITE_SRC "./textures/xpm/"
#define FRAME_REPETE 1

static void	ft_render_sprites_player(t_render *render)
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

static void	ft_render_sprites_tiles(t_render *render)
{
	t_sprite	**sprites;
	void		*mlx;

	sprites = render->sprites;
	mlx = render->mlx;
	sprites[SPRITE_FLOOR] = ft_sprite_new(mlx, SPRITE_SRC "floor.xpm", 3, 4);
	sprites[SPRITE_WALL] = ft_sprite_new(mlx, SPRITE_SRC "wall.xpm", 4, 4);
	sprites[SPRITE_OBSTACLE] = ft_sprite_new(mlx, SPRITE_SRC "obstacle.xpm", 5,
			1);
	sprites[SPRITE_RUPEE] = ft_sprite_new(mlx, SPRITE_SRC "rupee.xpm", 10, 3);
	sprites[SPRITE_SOLDIER] = ft_sprite_new(mlx, SPRITE_SRC "soldier.xpm", 6,
			4);
	sprites[SPRITE_SMOKE] = ft_sprite_new(mlx, SPRITE_SRC "smoke.xpm", 3, 1);
	sprites[SPRITE_EXIT] = ft_sprite_new(mlx, SPRITE_SRC "exit.xpm", 4, 2);
}

static void	ft_render_sprites_objects(t_render *render)
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
	sprites[SPRITE_LINK_DYING]->loop = 4 * FRAME_REPETE;
	sprites[SPRITE_LINK_VICTORY]->loop = 1 * FRAME_REPETE;
	sprites[SPRITE_LINK_WALKING]->loop = 2 * FRAME_REPETE;
	sprites[SPRITE_SWORD_SPIN]->loop = sprites[SPRITE_LINK_SPIN]->loop;
	sprites[SPRITE_SWORD_ATTACK]->loop = sprites[SPRITE_LINK_ATTACKING]->loop;
	sprites[SPRITE_SWORD_LOADING]->loop = sprites[SPRITE_LINK_LOADING]->loop;
	sprites[SPRITE_SWORD_VICTORY]->loop = sprites[SPRITE_LINK_VICTORY]->loop;
	sprites[SPRITE_STAR_LOADING_H]->loop = sprites[SPRITE_LINK_LOADING]->loop;
	sprites[SPRITE_STAR_LOADING_V]->loop = sprites[SPRITE_LINK_LOADING]->loop;
	sprites[SPRITE_RUPEE]->loop = 3 * FRAME_REPETE;
	sprites[SPRITE_EXIT]->loop = 3 * FRAME_REPETE;
	sprites[SPRITE_SOLDIER]->loop = 10 * FRAME_REPETE;
	sprites[SPRITE_SMOKE]->loop = sprites[SPRITE_SOLDIER]->loop;
}

void	ft_render_sprites_init(t_render *render)
{
	unsigned int	i;

	if (render == NULL)
		return ;
	render->sprites = ft_calloc(sizeof(t_sprite *), SPRITE_TOTAL + 1);
	if (render->sprites == NULL)
		return ;
	ft_render_sprites_player(render);
	ft_render_sprites_objects(render);
	ft_render_sprites_tiles(render);
	i = 0;
	while (i < SPRITE_TOTAL)
	{
		if (!render->sprites[i])
			return (ft_sprites_clear(&render->sprites));
		i++;
	}
	ft_render_sprites_loop(render);
}
