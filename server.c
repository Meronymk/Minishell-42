/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krochefo <krochefo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:36:11 by krochefo          #+#    #+#             */
/*   Updated: 2022/09/13 22:28:39 by krochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "includes/includes.h"

void	startup_message(void)
{
	ft_putstr_fd("┌────────────────────┐\n", 1);
	ft_putstr_fd("│   Minitalk Server  │\n", 1);
	ft_putstr_fd("└────────────────────┘\n", 1);
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
}

static void	sig_print(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				byte;

	(void)context;
	if (byte == 0)
		byte = 8;
	if (sig == SIGUSR2)
		sig = 0;
	else if (sig == SIGUSR1)
		sig = 1;
	byte--;
	c += (sig & 1) << byte;
	if (byte == 0)
	{
		if (!c)
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR1);
		}
		write (1, &c, 1);
		byte = 8;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sig;

	(void)argc;
	(void)argv;
	startup_message();
	sig.sa_sigaction = sig_print;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
