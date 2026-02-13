/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alball <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:25:51 by alball            #+#    #+#             */
/*   Updated: 2025/11/22 14:25:59 by alball           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dp;
	char	*sp;

	dp = (char *) dest;
	sp = (char *) src;
	if (!dp && !sp)
		return (NULL);
	if (sp < dp)
		while (n--)
			dp[n] = sp[n];
	else
		while (n--)
			*dp++ = *sp++;
	return (dest);
}
