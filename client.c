/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carl <sde-carl@student.42roma.it >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 23:43:34 by sde-carl          #+#    #+#             */
/*   Updated: 2023/05/28 23:43:34 by sde-carl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_char(int pid, char *str)
{
	int	i;
	int	c;

	i = 0;
	while (*str)
	{
		c = *(str);
		while (i < 8)
		{
			if (c << i & 0b10000000)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i++;
			usleep(100);
		}
		str++;
		i = 0;
	}
}

int	main(int ac, char **av)
{
	unsigned char	*str;
	int				pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		str = (unsigned char *)av[2];
		while (*str)
		{
			ft_send_char(pid, *str++);
		}
	}
	else
		ft_printf("WARNING: wrong number of arguments\n", RED, END);
	return (0);
}
