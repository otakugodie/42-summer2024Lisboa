/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 19:27:06 by diegfern          #+#    #+#             */
/*   Updated: 2025/05/21 22:59:54 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int main (int arg, char *argv[]){
	if (arg >= 3){
		printf("PID process is: %s\n", argv[1]);
		printf("Message is: %s\n", argv[2]);
		while (1){
			kill (14867, SIGUSR1);
			sleep(2);
			kill (14867, SIGUSR2);
			sleep(2);
		}
	}
	

	return (0);
}