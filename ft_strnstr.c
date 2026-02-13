/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alball <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:41:02 by alball            #+#    #+#             */
/*   Updated: 2025/11/22 14:41:10 by alball           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *) big);
	j = 0;
	while (len && *(big + j))
	{
		i = 0;
		while (*(little + i) && len > (j + i))
		{
			if (*(big + j + i) == *(little + i))
				i++;
			else
				break ;
		}
		if (*(little + i) == '\0')
			return ((char *)big + j);
		j++;
	}
	return (NULL);
}
