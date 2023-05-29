/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carl <sde-carl@student.42roma.it >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 00:27:59 by sde-carl          #+#    #+#             */
/*   Updated: 2023/05/29 00:27:59 by sde-carl         ###   ########.fr       */
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

void	ft_server_msg2(int sig, siginfo_t *info, void *content)
{
	static unsigned char	c;
	static int				i;

	c = 0;
	i = 0;
	(void)content;
	if (sig == SIGUSR2)
		c = c << 1;
	else if (sig == SIGUSR1)
		c = (c << 1) | 0b00000001;
	i++;
	if (i == 8)
	{
		ft_printf("%c", c, GREEN, END);
		i = 0;
		c = 0;
		if (kill(info->si_pid, SIGUSR1) == -1)
			ft_printf("WARNING: failed to send signal1\n", RED, END);
		return ;
	}
	if (kill(info->si_pid, SIGUSR2) == -1)
		ft_printf("WARNING: failed to send signal2\n", RED, END);
}

int	main(void)
{
	struct sigaction	sa;

	ft_display_banner();
	ft_printf("PID: %d\n", getpid(), GREEN, END);
	while (1)
	{
		if (ft_q_key())
		{
			ft_printf("Exiting Program...\n", YELLOW, END);
			break ;
		}
		sa.sa_flags = SA_SIGINFO;
		sa.sa_sigaction = ft_server_msg2;
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
			ft_printf("WARNING: failed to send signal1\n", RED, END);
		if (sigaction(SIGUSR2, &sa, NULL) == -1)
			ft_printf("WARNING: failed to send signal2\n", RED, END);
	}
	return (0);
}
