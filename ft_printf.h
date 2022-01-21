/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarkas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:00:13 by nfarkas           #+#    #+#             */
/*   Updated: 2021/12/25 23:00:20 by nfarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *s, ...);
int		ft_putchr(int c);
int		ft_specifier(int s);
size_t	ft_strlen(const char *s);
int		ft_putnbr(int n);
void	print_nbr(long nbr, int *len);
void	ft_s(char *str, int *len);
int		ft_u(unsigned int n);
int		ft_x(unsigned int n);
int		ft_xmax(unsigned int n);
int		ft_p(unsigned long long n);

#endif
