/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:27:29 by diegfern          #+#    #+#             */
/*   Updated: 2025/08/23 19:55:49 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* void	signal_handler(int sig, siginfo_t *info, void *ucontext)
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
		if (c == '\0')
		{
			write(1, "\n", 1);
			kill((*info).si_pid, SIGUSR2);
			bit_count = 0;
			c = 0;
			return ;
		}
		write(1, &c, 1);
		bit_count = 0;
		c = 0;
	}
	kill((*info).si_pid, SIGUSR1);
} */
/************************************************************************************/
/************************************************************************************/
/************************************************************************************/
void	signal_handler(int sig, siginfo_t *info, void *ucontext)
{
	static int total_bits = 0;   // ← Estática en lugar de global
	static int bit_count = 0;    // bits del elemento actual
	static int len = 0;          // tamaño del mensaje
	static char c = 0;           // carácter en construcción
	static char *buffer = NULL;  // buffer del mensaje
	static int buffer_index = 0; // índice en el buffer
	(void)ucontext;
	if (total_bits < 32) // 🔵 FASE 1: Recibir tamaño
	{
		// Reconstruir longitud
		if (sig == SIGUSR2)
		{
			len = (len << 1) | 1;
		}
			
		else 
		{
			len = (len << 1) | 0;
		}
		if (++total_bits == 32) // Al completar 32 bits
		{
			buffer = malloc(len + 1); // Asignar memoria
			buffer[len] = '\0';
		}
		kill(info->si_pid, SIGUSR1); // ✅ SÍ enviar ACK para tamaño
		return ;
	}
	else // 🟢 FASE 2: Recibir mensaje
	{
		// Reconstruir carácter
		if (sig == SIGUSR2)
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
				free(buffer);
				// Resetear todo
				total_bits = bit_count = len = buffer_index = 0;
				c = 0;
				buffer = NULL;
				kill(info->si_pid, SIGUSR2); // Confirmación final
				return ;
			}
			bit_count = 0;
			c = 0;
		}
	}
	kill(info->si_pid, SIGUSR1); // ACK normal
}

/************************************************************************************/
/************************************************************************************/
/************************************************************************************/

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
