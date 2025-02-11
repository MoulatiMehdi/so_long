/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_dup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:57:22 by mmoulati          #+#    #+#             */
/*   Updated: 2025/02/11 22:57:31 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strs_dup(char **map)
{
	char	**strs;
	size_t	height;
	size_t	i;

	if (map == NULL)
		return (NULL);
	i = 0;
	height = 0;
	while (map[height])
		height++;
	strs = malloc((height + 1) * sizeof(char *));
	while (i < height)
	{
		strs[i] = ft_strdup(map[i]);
		i++;
	}
	strs[height] = NULL;
	return (strs);
}
