/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carl <sde-carl@student.42roma.it >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:56:04 by sde-carl          #+#    #+#             */
/*   Updated: 2023/04/26 18:56:04 by sde-carl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	int	index;

	index = 0;
	if (nbr == -2147483648)
		return (ft_putstr("-2147483648"));
	if (nbr < 0)
	{
		index += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr > 9)
		index += ft_putnbr(nbr / 10);
	index += ft_putchar(nbr % 10 + '0');
	return (index);
}
