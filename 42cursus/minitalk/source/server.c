/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:27:29 by diegfern          #+#    #+#             */
/*   Updated: 2025/08/16 17:06:40 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd((n / 10), fd);
	}
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

void	handle_end_message(char *buffer, int *msg_index, pid_t client_pid)
{
	buffer[*msg_index] = '\0';
	write(1, buffer, *msg_index);
	write(1, "\n", 1);
	*msg_index = 0;
	kill(client_pid, SIGUSR2);
}

void	hand_comp_char(char c, char *buffer, int *msg_index, pid_t client_pid)
{
	if (c == '\0')
	{
		handle_end_message(buffer, msg_index, client_pid);
		return ;
	}
	if (*msg_index < 1023)
	{
		buffer[*msg_index] = c;
		(*msg_index)++;
	}
}

void	signal_handler(int sig, siginfo_t *info, void *ucontext)
{
	static char	c;
	static int	bit_count;
	static char	buffer[1024];
	static int	msg_index;

	(void)ucontext;
	if (sig == SIGUSR1)
		c = (c << 1) | 0;
	else if (sig == SIGUSR2)
		c = (c << 1) | 1;
	bit_count++;
	if (bit_count == 8)
	{
		hand_comp_char(c, buffer, &msg_index, (*info).si_pid);
		bit_count = 0;
		c = 0;
		if (msg_index == 0)
			return ;
	}
	kill((*info).si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	write(1, "Server PID is: ", 15);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 2);
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
