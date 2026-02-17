/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ltoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alball <alball@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 13:04:38 by alball            #+#    #+#             */
/*   Updated: 2025/12/23 13:17:54 by alball           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

size_t	countlong(long n)
{
	long	i;

	i = 0;
	if (n < 1)
		return (2);
	else
	{
		while (n > 0)
		{
			n = n / 10;
			i++;
		}
	}
	return (i + 1);
}

void	long2char(char *ptr, long num, size_t *idx)
{
	if (num > 9)
	{
		long2char(ptr, num / 10, idx);
		long2char(ptr, num % 10, idx);
	}
	else
		ptr[(*idx)++] = num + '0';
}

char	*ltoa(long n)
{
	char	*p;
	size_t	i;
	size_t	uic;

	uic = countlong(n);
	p = (char *) ft_calloc(uic, sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	long2char(p, n, &i);
	return (p);
}
