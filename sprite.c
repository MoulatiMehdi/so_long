/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:32:45 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/03 17:32:45 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sprite	*ft_sprite_new(void *mlx, char *path, unsigned int col,
		unsigned int row)
{
	t_sprite	*sprite;

	sprite = malloc(sizeof(t_sprite));
	if (!sprite)
		return (NULL);
	sprite->image = ft_image_from_xpm(mlx, path);
	sprite->frame_height = sprite->image->height / row;
	sprite->frame_width = sprite->image->width / col;
	sprite->x = 0;
	sprite->y = 0;
	sprite->row = row;
	sprite->col = col;
	sprite->loop = 1;
	return (sprite);
}

void	ft_sprite_toimage(t_image *dst, t_sprite *sprite, t_point *o_dest)
{
	int	color;
	int	i;
	int	j;

	i = 0;
	if (o_dest->x < 0)
		i = -o_dest->x;
	while (i < sprite->frame_width)
	{
		if (i + o_dest->x >= dst->width)
			break ;
		j = 0;
		if (o_dest->y < 0)
			j = -o_dest->y;
		while (j < sprite->frame_height)
		{
			if (j + o_dest->y >= dst->height)
				break ;
			color = ft_image_getcolor(sprite->image, sprite->x + i, sprite->y
					+ j);
			ft_image_putpixel(dst, o_dest->x + i, o_dest->y + j, color);
			j++;
		}
		i++;
	}
}
