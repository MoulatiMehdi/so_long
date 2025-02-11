/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:47:12 by mmoulati          #+#    #+#             */
/*   Updated: 2025/02/11 12:39:03 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	*ft_image_new(void *mlx, size_t width, size_t height)
{
	t_image	*img;

	if (mlx == NULL)
		return (NULL);
	img = malloc(sizeof(t_image));
	img->height = height;
	img->width = width;
	img->data = ft_data_new(mlx, width, height);
	img->mlx = mlx;
	return (img);
}

void	ft_image_putpixel(t_image *image, int x, int y, int color)
{
	if (image == NULL)
		return ;
	ft_data_putpixel(image->data, x, y, color);
}
