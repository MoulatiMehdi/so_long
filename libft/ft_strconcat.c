/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strconcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 18:29:40 by mmoulati          #+#    #+#             */
/*   Updated: 2025/02/10 11:32:19 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strconcat(char **target, char *str)
{
	char	*tmp;

	if (target == NULL || str == NULL)
		return ;
	tmp = *target;
	*target = ft_strjoin(*target, str);
	free(tmp);
}
