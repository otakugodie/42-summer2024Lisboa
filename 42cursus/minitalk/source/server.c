/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:27:29 by diegfern          #+#    #+#             */
/*   Updated: 2025/06/03 18:13:10 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static int	g_bit_count = 0; // Contador de bits recibidos
static char	g_char = 0;	// Carácter reconstruido

void	ft_signal_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		// printf("Signal is: %d \n", sig);
		g_char = (g_char << 1) | 0; // Desplaza y añade un 0
		g_bit_count++;
	}
	else if (sig == SIGUSR2)
	{
		// printf("Signal is: %d \n", sig);
		g_char = (g_char << 1) | 1; // Desplaza y añade un 1
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
			// Si el carácter es nulo, termina el mensaje
			write(1, "\nMessage received successfully!\n", 32);
			g_bit_count = 0;
			g_char = 0;
			return ;
		}
		// Cuando se reciben 8 bits
		write(1, &g_char, 1); // Imprime el carácter reconstruido
		g_bit_count = 0; // Reinicia el contador
		g_char = 0; // Reinicia el carácter
	}
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
				// SIGINT la uso para terminar el proceso con Ctrl+C
				signal(i, &ft_signal_handler);
			}
			i++;
		}
	}
	return (0);
}
