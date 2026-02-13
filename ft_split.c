/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alball <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:30:57 by alball            #+#    #+#             */
/*   Updated: 2025/11/22 14:31:13 by alball           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wordcount(const char *s, char c)
{
	size_t	wc;
	char	*tmp;
	int		word;

	wc = 0;
	tmp = (char *) s;
	word = 0;
	while (*tmp)
	{
		while (*tmp && *tmp != c)
		{
			tmp++;
			word = 1;
		}
		while (*tmp && *tmp == c)
			tmp++;
		if (word)
			wc++;
	}
	return (wc);
}

static size_t	findstart(const char *s, char c, size_t start, size_t wi)
{
	size_t	i;

	i = start;
	if (wi == 0 && *(s + i) != c)
		return (i);
	while (*(s + i) && *(s + i) != c)
		i++;
	while (*(s + i) && *(s + i) == c)
		i++;
	return (i);
}

static size_t	findlen(const char *s, char c, size_t start)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = start;
	while (*(s + i) && *(s + i) != c)
	{
		i++;
		len++;
	}
	return (len);
}

static char	*ft_strndup(const char *s, char c, size_t start)
{
	size_t	len;
	size_t	i;
	char	*p;

	len = findlen(s, c, start);
	p = (char *) malloc((len + 1) * sizeof(char));
	i = 0;
	if (!p)
		return (NULL);
	while (len--)
	{
		*(p + i) = *(s + start);
		start++;
		i++;
	}
	*(p + i) = '\0';
	return (p);
}

char	**ft_split(const char *s, char c)
{
	char	**p;
	size_t	start;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	start = findstart(s, c, 0, i);
	p = (char **) malloc((wordcount(s, c) + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	while (i < wordcount(s, c))
	{
		p[i] = ft_strndup(s, c, start);
		if (!p[i])
		{
			free(p);
			return (NULL);
		}
		i++;
		start = findstart(s, c, start, i);
	}
	*(p + i) = (void *) 0;
	return (p);
}
