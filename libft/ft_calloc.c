/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:17:01 by mmoulati          #+#    #+#             */
/*   Updated: 2025/02/10 11:34:13 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	long	*p_long;
	char	*p_char;
	size_t	i;
	size_t	total;

	i = 0;
	if (!size || !count)
		return (malloc(0));
	if (size && count && count > SIZE_MAX / size)
		return (NULL);
	total = count * size;
	p = malloc(total);
	if (!p)
		return (NULL);
	p_long = p;
	p_char = p;
	while (total % sizeof(*p_long))
		p_char[--total] = 0;
	while (i * sizeof(*p_long) < total)
		p_long[i++] = 0;
	return (p_char);
}
