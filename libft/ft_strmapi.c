/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:17:08 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/13 21:10:20 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	size_t	len;
	size_t	i;

	if (!s || !f)
		return (0);
	len = 0;
	while (s[len])
		len++;
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	p[len] = 0;
	i = 0;
	while (i < len)
	{
		p[i] = (*f)(i, s[i]);
		i++;
	}
	return (p);
}
