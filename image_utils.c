/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:32:23 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/03 17:32:23 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <math.h>

static int	ft_image_offset(t_image *data, int x, int y)
{
	int	offset;

	offset = y * data->line_length + x * (data->bpp / 8);
	return (offset);
}

char	*ft_image_pixels(t_image *data)
{
	if (data == NULL)
		return (NULL);
	return (mlx_get_data_addr(data->address, &data->bpp, &data->line_length,
			&data->endian));
}

t_color	ft_image_getcolor(t_image *data, int x, int y)
{
	int	color;

	if (data == NULL)
		return (0XFF000000);
	if (data->height <= y || data->width <= x)
		return (0XFF000000);
	if (y < 0 || x < 0)
		return (0XFF000000);
	color = *(unsigned int *)(data->pixels + ft_image_offset(data, x, y));
	return (color);
}

void	ft_image_putpixel(t_image *data, int x, int y, t_color color)
{
	char	*dst;

	if (data == NULL)
		return ;
	if (data->height <= y || data->width <= x)
		return ;
	if (ft_color_opacity(color) == 0XFF || data == NULL)
		return ;
	if (y < 0 || x < 0)
		return ;
	dst = data->pixels + ft_image_offset(data, x, y);
	*(unsigned int *)dst = color;
}

bool	ft_ellipse_inside(t_ellipse *ellipse, t_point *p)
{
	if (ellipse->raduis_x == 0 || ellipse->raduis_y == 0)
		return (false);
	return (pow(ellipse->center.x - p->x, 2) / pow(ellipse->raduis_x, 2)
		+ pow(ellipse->center.y - p->y, 2) / pow(ellipse->raduis_y, 2) <= 1);
}
