/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:17:05 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/13 21:00:30 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	const unsigned char	*p_src;
	unsigned char		*p_dst;

	if (!dst && !src)
		return (NULL);
	if (dst == src)
		return (dst);
	p_src = src;
	p_dst = dst;
	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			p_dst[i] = p_src[i];
			i++;
		}
	}
	else
	{
		while (len--)
			p_dst[len] = p_src[len];
	}
	return (dst);
}
