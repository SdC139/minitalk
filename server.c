/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carl <sde-carl@student.42roma.it >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 00:20:40 by sde-carl          #+#    #+#             */
/*   Updated: 2023/05/29 00:20:40 by sde-carl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_display_banner(void)
{
	ft_printf("\n\t%s███   ███  ██ ███    ██ ██      ████████  █████ ██  \
	██   ██ %s\n", YELLOW, END);
	ft_printf("\t%s████  ████ ██ ████   ██ ██        ██    ██   ██ ██     \
	██  ██  %s\n", YELLOW, END);
	ft_printf("\t%s██ ████ ██ ██ ██ ██  ██ ██        ██    ███████ ██     \
	█████   %s\n", YELLOW, END);
	ft_printf("\t%s██  ██  ██ ██ ██  ██ ██ ██        ██    ██   ██ ██     \
	██  ██  %s\n", YELLOW, END);
	ft_printf("\t%s██      ██ ██ ██   ████ ██        ██    ██   ██ ███████\
	██   ██ %s\n", YELLOW, END);
}

int	ft_q_key(void)
{
	int	c;

	c = getchar();
	if (c == 'q' || c == 'Q')
	{
		return (1);
	}
	return (0);
}

void	ft_server_msg(int sig)
{
	static unsigned char	c;
	static int				i;

	c = 0;
	i = 0;
	if (sig == SIGUSR2)
		c = c << 1;
	else if (sig == SIGUSR1)
		c = c << 1 | 0b00000001;
	i++;
	if (i == 8)
	{
		ft_printf("%c", c, GREEN, END);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_display_banner();
	ft_printf("PID: %d\n", getpid(), GREEN, END);
	while (1)
	{
		if (ft_q_key())
		{
			ft_printf("%sExiting Program...%s\n", YELLOW, END);
			break ;
		}
		signal(SIGUSR1, ft_server_msg);
		signal(SIGUSR2, ft_server_msg);
		pause();
	}
	return (0);
}
