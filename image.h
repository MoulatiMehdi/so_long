#ifndef IMAGE_H

# define IMAGE_H

# include "color.h"
# include "stdbool.h"

typedef struct s_point
{
	int		x;
	int		y;

}			t_point;

typedef struct s_ellipse
{
	t_point	center;
	int		raduis_x;
	int		raduis_y;
}			t_ellipse;

typedef struct s_image
{
	void	*mlx;
	int		bpp;
	int		width;
	int		height;
	int		endian;
	char	*pixels;
	void	*address;
	int		line_length;
}			t_image;

t_color		ft_image_getcolor(t_image *data, int x, int y);

void		ft_image_clear(t_image **data);
void		ft_image_putpixel(t_image *data, int x, int y, t_color color);
void		ft_image_fill(t_image *img, t_color color);

// void		ft_image_grid(t_image *image, int stepx, int stepy, t_color color);
t_image		*ft_image_new(void *mlx, int width, int height);
t_image		*ft_image_from_xpm(void *mlx, char *filename);

void		ft_image_putpixel(t_image *data, int x, int y, t_color color);
bool		ft_ellipse_inside(t_ellipse *ellipse, t_point *p);
char		*ft_image_pixels(t_image *data);
#endif // !IMAGE_H
