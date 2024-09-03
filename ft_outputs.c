/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outputs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:12:11 by msisto            #+#    #+#             */
/*   Updated: 2024/04/19 14:58:51 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int		i;
	char	*n;

	n = "(null)";
	i = -1;
	if (!s)
	{
		while (n[++i])
			ft_putchar(n[i]);
		return (i);
	}
	while (s[++i])
		ft_putchar(s[i]);
	return (i);
}

int	nlen(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*out;
	int		len;

	len = nlen(n);
	out = ft_calloc(len + 1, sizeof(char));
	if (!out)
		return (NULL);
	out[len] = '\0';
	if (n < 0)
		out[0] = '-';
	else if (n < 10 && n >= 0)
	{
		out[0] = n + 48;
		return (out);
	}
	while (len-- > 0 && n)
	{
		if (n < 0)
			out[len] = (-(n % 10)) + 48;
		else
			out[len] = (n % 10) + 48;
		n /= 10;
	}
	return (out);
}

int	ft_putnbr(int n)
{
	char	*num;

	num = ft_itoa(n);
	ft_putstr(num);
	free(num);
	return (nlen(n));
}
