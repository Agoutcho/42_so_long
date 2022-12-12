/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atchougo <atchougo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 05:43:59 by atchougo          #+#    #+#             */
/*   Updated: 2022/10/09 22:14:07 by atchougo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./../libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
void	ft_putnbr_printf(int n, int *r);
void	ft_putadr(unsigned long p, int *r);
void	ft_putnbr_u(unsigned int n, int *r);
void	ft_puthexa_low(int n, int *r);
void	ft_puthexa_up(int n, int *r);
void	ft_putchar_printf(char c, int *r);

#endif
