#ifndef DATA_H

#define DATA_H

#include "color.h"
#include "mlx.h"
#include "stdlib.h"

typedef struct s_image {
  int bpp;
  int width;
  int height;
  int endian;
  char *pixels;
  void *address;
  int line_length;
} t_image;


void ft_image_putpixel(t_image *data, int x, int y, t_color color);
void ft_image_clear(void *mlx, t_image **data);

t_image *ft_image_new(void *mlx, int width, int height);
t_color ft_image_getcolor(t_image *data, int x, int y);

#endif // !DATA_H
