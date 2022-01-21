/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 22:59:52 by nfarkas           #+#    #+#             */
/*   Updated: 2021/12/25 22:59:57 by nfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

void	ft_s(char *str, int *len)
{
	if (str == NULL)
		*len += write(1, "(null)", 6);
	else
		*len += write(1, str, ft_strlen(str));
}

int	ft_specif(int c, va_list argv)
{
	int		len;
	char	ch;

	len = 0;
	if (c == 'c')
	{
		ch = (char) va_arg(argv, int);
		len += write(1, &ch, 1);
	}
	if (c == 's')
		ft_s(va_arg(argv, char *), &len);
	if (c == 'p')
		len += ft_p(va_arg(argv, unsigned long long));
	if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(argv, int));
	if (c == 'u')
		len += ft_u(va_arg(argv, unsigned int));
	if (c == 'x')
		len += ft_x(va_arg(argv, unsigned int));
	if (c == 'X')
		len += ft_xmax(va_arg(argv, unsigned int));
	return (len);
}

int	ft_parsing(va_list argv, const char *s)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] != '%')
			len += write(1, &s[i++], 1);
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			if (s[i] == '%')
				len += write(1, "%", 1);
			if (ft_specifier(s[i]))
				len += ft_specif(s[i], argv);
			i++;
		}
	}
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		count;
	va_list	argv;

	count = 0;
	va_start(argv, s);
	count += ft_parsing(argv, s);
	va_end(argv);
	return (count);
}
