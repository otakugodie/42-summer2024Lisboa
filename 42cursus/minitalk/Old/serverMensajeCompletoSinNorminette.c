/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:27:29 by diegfern          #+#    #+#             */
/*   Updated: 2025/08/23 22:03:07 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int sig, siginfo_t *info, void *ucontext)
{
	static int total_bits = 0;   // ← Estática en lugar de global
	static int bit_count = 0;    // bits del elemento actual
	static int len = 0;          // tamaño del mensaje
	static char c = 0;           // carácter en construcción
	static char *buffer = NULL;  // buffer del mensaje
	static int buffer_index = 0; // índice en el buffer
	(void)ucontext;

	//*********************** Reserva de memoria

	if (total_bits < 32) // 🔵 FASE 1: Recibir tamaño
	{
		if (sig == SIGUSR2)	//Reconstruir longitud
			len = (len << 1) | 1;	
		else 
			len = (len << 1) | 0;
		if (++total_bits == 32) // Al completar 32 bits
		{
			buffer = malloc(len + 1); // Asignar memoria
			buffer[len] = '\0';
		}
		kill(info->si_pid, SIGUSR1); // ✅ SÍ enviar ACK para tamaño
		return ;
	}
	//*********************** Hasta aqui va la reserva de memoria
	
	else // 🟢 FASE 2: Recibir mensaje
	{
		if (sig == SIGUSR2)		// Reconstruir carácter
			c = (c << 1) | 1;
		else
			c = (c << 1) | 0;
		if (++bit_count == 8) // 8 bits completos
		{
			buffer[buffer_index++] = c;
			if (c == '\0') // 🔴 FINAL: mensaje completo
			{
				write(1, buffer, buffer_index - 1); // Imprimir sin '\0'
				write(1, "\n", 1);
				
				//*********************** Limpieza de variables
				free(buffer);
				total_bits = bit_count = len = buffer_index = 0;	// Resetear todo
				c = 0;
				buffer = NULL;
				//*********************** Hasta aqui va la limpieza de variables

				kill(info->si_pid, SIGUSR2); // Confirmación final
				return ;
			}
			bit_count = 0;
			c = 0;
		}
	}
	kill(info->si_pid, SIGUSR1); // ACK normal
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
