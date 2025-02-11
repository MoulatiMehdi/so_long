/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:17:09 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/13 21:14:38 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init_lookup(const char *set, char lookup[])
{
	size_t	i;

	i = 0;
	ft_memset(lookup, 1, 256);
	if (set)
	{
		while (set[i])
			lookup[(unsigned char)set[i++]] = 0;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	char	lookup[256];
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	if (end == 0)
		return (ft_strdup(""));
	end--;
	if (set)
	{
		init_lookup(set, lookup);
		while (s1[start] && !lookup[(unsigned char)s1[start]])
			start++;
		while (end && !lookup[(unsigned char)s1[end]])
			end--;
	}
	p = ft_substr(s1, start, end - start + 1);
	return (p);
}
