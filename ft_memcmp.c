/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alball <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:24:32 by alball            #+#    #+#             */
/*   Updated: 2025/11/22 14:24:43 by alball           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *) s1;
	p2 = (unsigned char *) s2;
	if (p1 == p2 || n == 0)
		return (0);
	while (n--)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		if (n)
		{
			p1++;
			p2++;
		}
	}
	return (*p1 - *p2);
}
