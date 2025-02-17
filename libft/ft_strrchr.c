/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:17:09 by mmoulati          #+#    #+#             */
/*   Updated: 2025/02/10 11:29:47 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;

	if (str == NULL)
		return (NULL);
	i = 0;
	c = (char)c;
	while (str[i])
		i++;
	while (1)
	{
		if (str[i] == c)
			return ((char *)str + i);
		if (!i)
			break ;
		i--;
	}
	return (NULL);
}
