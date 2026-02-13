/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alball <alball@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 13:04:23 by alball            #+#    #+#             */
/*   Updated: 2025/12/23 18:01:56 by alball           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

static void	insert_str(char **dest, char *src)
{
	char	*chk;

	chk = src;
	if (chk)
		*dest = ft_strdup(chk);
	else
		*dest = ft_strdup("(null)");
}

#if __linux__

static void	insert_ptr(char **dest, unsigned long src)
{
	unsigned long	chk;

	chk = src;
	if (chk)
		*dest = ltoh(chk, 1, 1);
	else
		*dest = ft_strdup("(nil)");
}
#elif __APPLE__

static void	insert_ptr(char **dest, unsigned long src)
{
	unsigned long	chk;

	chk = src;
	if (chk)
		*dest = ltoh(chk, 1, 1);
	else
		*dest = ft_strdup("0x0");
}
#endif

static void	print_insert(char **input, int *size)
{
	size_t	i;

	i = 0;
	if (!*input)
		*size += 1;
	else
	{
		while (input[0][i])
		{
			ft_putchar_fd(input[0][i++], 1);
			*size += 1;
		}
		free(*input);
	}
}

void	insert(t_ftpf_data *pdata, const char *str)
{
	char	*input;

	input = NULL;
	if (*str == 'd' || *str == 'i')
		input = ft_itoa(va_arg(pdata->args, int));
	if (*str == 'u')
		input = ltoa((long)va_arg(pdata->args, unsigned int));
	if (*str == '%')
		ft_putchar_fd('%', 1);
	if (*str == 'c')
		ft_putchar_fd((char)va_arg(pdata->args, int), 1);
	if (*str == 's')
		insert_str(&input, va_arg(pdata->args, char *));
	if (*str == 'p')
		insert_ptr(&input, va_arg(pdata->args, unsigned long));
	if (*str == 'x')
		input = ltoh((unsigned long)va_arg(pdata->args, unsigned int), 1, 0);
	if (*str == 'X')
		input = ltoh((unsigned long)va_arg(pdata->args, unsigned int), 0, 0);
	print_insert(&input, &pdata->size);
}
