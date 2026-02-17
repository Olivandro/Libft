/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alball <alball@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 13:14:31 by alball            #+#    #+#             */
/*   Updated: 2025/12/23 13:15:08 by alball           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*n_ptr;

	n_ptr = malloc(size);
	if (!n_ptr)
	{
		free(ptr);
		return (NULL);
	}
	ft_bzero(n_ptr, size);
	ft_memcpy(n_ptr, ptr, size);
	free(ptr);
	return (n_ptr);
}
