/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carl <sde-carl@student.42roma.it >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 00:02:23 by sde-carl          #+#    #+#             */
/*   Updated: 2023/05/29 00:02:23 by sde-carl         ###   ########.fr       */
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
			if (c << i & 128)
			{
				if (kill(pid, SIGUSR1) == -1)
					ft_printf("WARNING: failed to send signal1\n", RED, END);
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					ft_printf("WARNING: failed to send signal2\n", RED, END);
			}
			i++;
			usleep(100);
		}
		str++;
		i = 0;
	}
}

void	ft_client_msg(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Message received by server\n", GREEN, END);
	else
		ft_printf("WARNING: message not received by server\n", RED, END);
}

int	main(int ac, char **av)
{
	int				pid;
	unsigned char	*str;

	if (ac == 3)
	{
		signal(SIGUSR1, ft_client_msg);
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
