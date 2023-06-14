/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carl <sde-carl@student.42roma.it >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:35:32 by sde-carl          #+#    #+#             */
/*   Updated: 2023/04/01 18:54:39 by sde-carl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int i)
{	
	if (i >= '0' && i <= '9')
		return (1);
	return (0);
}
