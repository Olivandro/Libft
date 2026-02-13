/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alball <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:14:48 by alball            #+#    #+#             */
/*   Updated: 2025/11/22 14:15:02 by alball           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	intcount(int n)
{
	size_t	ic;

	ic = 0;
	if (n == 0)
		return (2);
	if (n == INT_MIN)
		return (12);
	if (n < 0)
		ic += 1;
	while (n)
	{
		n = n / 10;
		ic++;
	}
	return (ic + 1);
}

static void	int2char(long n, char *s, size_t *i)
{
	if (n > 9)
	{
		int2char(n / 10, s, i);
		int2char(n % 10, s, i);
	}
	else
		s[(*i)++] = n + '0';
}

char	*ft_itoa(int n)
{
	char	*p;
	size_t	ic;
	size_t	i;

	i = 0;
	ic = intcount(n);
	p = (char *) malloc(ic * sizeof(char));
	if (!p)
		return (NULL);
	if (n < 0)
	{
		p[i++] = '-';
		if (n == INT_MIN)
		{
			n = 147483648;
			p[i++] = '2';
		}
		else
		{
			n = -n;
		}
	}
	int2char((long) n, p, &i);
	p[i] = '\0';
	return (p);
}
