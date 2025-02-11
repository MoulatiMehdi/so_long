/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:17:08 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/13 21:09:25 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;

	slen = ft_strlen(src);
	if (dstsize == 0 && !dst)
		return (slen);
	dlen = ft_strlen(dst);
	if (dstsize <= dlen)
		return (dstsize + slen);
	dstsize -= dlen + 1;
	if (dstsize > slen)
		dstsize = slen;
	i = 0;
	while (i < dstsize)
	{
		dst[i + dlen] = src[i];
		i++;
	}
	dst[dlen + dstsize] = '\0';
	return (slen + dlen);
}
