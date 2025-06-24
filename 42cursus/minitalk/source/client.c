/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:27:06 by diegfern          #+#    #+#             */
/*   Updated: 2025/06/24 18:48:49 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

volatile sig_atomic_t	g_ack_received;

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	sign;

	sign = 1;
	result = 0;
	i = 0;
	while ((nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r')) && nptr[i])
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= (-1);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i])
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

void	send_char_to_server(int pid, char c)
{
	int	bit;
	int	timeout;

	bit = 7;
	while (bit >= 0)
	{
		g_ack_received = 0;
		timeout = 50000;
		if ((c >> bit) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (!g_ack_received)
		{
			usleep(100);
			if (--timeout == 0)
			{
				write(2, "Error: Server timeout\n", 22);
				exit(1);
			}
		}
		bit--;
	}
}

void	handshake_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		g_ack_received = 1;
	}
	else if (sig == SIGUSR2)
	{
		write(1, "Message received from server!\n", 30);
		g_ack_received = 2;
	}
}

void	wait_final_ack(void)
{
	int	timeout;

	timeout = 50000;
	while (g_ack_received != 2)
	{
		usleep(100);
		if (--timeout == 0)
		{
			write(2, "Error: Final acknowledgment timeout\n", 36);
			exit(1);
		}
	}
}

int	main(int argc, char **argv)
{
	int		pid_server;
	char	*message;
	int		i;

	if (argc != 3)
	{
		write(1, "Must insert: ./client [PID_SERVER] 'Message' \n", 47);
		return (1);
	}
	pid_server = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
	g_ack_received = 0;
	signal(SIGUSR1, handshake_handler);
	signal(SIGUSR2, handshake_handler);
	while (message[i])
	{
		send_char_to_server(pid_server, message[i]);
		i++;
	}
	send_char_to_server(pid_server, '\0');
	wait_final_ack();
	write(1, "Client finished successfully!\n", 30);
	return (0);
}
