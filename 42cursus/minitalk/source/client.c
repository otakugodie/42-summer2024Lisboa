/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:27:06 by diegfern          #+#    #+#             */
/*   Updated: 2025/08/24 23:38:04 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack_received;

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
			usleep(250);
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
		usleep(250);
		if (--timeout == 0)
		{
			write(2, "Error: Final acknowledgment timeout\n", 36);
			exit(1);
		}
	}
}

static void	ft_send_size(int pid_server, char *message)
{
	int	size;
	int	i;
	int	timeout;

	size = 0;
	while (message[size])
		size++;
	i = 31;
	while (i >= 0)
	{
		g_ack_received = 0;
		timeout = 50000;
		if (size >> i & 1)
			kill(pid_server, SIGUSR2);
		else
			kill(pid_server, SIGUSR1);
		while (!g_ack_received && --timeout > 0)
			usleep(250);
		if (timeout == 0)
		{
			write(2, "Error: Server timeout\n", 22);
			exit(1);
		}
		i--;
	}
}

int	main(int argc, char **argv)
{
	int		pid_server;
	char	*message;
	int		i;

	if (argc != 3 || ft_atoi(argv[1]) < 1)
	{
		write(1, "Problem with arguments and [PID] must > 0 \n", 44);
		return (1);
	}
	pid_server = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
	g_ack_received = 0;
	signal(SIGUSR1, handshake_handler);
	signal(SIGUSR2, handshake_handler);
	ft_send_size(pid_server, message);
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
