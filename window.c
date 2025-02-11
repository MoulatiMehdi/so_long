/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:55:17 by mmoulati          #+#    #+#             */
/*   Updated: 2025/02/11 16:35:18 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

int	ft_handler_keys(int keycode, t_window *window)
{
	printf("%d\n", keycode);
	if (keycode == KEY_ESC)
		return (mlx_destroy_window(window->mlx, window->addr));
	return (0);
}

int	ft_window_close(t_window *window)
{
	return (mlx_destroy_window(window->mlx, window->addr));
}

t_window	*ft_window_new(char *title, size_t width, size_t height)
{
	t_window	*window;
	void		*mlx;

	mlx = mlx_init();
	if (mlx == NULL)
		return (NULL);
	window = malloc(sizeof(t_window));
	window->width = width;
	window->height = height;
	window->mlx = mlx;
	window->addr = mlx_new_window(mlx, width, height, title);
	window->title = title;
	mlx_hook(window->addr, 17, 0, ft_window_close, window);
	mlx_hook(window->addr, 2, 1L << 0, ft_handler_keys, window);
	return (window);
}

void	ft_window_putimage(t_window *window, t_image *image, int x, int y)
{
	if (window == NULL || window->mlx == NULL || window->addr == NULL)
		return ;
	if (image == NULL || image->data == NULL || image->data->img == NULL)
		return ;
	mlx_put_image_to_window(window->mlx, window->addr, image->data->img, x, y);
}
