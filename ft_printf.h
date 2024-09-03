/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msisto <msisto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:10:28 by msisto            #+#    #+#             */
/*   Updated: 2024/04/19 15:00:33 by msisto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		nlen(long n);
int		ft_putnbr(int n);
int		ft_put_u_nbr(unsigned int n);
int		ft_putstr(char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_itoa(int n);
int		ft_putnbr(int n);

#endif
