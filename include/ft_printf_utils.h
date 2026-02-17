/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alball <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:23:49 by alball            #+#    #+#             */
/*   Updated: 2025/12/23 13:26:11 by alball           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include <stdarg.h>
# include "libft.h"

# define MIN_LIMIT 100000

typedef struct t_mod_data
{
	unsigned int	unused:1;
	unsigned int	plus:1;
	unsigned int	hash:1;
	unsigned int	space:1;
	unsigned int	l_pad:1;
	unsigned int	r_pad:1;
	unsigned int	percision:8;
	unsigned int	padding:18;
}	t_mod_data;

typedef struct t_ftpf_data
{
	va_list			args;
	char			*vaptr;
	t_mod_data		modifiers;
	int				size;
}	t_ftpf_data;

void	insert(t_ftpf_data *pdata, const char *str);
#endif
