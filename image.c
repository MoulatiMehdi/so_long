/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:32:22 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/03 17:51:31 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_image_ellipse(t_image *img, t_ellipse *ellipse, t_color color)
{
	int		width;
	int		height;
	t_point	p;

	width = img->width;
	height = img->height;
	p.x = 0;
	while (p.x < width)
	{
		p.y = 0;
		while (p.y < height)
		{
			if (!ft_ellipse_inside(ellipse, &p))
				ft_image_putpixel(img, p.x, p.y, color);
			p.y++;
		}
		p.x++;
	}
}

t_image	*ft_image_from_xpm(void *mlx, char *filename)
{
	t_image	*data;
	void	*address;
	int		width;
	int		height;

	if (mlx == NULL)
		return (NULL);
	address = mlx_xpm_file_to_image(mlx, filename, &width, &height);
	if (address == NULL)
		return (NULL);
	data = malloc(sizeof(t_image));
	if (data == NULL)
		return (NULL);
	data->address = address;
	data->pixels = ft_image_pixels(data);
	data->width = width;
	data->height = height;
	data->mlx = mlx;
	return (data);
}

t_image	*ft_image_new(void *mlx, int width, int height)
{
	t_image	*image;

	if (mlx == NULL)
		return (NULL);
	image = ft_calloc(sizeof(t_image), 1);
	if (image == NULL)
		return (NULL);
	image->address = mlx_new_image(mlx, width, height);
	if (image->address == NULL)
	{
		free(image);
		return (NULL);
	}
	image->pixels = ft_image_pixels(image);
	image->height = height;
	image->width = width;
	image->mlx = mlx;
	return (image);
}

void	ft_image_clear(t_image **image)
{
	if (!image || !*image)
		return ;
	if ((*image)->mlx && (*image)->address)
		mlx_destroy_image((*image)->mlx, (*image)->address);
	free(*image);
	*image = NULL;
}

void	ft_image_fill(t_image *img, t_color color)
{
	int	width;
	int	height;
	int	i;
	int	j;

	width = img->width;
	height = img->height;
	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			ft_image_putpixel(img, i, j, color);
			j++;
		}
		i++;
	}
}

/*void	ft_image_grid(t_image *image, int stepx, int stepy, t_color color)*/
/*{*/
/*	int	i;*/
/*	int	j;*/
/**/
/*	i = 0;*/
/*	while (i < WINDOW_HEIGHT)*/
/*	{*/
/*		j = 0;*/
/*		while (j < WINDOW_WIDTH)*/
/*		{*/
/*			ft_image_putpixel(image, j, i, color);*/
/*			j++;*/
/*		}*/
/*		i += stepy;*/
/*	}*/
/*	j = 0;*/
/*	while (j < WINDOW_WIDTH)*/
/*	{*/
/*		i = 0;*/
/*		while (i < WINDOW_HEIGHT)*/
/*		{*/
/*			ft_image_putpixel(image, j, i, color);*/
/*			i++;*/
/*		}*/
/*		j += stepx;*/
/*	}*/
/*}*/
