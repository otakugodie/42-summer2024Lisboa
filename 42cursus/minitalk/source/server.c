/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:27:29 by diegfern          #+#    #+#             */
/*   Updated: 2025/06/09 14:48:58 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static int	g_bit_count = 0;
static char	g_char = 0;

void	ft_signal_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		g_char = (g_char << 1) | 0;
		g_bit_count++;
	}
	else if (sig == SIGUSR2)
	{
		g_char = (g_char << 1) | 1;
		g_bit_count++;
	}
	else
	{
		ft_printf("Signal ignored \n");
		return ;
	}
	if (g_bit_count == 8)
	{
		if (g_char == '\0')
		{
			write(1, "\nMessage received successfully!\n", 32);
			g_bit_count = 0;
			g_char = 0;
			return ;
		}
		write(1, &g_char, 1);
		g_bit_count = 0;
		g_char = 0;
	}
	return ;
}

int	main(void)
{
	int	i;

	ft_printf("PID server is: %d \n", getpid());
	while (1)
	{
		signal(SIGUSR1, &ft_signal_handler);
		signal(SIGUSR2, &ft_signal_handler);
		i = 1;
		while (i <= 31)
		{
			if (i != SIGUSR1 && i != SIGUSR2 && i != SIGKILL && i != SIGSTOP
				&& i != SIGINT)
			{
				signal(i, &ft_signal_handler);
			}
			i++;
		}
	}
	return (0);
}
