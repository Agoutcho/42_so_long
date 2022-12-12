/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:15:14 by atchougo          #+#    #+#             */
/*   Updated: 2022/02/20 18:17:24 by atchougo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa_up(int n, int *r)
{
	char			*hexa;
	unsigned int	number;

	number = (unsigned int)n;
	hexa = "0123456789ABCDEF";
	if (number > 15)
		ft_puthexa_up((number / 16), r);
	ft_putchar_printf(hexa[number % 16], r);
}

void	ft_puthexa_low(int n, int *r)
{
	char			*hexa;
	unsigned int	number;

	number = (unsigned int)n;
	hexa = "0123456789abcdef";
	if (number > 15)
		ft_puthexa_low((number / 16), r);
	ft_putchar_printf(hexa[number % 16], r);
}

void	ft_putnbr_u(unsigned int n, int *r)
{
	char			*decimal;
	unsigned int	number;

	number = n;
	decimal = "0123456789";
	if (number > 9)
		ft_putnbr_u((number / 10), r);
	ft_putchar_printf(decimal[number % 10], r);
}

void	ft_putadr(unsigned long p, int *r)
{
	unsigned long	nb;
	char			*hexa;

	nb = p;
	hexa = "0123456789abcdef";
	if (nb > 15)
		ft_putadr((nb / 16), r);
	ft_putchar_printf(hexa[nb % 16], r);
}

void	ft_putnbr_printf(int n, int *r)
{
	char	*decimal;
	long	number;

	number = (long)n;
	decimal = "0123456789";
	if (number < 0)
	{
		number = -number;
		ft_putchar_printf('-', r);
	}
	if (number > 9)
		ft_putnbr_printf((number / 10), r);
	ft_putchar_printf(decimal[number % 10], r);
}
