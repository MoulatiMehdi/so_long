/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:17:03 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/13 20:57:12 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*p;
	int				power;
	unsigned int	len;
	long			nbr;

	len = n < 0;
	nbr = n * (-2 * (len++) + 1);
	power = 1;
	while (nbr / power >= 10)
	{
		power *= 10;
		len++;
	}
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	p[len] = 0;
	while (len--)
	{
		p[len] = '0' + nbr % 10;
		nbr /= 10;
	}
	if (n < 0)
		p[0] = '-';
	return (p);
}
