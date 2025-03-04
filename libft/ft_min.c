/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:17:05 by mmoulati          #+#    #+#             */
/*   Updated: 2024/11/13 21:00:16 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_max(long a, long b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

long	ft_min(long a, long b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
