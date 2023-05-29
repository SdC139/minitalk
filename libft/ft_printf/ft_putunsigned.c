/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carl <sde-carl@student.42roma.it >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:01:41 by sde-carl          #+#    #+#             */
/*   Updated: 2023/04/26 19:01:41 by sde-carl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int nbr)
{
	int	index;

	index = 0;
	if (nbr > 9)
		index += ft_putunsigned(nbr / 10);
	index += ft_putchar(nbr % 10 + '0');
	return (index);
}
