/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:13:23 by msisto            #+#    #+#             */
/*   Updated: 2024/02/05 11:41:15 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

void	*ft_calloc(size_t count, size_t size)
{
	char			*mem;
	size_t			i;
	unsigned long	len;

	i = -1;
	mem = NULL;
	len = (unsigned long)size * (unsigned long)count;
	if (count && size && count > (4294967295U / size))
		return (0);
	mem = malloc(len);
	if (!mem)
		return (NULL);
	while (++i < len)
	{
		mem[i] = 0;
	}
	return (mem);
}
