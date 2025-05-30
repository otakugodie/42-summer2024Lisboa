/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:27:06 by diegfern          #+#    #+#             */
/*   Updated: 2025/05/30 21:51:38 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void send_char_to_server(int pid_server, char c) {
    int bit;

    for (bit = 7; bit >= 0; bit--) {
        if ((c >> bit) & 1) {
            kill(pid_server, SIGUSR2); // Enviar bit 1 como SIGUSR2
        } else {
            kill(pid_server, SIGUSR1); // Enviar bit 0 como SIGUSR1
        }
        usleep(100); // Pausa breve para que el servidor procese la señal
    }
}

int main (int argc, char *argv[]){

	int pid_server;
	char *message;
    int i;

	//pid_server = 31866;

	if (argc != 3) {
        write(2, "Usage: ./client <PID_SERVER> <MESSAGE>\n", 39);
        return (1);
    }

	pid_server = atoi(argv[1]);
	message = argv[2];

	i = 0;
    while (message[i]) {
        send_char_to_server(pid_server, message[i]); // Enviar cada carácter
        i++;
    }

	/* if (argc >= 3){
		printf("PID process is: %s\n", argv[1]);
		printf("Message is: %s\n", argv[2]);
		while (1){
			kill (pid_server, SIGUSR1);
			sleep(2);
			kill (pid_server, SIGUSR2);
			sleep(2);
		}
	} */

	return (0);
}