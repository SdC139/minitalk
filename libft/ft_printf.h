/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carl <sde-carl@student.42roma.it >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:39:47 by sde-carl          #+#    #+#             */
/*   Updated: 2023/04/18 18:39:47 by sde-carl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

int	ft_all_cases(va_list args, const char c);
int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_puthexa(unsigned long nbr, char *hexa);
int	ft_putnbr(int nbr);
int	ft_putptr(unsigned long nbr);
int	ft_putstr(char *str);
int	ft_putunsigned(unsigned int nbr);

#endif