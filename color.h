#ifndef COLOR_H
#define COLOR_H
typedef unsigned int t_color;
typedef unsigned char t_byte;

t_byte ft_color_opacity(t_color color);
t_byte ft_color_red(t_color color);
t_byte ft_color_green(t_color color);
t_byte ft_color_blue(t_color color);
t_color ft_color_rgba(t_byte red, t_byte green, t_byte blue, t_byte opacity);

#endif // !COLOR_H
