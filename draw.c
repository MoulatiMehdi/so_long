/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:30:10 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/04 19:42:37 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_react(t_render *render, t_player *player, t_color color)
{
	int		j;
	t_point	p;

	ft_player_camera_center(render, player, &p);
	p.x += -player->width / 2 + player->origin_x;
	p.y += -player->height / 2 + player->origin_y;
	j = 0;
	while (j < player->width)
	{
		ft_image_putpixel(render->back, p.x + j, p.y, color);
		j++;
	}
	j = 0;
	while (j < player->height)
	{
		ft_image_putpixel(render->back, p.x, p.y + j, color);
		ft_image_putpixel(render->back, p.x + player->width - 1, p.y + j,
			color);
		j++;
	}
	j = 0;
	while (j < player->width)
	{
		ft_image_putpixel(render->back, p.x + j, p.y + player->height - 1,
			color);
		j++;
	}
}

void	draw_coin_collision(t_render *render, t_point p)
{
	int			j;
	t_sprite	*sprite;
	int			color;

	color = 0X00FF0000;
	sprite = render->sprites[SPRITE_RUPEE];
	j = 0;
	while (j < sprite->frame_width)
	{
		ft_image_putpixel(render->back, p.x + j, p.y, color);
		j++;
	}
	j = 0;
	while (j < sprite->frame_height)
	{
		ft_image_putpixel(render->back, p.x, p.y + j, color);
		ft_image_putpixel(render->back, p.x + sprite->frame_width - 1, p.y + j,
			color);
		j++;
	}
	j = 0;
	while (j < sprite->frame_width)
	{
		ft_image_putpixel(render->back, p.x + j, p.y + sprite->frame_height - 1,
			color);
		j++;
	}
}
