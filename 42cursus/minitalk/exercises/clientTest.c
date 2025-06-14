/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clientTest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:21:12 by diegfern          #+#    #+#             */
/*   Updated: 2025/06/14 10:34:44 by diegfern         ###   ########.fr       */
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

void	send_char_to_server(int pid, unsigned char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		g_ack_received = 0;
			// Cambio la variable a 0 para que al enviar la senal al servidor se quede a la espera hasta recibir la confirmacion mediante una senal de regreso
		if ((c >> bit) & 1)
		{
			kill(pid, SIGUSR2); // Ddesplaza los bits del caracter i veces a la derecha y luego enmascara con 1, para validar si es un 1 o 0
		}
		else
		{
			kill(pid, SIGUSR1);
		}
		while (!g_ack_received)
			//usleep(50); // *********************Ayuda en pruebas largas
			pause(); // Espera senal de confirmacion
		// usleep(100);
		bit--;
	}
}

void	handshake_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		g_ack_received = 1;
		// write (1, "Signal received from server!\n", 30);
	}
	else if (sig == SIGUSR2)
	{
		write(1, "Message received from server!\n", 31);
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
	/*Manejo de señales cuando el servidor confirma la recepción de la senal o el mensaje completo*/
	signal(SIGUSR1, handshake_handler);
	signal(SIGUSR2, handshake_handler);
	while (message[i])
	{
		send_char_to_server(pid_server, message[i]);
		i++;
	}
	send_char_to_server(pid_server, '\0');
		// Envia caracter indicando que termino mensaje
	// usleep(200);
	return (0);
}
