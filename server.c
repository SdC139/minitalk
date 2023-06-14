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
	██   ██ %s\n", ORANGE, END);
	ft_printf("\t%s████  ████ ██ ████   ██ ██        ██    ██   ██ ██     \
	██  ██  %s\n", ORANGE, END);
	ft_printf("\t%s██ ████ ██ ██ ██ ██  ██ ██        ██    ███████ ██     \
	█████   %s\n", ORANGE, END);
	ft_printf("\t%s██  ██  ██ ██ ██  ██ ██ ██        ██    ██   ██ ██     \
	██  ██  %s\n", ORANGE, END);
	ft_printf("\t%s██      ██ ██ ██   ████ ██        ██    ██   ██ ███████\
	██   ██ %s\n", ORANGE, END);
}

void	ft_handler(int signal, siginfo_t *info, void *unused)
{
	static int	bit;
	static int	i;

	(void)unused;
	if (signal == SIGUSR1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		if (!i)
			kill(info->si_pid, SIGUSR1);
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	if (pid == -1)
	{
		ft_printf("%sERROR: Too many arguments%s\n", RED, END);
		return (EXIT_FAILURE);
	}
	ft_display_banner();
	ft_printf("\n\tPid  %u\n", pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &ft_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
