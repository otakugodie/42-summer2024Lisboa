/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:27:29 by diegfern          #+#    #+#             */
/*   Updated: 2025/08/21 23:29:55 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

char	*resize_message(char *message, int msg_len, int new_capacity)
{
	char	*new_message;
	int		i;

	new_message = malloc(new_capacity);
	if (!new_message)
		return (NULL);
	i = 0;
	while (i < msg_len)
	{
		new_message[i] = message[i];
		i++;
	}
	free(message);
	return (new_message);
}

void	process_complete_char(char c, siginfo_t *info)
{
	static char	*message;
	static int	msg_len;
	static int	msg_capacity;

	if (c == '\0')
	{
		if (message)
		{
			write(1, message, msg_len);
			write(1, "\n", 1);
			free(message);
			message = NULL;
			msg_len = 0;
			msg_capacity = 0;
		}
		kill((*info).si_pid, SIGUSR2);
		return ;
	}
	if (!message)
	{
		msg_capacity = 1024;
		msg_len = 0;
		message = malloc(msg_capacity);
	}
	else if (msg_len >= msg_capacity - 1)
		message = resize_message(message, msg_len, msg_capacity *= 2);
	if (message)
		message[msg_len++] = c;
}

void	signal_handler(int sig, siginfo_t *info, void *ucontext)
{
	static char	c;
	static int	bit_count;

	(void)ucontext;
	if (sig == SIGUSR1)
		c = (c << 1) | 0;
	else if (sig == SIGUSR2)
		c = (c << 1) | 1;
	bit_count++;
	if (bit_count == 8)
	{
		process_complete_char(c, info);
		bit_count = 0;
		c = 0;
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
