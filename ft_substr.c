/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alball <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:42:45 by alball            #+#    #+#             */
/*   Updated: 2025/11/22 16:18:43 by alball           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	srcchk(char const *s, unsigned int start, size_t len)
{
	size_t	nmemb;

	nmemb = ft_strlen(s);
	if (start > nmemb && len == 1)
		return (1);
	if (start > nmemb && len > nmemb)
		return (1);
	if (nmemb == len)
		return ((len - start) + 1);
	if (len < nmemb)
		nmemb = len + 1;
	else
		nmemb += 1;
	return (nmemb);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	nmemb;

	if (!s)
		return (NULL);
	i = 0;
	nmemb = srcchk(s, start, len);
	p = (char *) ft_calloc(nmemb, sizeof(char));
	if (!p)
		return (NULL);
	if (!(start >= ft_strlen(s)))
	{
		while (*(s + start) && len--)
		{
			*(p + i) = *(s + start);
			i++;
			start++;
		}
	}
	return (p);
}
