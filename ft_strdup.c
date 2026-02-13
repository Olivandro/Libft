/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alball <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:32:22 by alball            #+#    #+#             */
/*   Updated: 2025/11/22 14:34:00 by alball           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	nmemb;
	size_t	i;
	char	*dup;

	nmemb = strlen(s) + 1;
	dup = (char *) malloc(nmemb * sizeof(char));
	i = 0;
	if (!dup)
		return (0);
	while (s[i] != '\0')
	{
		*(dup + i) = s[i];
		i++;
	}
	*(dup + i) = '\0';
	return (dup);
}
