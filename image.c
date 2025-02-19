
#include "image.h"
#include "mlx.h"
#include "so_long.h"

static int	ft_image_offset(t_image *data, int x, int y)
{
	return (y * data->line_length + x * (data->bpp / 8));
}

static char	*ft_image_pixels(t_image *data)
{
	return (mlx_get_data_addr(data->address, &data->bpp, &data->line_length,
			&data->endian));
}

t_color	ft_image_getcolor(t_image *data, int x, int y)
{
	int	color;

	if (data == NULL)
		return (0XFF000000);
	if (data->height < y || data->width < x)
		return (0XFF000000);
	if (y < 0 || x < 0)
		return (0);
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
	t_image	*data;

	if (mlx == NULL)
		return (NULL);
	data = malloc(sizeof(t_image));
	if (data == NULL)
		return (NULL);
	data->address = mlx_new_image(mlx, width, height);
	data->pixels = ft_image_pixels(data);
	data->height = height;
	data->width = width;
	data->mlx = mlx;
	return (data);
}

void	ft_image_clear(t_image **data)
{
	if (!data || !*data)
		return ;
	if ((*data)->mlx && (*data)->address)
		mlx_destroy_image((*data)->mlx, (*data)->address);
	free(*data);
	*data = NULL;
}

void ft_image_dup(t_image * dest,t_image * src, int x , int y)
{
	int	dy;
	int	dx;
	int	color;
	int	height;
	int	width;

	height = src->height;
	width = src->width;
	if (src->width + x > dest->width)
		width = dest->width - x;
	if (src->height + y > dest->height)
		height = dest->height - y;
	dy = (y < 0) * (- y);
	while (dy < height)
	{
		dx = (x < 0) * (-x);
		while (dx < width)
		{
			color = ft_image_getcolor(src, dx, dy);
			ft_image_putpixel(dest, x + dx, y + dy, color);
			dx++;
		}
		dy++;
	}

}

void	ft_image_toimage(t_image * dest,t_image *src,t_rect rect)
{
	int	dy;
	int	dx;
	int	color;
	int	height;
	int	width;

	height = src->height;
	width = src->width;
	if (src->width + rect.x > dest->width)
		width = dest->width - rect.x;
	if (src->height + rect.y > dest->height)
		height = dest->height - rect.y;
	dy = (rect.y < 0) * (- rect.y);
	while (dy < height)
	{
		dx = (rect.x < 0) * (-rect.x);
		while (dx < width)
		{
			color = ft_image_getcolor(src, dx, dy);
			ft_image_putpixel(dest, rect.x + dx, rect.y + dy, color);
			dx++;
		}
		dy++;
	}
}

void	ft_image_towindow(t_image *image, t_render *render, int x, int y)
{
	if (image == NULL || render == NULL)
		return ;
	mlx_put_image_to_window(render->mlx, render->window, image->address, x, y);
}
