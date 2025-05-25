/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:27:06 by diegfern          #+#    #+#             */
/*   Updated: 2025/05/25 21:49:13 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int main (int arg, char *argv[]){

	int pid_server;

	pid_server = 23823;

	if (arg >= 3){
		printf("PID process is: %s\n", argv[1]);
		printf("Message is: %s\n", argv[2]);
		while (1){
			kill (pid_server, SIGUSR1);
			sleep(2);
			kill (pid_server, SIGUSR2);
			sleep(2);
		}
	}
	

	return (0);
}