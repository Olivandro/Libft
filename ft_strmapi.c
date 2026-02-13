/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alball <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:39:28 by alball            #+#    #+#             */
/*   Updated: 2025/11/22 14:39:36 by alball           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*p;
	size_t	len;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	p = (char *) malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (*(s + i))
	{
		*(p + i) = (f)(i, *(s + i));
		i++;
	}
	*(p + i) = '\0';
	return (p);
}
