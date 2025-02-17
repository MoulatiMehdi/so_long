/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:17:07 by mmoulati          #+#    #+#             */
/*   Updated: 2025/02/10 11:32:37 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	if (str == NULL)
		return (NULL);
	c = (char)c;
	i = 0;
	while (1)
	{
		if (str[i] == c)
			return ((char *)str + i);
		if (!str[i])
			break ;
		i++;
	}
	return (NULL);
}
