/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:17:06 by mmoulati          #+#    #+#             */
/*   Updated: 2025/02/10 11:32:51 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	int		power;
	char	c;

	if (fd < 0)
		return ;
	nbr = n;
	power = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		write(fd, "-", 1);
	}
	while (nbr / power >= 10)
		power *= 10;
	while (power)
	{
		c = '0' + nbr / power;
		write(fd, &c, 1);
		nbr %= power;
		power /= 10;
	}
}
