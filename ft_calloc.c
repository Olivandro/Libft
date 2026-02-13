/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alball <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:09:40 by alball            #+#    #+#             */
/*   Updated: 2025/11/22 14:09:48 by alball           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	memsize;

	p = NULL;
	if (nmemb == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	if (size && SIZE_MAX / size < nmemb)
		return (NULL);
	memsize = nmemb * size;
	p = malloc(memsize);
	if (!p)
		return (NULL);
	while (memsize--)
		*(unsigned char *)(p + memsize) = 0;
	return (p);
}
