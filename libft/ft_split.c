/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 21:23:31 by mmoulati          #+#    #+#             */
/*   Updated: 2025/02/10 11:32:41 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_strs(char const *s, char *c)
{
	size_t	count;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while (s[i] && ft_strchr(c, s[i]) != NULL)
		i++;
	while (s[i])
	{
		while (s[i] && ft_strchr(c, s[i]) == NULL)
			i++;
		count++;
		while (s[i] && ft_strchr(c, s[i]) != NULL)
			i++;
		if (!s[i])
			break ;
	}
	return (count + (count == 0));
}

static char	**free_all(char **strs, size_t size)
{
	while (size--)
	{
		if (strs[size])
			free(strs[size]);
		strs[size] = NULL;
	}
	free(strs);
	strs = NULL;
	return (NULL);
}

static char	*ft_split_dup(const char **s, char *charset)
{
	size_t	size;
	char	*str;

	size = 0;
	while (s[size] && ft_strchr(charset, (*s)[size]) == NULL)
		size++;
	str = ft_substr(*s, 0, size);
	*str += size;
	return (str);
}

void	ft_split_free(char ***strs)
{
	int	i;

	if (strs == NULL || *strs == NULL)
		return ;
	i = 0;
	while ((*strs)[i])
	{
		free((*strs)[i]);
		i++;
	}
	free(*strs);
	*strs = NULL;
}

char	**ft_split(char const *s, char *charset)
{
	char	**strs;
	size_t	j;

	if (!s || !charset)
		return (NULL);
	strs = malloc(sizeof(char *) * (count_strs(s, charset) + 1));
	if (!strs)
		return (NULL);
	j = 0;
	while (*s)
	{
		while (*s && ft_strchr(charset, *s) != NULL)
			s++;
		if (!*s)
			break ;
		strs[j] = ft_split_dup(&s, charset);
		if (!strs[j++])
			return (free_all(strs, j));
	}
	if (j == 0)
		strs[j++] = ft_strdup("");
	strs[j] = NULL;
	return (strs);
}
