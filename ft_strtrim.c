/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alball <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:42:06 by alball            #+#    #+#             */
/*   Updated: 2025/11/22 14:42:28 by alball           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	inset(char c, const char *set)
{
	unsigned int	i;

	i = 0;
	while (*(set + i) != '\0')
	{
		if (c == *(set + i))
			return (1);
		i++;
	}
	return (0);
}

static size_t	findstart(const char *s, const char *set)
{
	size_t	start;

	start = 0;
	while (*(s + start) && inset(*(s + start), set))
		start++;
	return (start);
}

static size_t	findend(const char *s, const char *set)
{
	size_t	end;

	end = ft_strlen(s) - 1;
	while (end && inset(*(s + end), set))
		end--;
	return (end);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*p;

	if (!s1)
		return (NULL);
	start = findstart(s1, set);
	end = findend(s1, set);
	if (start > end || *s1 == '\0')
	{
		p = (char *) malloc(sizeof(char));
		if (!p)
			return (NULL);
		*p = '\0';
		return (p);
	}
	i = 0;
	p = (char *) malloc((end - start + 2) * sizeof(char));
	if (!p)
		return (NULL);
	while (start <= end)
		*(p + i++) = *(s1 + start++);
	*(p + i) = '\0';
	return (p);
}
