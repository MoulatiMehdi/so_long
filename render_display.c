/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:32:44 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/03 17:49:44 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_display(t_render *render)
{
	t_image	*tmp;

	if (render == NULL)
		return ;
	mlx_put_image_to_window(render->mlx, render->window, render->back->address,
		0, 0);
	tmp = render->front;
	render->front = render->back;
	render->back = tmp;
}

void	ft_render_sprite(t_render *render, t_sprite *sprite, t_point *point)
{
	ft_sprite_toimage(render->back, sprite, point);
	sprite->frame_height = sprite->image->height / sprite->row;
	sprite->frame_width = sprite->image->width / sprite->col;
}

void	ft_sprites_clear(t_sprite ***sprites)
{
	unsigned int	i;

	if (!*sprites)
		return ;
	i = 0;
	while ((*sprites)[i])
	{
		ft_image_clear(&(*sprites)[i]->image);
		free((*sprites)[i]);
		i++;
	}
	free(*sprites);
	*sprites = NULL;
}

void	ft_render_clear(t_render **render)
{
	if (*render == NULL)
		return ;
	ft_image_clear(&(*render)->back);
	ft_image_clear(&(*render)->front);
	ft_sprites_clear(&(*render)->sprites);
	mlx_destroy_window((*render)->mlx, (*render)->window);
	mlx_destroy_display((*render)->mlx);
	free((*render)->mlx);
	free(*render);
	*render = NULL;
}

t_sprite	*ft_sprite_coor_way(t_player *player, t_render *render,
		t_sprite_idx type)
{
	t_sprite	*sprite;
	int			factor;

	sprite = render->sprites[type];
	factor = player->frame_on_loop;
	factor = (factor / sprite->loop) % sprite->col;
	sprite->x = sprite->frame_width * factor;
	sprite->y = sprite->frame_height * player->way;
	return (sprite);
}
