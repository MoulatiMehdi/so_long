#ifndef IMAGE_H

# define IMAGE_H

# include "color.h"

typedef struct s_image
{
    void * mlx;
	int		bpp;
	int		width;
	int		height;
	int		endian;
	char	*pixels;
	void	*address;
	int		line_length;
}			t_image;

typedef struct s_rect
{
    int x;
    int y;
    int width;
    int height;
} t_rect;

t_color		ft_image_getcolor(t_image *data, int x, int y);

void		ft_image_clear(t_image **data);
void		ft_image_toimage(t_image *dest, t_image *src, t_rect rect);
void		ft_image_putpixel(t_image *data, int x, int y, t_color color);

t_image		*ft_image_new(void *mlx, int width, int height);
t_image		*ft_image_from_xpm(void *mlx, char *filename);

#endif // !IMAGE_H
