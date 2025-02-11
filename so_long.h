/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:47:43 by mmoulati          #+#    #+#             */
/*   Updated: 2025/02/11 16:45:08 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H
# define DEFAULT_HEIGHT 1080
# define DEFAULT_WIDTH 1920

# include "key.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

typedef unsigned int	t_color;
typedef unsigned char	t_byte;

typedef enum e_event
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
}						t_event;

typedef struct s_data
{
	void				*img;
	char				*addr;
	int					bpp;
	int					line_length;
	int					endian;
}						t_data;

typedef struct s_window
{
	void				*mlx;
	void				*addr;
	size_t				width;
	size_t				height;
	char				*title;
}						t_window;

typedef struct s_image
{
	void				*mlx;
	t_data				*data;
	size_t				height;
	size_t				width;
}						t_image;

void					*ft_data_address(t_data *data);
int						ft_data_offset(t_data *data, int x, int y);

void					ft_data_putpixel(t_data *data, int x, int y, int color);
void					ft_image_putpixel(t_image *image, int x, int y,
							int color);
void					ft_window_putimage(t_window *window, t_image *image,
							int x, int y);

t_data					*ft_data_new(void *mlx, size_t width, size_t height);
t_image					*ft_image_new(void *mlx, size_t width, size_t height);
t_window				*ft_window_new(char *title, size_t width,
							size_t height);

t_byte					ft_color_opacity(t_color color);
t_byte					ft_color_red(t_color color);
t_byte					ft_color_green(t_color color);
t_byte					ft_color_blue(t_color color);
t_color					ft_color_rgba(t_byte red, t_byte green, t_byte blue,
							t_byte opacity);
#endif
