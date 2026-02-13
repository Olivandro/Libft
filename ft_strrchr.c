/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alball <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:41:30 by alball            #+#    #+#             */
/*   Updated: 2025/11/22 15:33:25 by alball           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	size_t	i;

	if (c > UCHAR_MAX)
		c -= UCHAR_MAX + 1;
	i = 0;
	p = (char *) s;
	while (s[i] != '\0')
		i++;
	while (i > 0)
	{
		if (*(p + i) == c)
			return (p + i);
		i--;
	}
	if (*(p + i) == c)
		return (p + i);
	return (NULL);
}
