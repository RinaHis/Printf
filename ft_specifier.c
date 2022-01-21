/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:00:39 by nfarkas           #+#    #+#             */
/*   Updated: 2021/12/25 23:00:43 by nfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int	ft_u(unsigned int n)
{
	int	len;

	len = 0;
	print_nbr(n, &len);
	return (len);
}

int	ft_x(unsigned int n)
{
	static char	s[] = "0123456789abcdef";
	char		t[20];
	int			len;
	int			i;

	if (!n)
	{
		write(1, "0", 1);
		return (1);
	}
	i = 0;
	while (n)
	{
		t[i++] = s[n % 16];
		n /= 16;
	}
	t [i] = '\0';
	len = i;
	i--;
	while (i >= 0)
		write(1, &t[i--], 1);
	return (len);
}

int	ft_xmax(unsigned int n)
{
	static char	s[] = "0123456789ABCDEF";
	char		t[20];
	int			len;
	int			i;

	if (!n)
	{
		write(1, "0", 1);
		return (1);
	}
	i = 0;
	while (n)
	{
		t[i++] = s[n % 16];
		n /= 16;
	}
	t [i] = '\0';
	len = i;
	i--;
	while (i >= 0)
		write(1, &t[i--], 1);
	return (len);
}

int	ft_p(unsigned long long n)
{
	char	*hxd;
	char	t[20];
	int		len;
	int		i;

	hxd = "0123456789abcdef";
	if (!n)
	{
		write(1, "0x0", 3);
		return (3);
	}
	i = 0;
	while (n)
	{
		t[i++] = hxd[n % 16];
		n /= 16;
	}
	t[i] = '\0';
	len = i + 2;
	i--;
	write(1, "0x", 2);
	while (i >= 0)
		write(1, &t[i--], 1);
	return (len);
}
