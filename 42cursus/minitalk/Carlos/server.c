/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 00:31:20 by diegfern          #+#    #+#             */
/*   Updated: 2025/06/11 00:34:42 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	putnbr(long nb)
{
	char	digit;

	if (nb >= 10)
		putnbr(nb / 10);
	digit = nb % 10 + '0';
	write(1, &digit, 1);
}

void	handler(int signo, siginfo_t *info, void *null)
{
	static char	c;
	static int	bit;

	(void)null;
	if (signo == SIGUSR1)
		c |= (0x80 >> bit);
	else if (signo == SIGUSR2)
		c &= ~(0x80 >> bit);
	++bit;
	if (bit == 8)
	{
		if (c == 0)
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR2);
		}
		else
			write(1, &c, 1);
		bit = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	write(1, "listening on PID: ", 18);
	putnbr(getpid());
	write(1, "\n", 1);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		sleep(1);
	return (0);
}
