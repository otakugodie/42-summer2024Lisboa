/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:27:06 by diegfern          #+#    #+#             */
/*   Updated: 2025/06/09 14:49:00 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

void	send_char_to_server(int pid_server, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
		{
			kill(pid_server, SIGUSR2);
		}
		else
		{
			kill(pid_server, SIGUSR1);
		}
		usleep(100);
		bit--;
	}
}

int	main(int argc, char *argv[])
{
	int		pid_server;
	char	*message;
	int		i;

	if (argc != 3)
	{
		write(2, "Usage: ./client <PID_SERVER> <MESSAGE>\n", 39);
		return (1);
	}
	pid_server = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
	while (message[i])
	{
		send_char_to_server(pid_server, message[i]);
		i++;
	}
	send_char_to_server(pid_server, '\0');
	usleep(500);
	return (0);
}
