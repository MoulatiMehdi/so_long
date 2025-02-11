/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:17:05 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/13 20:59:47 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	c = (unsigned char)c;
	p = (void *)s;
	i = 0;
	while (i < n)
	{
		if (p[i] == c)
			return (p + i);
		i++;
	}
	return (NULL);
}
