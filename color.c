/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:42:34 by mmoulati          #+#    #+#             */
/*   Updated: 2025/02/11 16:07:05 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_byte	ft_color_opacity(t_color color)
{
	return ((color >> 24) & 0xFF);
}

t_byte	ft_color_red(t_color color)
{
	return ((color >> 16) & 0xFF);
}

t_byte	ft_color_green(t_color color)
{
	return ((color >> 8) & 0xFF);
}

t_byte	ft_color_blue(t_color color)
{
	return (color & 0xFF);
}

t_color	ft_color_rgba(t_byte red, t_byte green, t_byte blue, t_byte opacity)
{
	int	color;

	color = 0;
	color += opacity;
	color <<= 8;
	color += red;
	color <<= 8;
	color += green;
	color <<= 8;
	color += blue;
	color <<= 8;
	return (color);
}
