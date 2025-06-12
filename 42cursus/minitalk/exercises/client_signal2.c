/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_signal2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:21:12 by diegfern          #+#    #+#             */
/*   Updated: 2025/06/12 17:08:40 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

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

void send_char_to_server (int pid, char c){
	
	/*Cifrar el mensaje por bits y enviarlo mediante SIGNALS SIGUSR1: 1 y SIGUSR2: 0*/

	printf ("Entro a SCS\n");	// Test
	printf("[PID_SERVER] is: %d\n", pid);	//Test
	printf("[Message] is: %c\n", c);	//Test
	usleep(100);
}

int main (int argc, char **argv){

	int pid_server;
	char *message;
	int i;

	if (argc != 3){
		write(1, "Must insert: ./client [PID_SERVER] 'Message' \n", 47);
		return (1);
	}

	pid_server = ft_atoi(argv[1]);
	
	printf("Client PID is: %d\n", getpid());	//Test
	printf("Arg[1] -> [PID_SERVER] is: %d\n", pid_server);	//Test	

	message = argv[2];
	i = 0;

	printf("Arg[2] -> [Message] is: %s\n", message);	//Test
	
	/*Manejo de señales cuando el servidor confirma la recepción del mensaje*/

	while (message[i]){
		send_char_to_server (pid_server, message[i]);
		i++;
	}
	send_char_to_server(pid_server, '\0');	//Envia caracter indicando que termino mensaje
	usleep(200);
	return (0);

}