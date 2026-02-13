/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alball <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:37:56 by alball            #+#    #+#             */
/*   Updated: 2025/11/22 14:38:08 by alball           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	rtn;
	size_t	strlen;

	rtn = 0;
	i = 0;
	strlen = size - 1;
	while (src[rtn] != '\0')
		rtn++;
	if (!size)
		return (rtn);
	while (strlen-- && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (rtn);
}
