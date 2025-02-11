/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:44:08 by mmoulati          #+#    #+#             */
/*   Updated: 2025/02/11 15:41:44 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_data_address(t_data *data)
{
	if (data == NULL)
		return (NULL);
	return (mlx_get_data_addr(data->img, &data->bpp, &data->line_length,
			&data->endian));
}

int	ft_data_offset(t_data *data, int x, int y)
{
	if (data == NULL)
		return (-1);
	return (y * data->line_length + x * (data->bpp / 8));
}

void	ft_data_putpixel(t_data *data, int x, int y, int color)
{
	char	*pixel;

	if (data == NULL || data->addr == NULL)
		return ;
	pixel = data->addr + ft_data_offset(data, x, y);
	*(unsigned int *)pixel = color;
}

t_data	*ft_data_new(void *mlx, size_t width, size_t height)
{
	t_data	*data;

	if (mlx == NULL)
		return (NULL);
	data = malloc(sizeof(t_data));
	data->img = mlx_new_image(mlx, width, height);
	data->addr = ft_data_address(data);
	return (data);
}
