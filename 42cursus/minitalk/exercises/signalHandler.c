/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signalHandler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:00:21 by diegfern          #+#    #+#             */
/*   Updated: 2025/05/19 20:55:09 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

// unistd.h para usar sleep

// sighandler_t  signal(int  signum, sighandler_t handler);

void ft_signalHandler(int sig){
	printf("Signal is: %d \n", sig);
}

int main (void){

	//signal(SIGIO, &ft_signalHandler);
	signal (SIGALRM, SIG_IGN);	//Modifico el Signal disposition por defecto, para este caso es Term sino hay un signal handler
	while (1){
		printf("...Awaiting signals...\n");
		sleep(2);
	}
	return 0;
}