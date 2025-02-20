
#include "image.h"
#include "mlx.h"
#include "so_long.h"
#include <math.h>

static int	ft_image_offset(t_image *data, int x, int y)
{
    int offset = y * data->line_length + x * (data->bpp / 8);

    return (offset);
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

void ft_image_grid(t_image * image,int stepx,int stepy,t_color color)
{
    int i;
    int j;

    i = 0;
    while(i < WINDOW_HEIGHT)
    {
        j = 0;
        while(j < WINDOW_WIDTH)
        {
            ft_image_putpixel(image, j, i, color);
            j++;
        }

        i+= stepy;
    }
    j = 0;
    while(j < WINDOW_WIDTH)
    {
        i = 0;
        while(i < WINDOW_HEIGHT)
        {
            ft_image_putpixel(image, j, i, color);
            i++;
        }
        j+= stepx;
    }
}

void	ft_image_ellipse(t_image *img,t_sprite * sprite, t_point * point,t_color color)
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
            if(sprite->width == 0 || sprite->height == 0 || pow(i - point->x,2) /pow(sprite->width,2) + pow(j - point->y,2) / pow(sprite->height,2) >= 1 )
                ft_image_putpixel(img, i, j, color);
            j++;
        }
        i++;
    }
}
