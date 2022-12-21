/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 04:57:23 by atchougo          #+#    #+#             */
/*   Updated: 2021/12/28 04:59:52 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_aff(unsigned int n, int fd)
{
	if (!n)
		return ;
	ft_aff(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;
	int				sign;

	sign = 1;
	if (!n)
		ft_putchar_fd('0', fd);
	else if (n < 0)
	{
		sign = -1;
		ft_putchar_fd('-', fd);
	}
	un = n * sign;
	ft_aff(un, fd);
}
