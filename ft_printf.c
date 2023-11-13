/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: metyasar <metyasar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:05:23 by metyasar          #+#    #+#             */
/*   Updated: 2023/07/24 19:05:31 by metyasar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_control(char c, va_list va)
{
	int	total;

	total = 0;
	if (c == 'c')
		total += ft_putchr(va_arg(va, int));
	else if (c == 's')
		total += ft_putstr(va_arg(va, char *));
	else if (c == 'd' || c == 'i')
		total += ft_putnbr(va_arg(va, int), 10, 0);
	else if (c == 'u')
		total += ft_putnbr(va_arg(va, unsigned int), 10, 0);
	else if (c == 'x')
		total += ft_putnbr(va_arg(va, unsigned int), 16, 0);
	else if (c == 'X')
		total += ft_putnbr(va_arg(va, unsigned int), 16, 1);
	else if (c == 'p')
		total += ft_putptr(va_arg(va, unsigned long), 16, 0);
	else
		total += ft_putchr(c);
	return (total);
}

int	ft_printf(const char *str, ...)
{
	va_list	va;
	int		total;

	va_start(va, str);
	total = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '\0')
		{
			total += ft_control(*(str + 1), va);
			str++;
		}
		else if (*str != '%')
			total += ft_putchr(*str);
		str++;
	}
	va_end(va);
	return (total);
}
