/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signalHandler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:00:21 by diegfern          #+#    #+#             */
/*   Updated: 2025/05/30 21:29:08 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

// unistd.h para usar sleep

// sighandler_t  signal(int  signum, sighandler_t handler);

void ft_signalHandler(int sig){
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

	//signal (SIGALRM, SIG_IGN);	//Modifico el Signal disposition por defecto, para este caso es Term (Terminar) sino hay un signal handler. (Hay Term, Core, Ign, Stop, Cont)
	printf("PID server is: %d \n", getpid());
	
	while (1){
		//printf("...Awaiting signals...\n");
		//printf("PID server is: %d \n", getpid());
		//sleep(2);
		pause();
	}
	return 0;
}