/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:27:29 by diegfern          #+#    #+#             */
/*   Updated: 2025/08/24 23:36:56 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handle_size_reception(t_data *cli_data, int sig, siginfo_t *info)
{
	if (sig == SIGUSR2)
		cli_data->len = (cli_data->len << 1) | 1;
	else
		cli_data->len = (cli_data->len << 1) | 0;
	if (++(cli_data->total_bits) == 32)
	{
		cli_data->buffer = malloc(cli_data->len + 1);
		cli_data->buffer[cli_data->len] = '\0';
	}
	kill(info->si_pid, SIGUSR1);
}

static void	reset_vars(t_data *data, int *bit_count, int *buffer_index, char *c)
{
	free(data->buffer);
	data->total_bits = 0;
	data->len = 0;
	data->buffer = NULL;
	*bit_count = 0;
	*buffer_index = 0;
	*c = 0;
}

static void	handle_message_reception(t_data *data, int sig, siginfo_t *info)
{
	static int	bit_count;
	static char	c;
	static int	buffer_index;

	if (sig == SIGUSR2)
		c = (c << 1) | 1;
	else
		c = (c << 1) | 0;
	if (++bit_count == 8)
	{
		data->buffer[buffer_index++] = c;
		if (c == '\0')
		{
			write(1, data->buffer, buffer_index - 1);
			write(1, "\n", 1);
			reset_vars(data, &bit_count, &buffer_index, &c);
			kill(info->si_pid, SIGUSR2);
			return ;
		}
		bit_count = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

void	signal_handler(int sig, siginfo_t *info, void *ucontext)
{
	static t_data	data;

	(void)ucontext;
	if (data.total_bits < 32)
	{
		handle_size_reception(&data, sig, info);
		return ;
	}
	else
		handle_message_reception(&data, sig, info);
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
	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
	{
		write(1, "Closing connection server\n", 26);
		exit(0);
	}
	while (1)
	{
		pause();
	}
	return (0);
}
