/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carl <sde-carl@student.42roma.it >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:59:16 by sde-carl          #+#    #+#             */
/*   Updated: 2023/04/26 18:59:16 by sde-carl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(unsigned long nbr)
{
	int	index;

	index = 0;
	index += ft_putstr("0x");
	if (nbr == 0)
		index += ft_putchar('0');
	else
		index += ft_puthexa(nbr, "0123456789abcdef");
	return (index);
}
