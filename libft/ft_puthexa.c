/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carl <sde-carl@student.42roma.it >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:50:42 by sde-carl          #+#    #+#             */
/*   Updated: 2023/04/26 18:50:42 by sde-carl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long nbr, char *hexa)
{
	int	i;

	i = 0;
	if (nbr >= 16)
		i += ft_puthexa(nbr / 16, hexa);
	i += ft_putchar(hexa[nbr % 16]);
	return (i);
}
