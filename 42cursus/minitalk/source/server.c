/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:27:29 by diegfern          #+#    #+#             */
/*   Updated: 2025/05/31 23:23:13 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static int g_bit_count = 0; // Contador de bits recibidos
static char g_char = 0;    // Carácter reconstruido

void ft_signalHandler (int sig){
	if (sig == SIGUSR1){
		//printf("Signal is: %d \n", sig);
		g_char = (g_char << 1) | 0; // Desplaza y añade un 0
	}
	else if(sig == SIGUSR2){
		//printf("Signal is: %d \n", sig);
		g_char = (g_char << 1) | 1; // Desplaza y añade un 1
	}
	else {
		printf("Signal ignored \n");
	}
	g_bit_count++;
	if (g_bit_count == 8) { // Cuando se reciben 8 bits
        write(1, &g_char, 1); // Imprime el carácter reconstruido
        g_bit_count = 0;      // Reinicia el contador
        g_char = 0;           // Reinicia el carácter
		write(1, "\n", 1);
    }
}

int main (void){

	printf("PID server is: %d \n", getpid());

	while (1){
		int i;
	
		signal(SIGUSR1, &ft_signalHandler);
		signal(SIGUSR2, &ft_signalHandler);

		i = 1;

		while (i <= 31){
			if (i != SIGUSR1 && i != SIGUSR2 && i!= SIGKILL && i != SIGSTOP && i != SIGINT ){
				//SIGINT la uso para terminar el proceso con Ctrl+C
				signal(i, &ft_signalHandler);
			}
			i++;
		}
	}

	return (0);
}