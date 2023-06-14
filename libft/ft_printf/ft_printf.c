/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carl <sde-carl@student.42roma.it >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:26:04 by sde-carl          #+#    #+#             */
/*   Updated: 2023/04/18 18:26:04 by sde-carl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_allcases(va_list args, const char c)
{
	int	length;

	length = 0;
	if (c == 'c')
		length += ft_putchar(va_arg(args, int));
	else if (c == 's')
		length += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		length += ft_putnbr(va_arg(args, int));
	else if (c == 'x')
		length += ft_puthexa(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		length += ft_puthexa(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == 'p')
		length += ft_putptr(va_arg(args, unsigned long));
	else if (c == 'u')
		length += ft_putunsigned(va_arg(args, unsigned int));
	else if (c == '%')
		length += ft_putchar('%');
	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		index;
	int		length;

	index = 0;
	length = 0;
	va_start(args, format);
	while (format[index])
	{
		if (format[index] == '%')
		{
			index++;
			length += ft_allcases(args, format[index]);
		}
		else
			length += ft_putchar(format[index]);
		index++;
	}
	va_end(args);
	return (length);
}
