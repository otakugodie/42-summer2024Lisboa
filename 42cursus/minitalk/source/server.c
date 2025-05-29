/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:27:29 by diegfern          #+#    #+#             */
/*   Updated: 2025/05/29 16:45:51 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void ft_signalHandler (int sig){
	if (sig == SIGUSR1){
		printf("Signal is: %d \n", sig);
	}
	else if(sig == SIGUSR2){
		printf("Signal is: %d \n", sig);	
	}
	else {
		printf("Signal ignored \n");
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