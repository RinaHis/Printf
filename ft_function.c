/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 22:59:28 by nfarkas           #+#    #+#             */
/*   Updated: 2021/12/25 22:59:42 by nfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

int	ft_putchr(int c)
{
	return (write(1, &c, 1));
}

int	ft_specifier(int s)
{
	return (s == 'c' || s == 's' || s == 'p' || s == 'd'
		|| s == 'i' || s == 'u' || s == 'x' || s == 'X');
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	print_nbr(long nbr, int *len)
{
	if (nbr >= 10)
	{
		print_nbr(nbr / 10, len);
		print_nbr(nbr % 10, len);
	}
	else
		*len += ft_putchr(nbr + '0');
}

int	ft_putnbr(int n)
{
	long	nbr;
	int		len;

	nbr = n;
	len = 0;
	if (nbr < 0)
	{
		len += write(1, "-", 1);
		nbr = -1 * nbr;
	}
	print_nbr(nbr, &len);
	return (len);
}
