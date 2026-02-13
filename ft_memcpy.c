/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alball <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:25:12 by alball            #+#    #+#             */
/*   Updated: 2025/11/22 14:25:23 by alball           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dp;
	char	*sp;

	if (dest == NULL && src == NULL)
		return (NULL);
	dp = (char *)dest;
	sp = (char *)src;
	while (n--)
	{
		*dp = *sp;
		dp++;
		sp++;
	}
	return (dest);
}
