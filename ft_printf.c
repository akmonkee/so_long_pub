/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:22:02 by msisto            #+#    #+#             */
/*   Updated: 2024/04/11 15:27:56 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_which_fun(va_list *ap, const char l)
{
	int	i;

	i = 0;
	if (l == 'c')
		return (ft_putchar(va_arg(*ap, int)));
	else if (l == 's')
		return (ft_putstr(va_arg(*ap, char *)));
	else if (l == 'd')
		return (ft_putnbr(va_arg(*ap, int)));
	else if (l == 'i')
		return (ft_putnbr(va_arg(*ap, int)));
	else
		return (ft_putchar(l));
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		num;

	i = -1;
	num = 0;
	va_start(ap, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			num += ft_which_fun(&ap, str[i]);
		}
		else
			num += ft_putchar(str[i]);
	}
	va_end(ap);
	return (num);
}
