/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alball <alball@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:06:18 by alball            #+#    #+#             */
/*   Updated: 2025/12/23 17:53:20 by alball           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * ft_printf(const char *str, ...)
 * @TODO:
 */
#include "ft_printf_utils.h"

static void	str_print(const char *str, t_ftpf_data *pdata)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			insert(pdata, &str[i + 1]);
			i += 2;
		}
		else if (str[i] != '%')
		{
			ft_putchar_fd(str[i++], 1);
			pdata->size++;
		}
	}
}

int	ft_printf(const char *str, ...)
{
	t_ftpf_data	pdata;

	if (!str || (int)ft_strlen(str) > INT_MAX)
		return (-1);
	ft_memset(&pdata, 0, sizeof(pdata));
	pdata.vaptr = ft_strchr(str, '%');
	if (!pdata.vaptr)
	{
		ft_putstr_fd((char *)str, 1);
		return ((int)ft_strlen(str));
	}
	va_start(pdata.args, str);
	str_print(str, &pdata);
	va_end(pdata.args);
	return (pdata.size);
}
