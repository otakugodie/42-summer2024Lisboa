/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverTest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:06:22 by diegfern          #+#    #+#             */
/*   Updated: 2025/06/14 10:38:23 by diegfern         ###   ########.fr       */
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

void	signal_handler(int sig, siginfo_t *info, void *ucontext)
{
	static char	c;
	static int	bit_count;

	(void)ucontext; // Silencia la advertencia del parámetro no usado
	if (sig == SIGUSR1)
	{
		c = (c << 1) | 0; // Agrego un bit 0
	}
	else if (sig == SIGUSR2)
	{
		c = (c << 1) | 1; // Agrego un bit 1
	}
	bit_count++;
	if (bit_count == 8)
	{
		if (c == '\0')
		{
			write(1, "\n", 1);
			//write(1, "\nEnd message!\n", 15);
			kill((*info).si_pid, SIGUSR2);
				// Confirmo al cliente la recepcion del mensaje
											// c = 0;
			// bit_count = 0;
			// return ;
		}
		else
			write(1, &c, 1); // Escribo el carácter reconstruido
		bit_count = 0;
		c = 0;
	}
	kill((*info).si_pid, SIGUSR1);
		// Handshake: Confirmo al cliente mediante su PID la recepcion de cada senal
									// write(1, "Message received from: ", 23);
	// ft_putnbr_fd(info->si_pid,1);
	// ft_putnbr_fd((*info).si_pid, 1);
	// write(1, "\n", 1);
	// pause();
}

int	main(void)
{
	struct sigaction	sa;

	write(1, "Server PID is: ", 15);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 2);
	/*Inicializo estructura de sigaction con el objeto sa (signal action)*/
	sa.sa_flags = SA_SIGINFO; //
	sigemptyset(&sa.sa_mask);        // Mascara de señales empieza vacía
	sigaddset(&sa.sa_mask, SIGUSR1);
		// Bloquea las senal SIGUSR1 mientras esté dentro del handler
	sigaddset(&sa.sa_mask, SIGUSR2);
		// Bloquea las senal SIGUSR2 mientras esté dentro del handler
	sa.sa_sigaction = signal_handler; // Asigno el handler que usara
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
