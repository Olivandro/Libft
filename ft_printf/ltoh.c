/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ltoh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alball <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:25:00 by alball            #+#    #+#             */
/*   Updated: 2025/12/23 13:18:16 by alball           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

static size_t	longcount(unsigned long n)
{
	size_t	lc;

	lc = 0;
	if (n == 0)
		return (4);
	if (n < 0)
		lc += 1;
	while (n)
	{
		n = n / 10;
		lc++;
	}
	return (lc + 3);
}

static void	long2hexa(unsigned long n, char *s, size_t *i, int lower)
{
	unsigned int	remainder;	

	if (n > 0)
	{
		remainder = n % 16;
		long2hexa(n / 16, s, i, lower);
		if (remainder < 10)
			s[(*i)++] = remainder + 48;
		else if (!lower)
			s[(*i)++] = remainder + 55;
		else
			s[(*i)++] = remainder + 55 + 32;
	}
}

char	*ltoh(unsigned long n, int lower, int pointer)
{
	unsigned int	lc;
	char			*p;
	size_t			i;

	i = 0;
	lc = longcount(n);
	p = (char *) ft_calloc(lc, sizeof(char));
	if (!p)
		return (NULL);
	if (pointer)
		i = ft_strlcpy(p, "0x", lc);
	if (n != 0)
		long2hexa(n, p, &i, lower);
	else
		*p = n + 48;
	return (p);
}
