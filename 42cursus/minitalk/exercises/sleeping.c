/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:00:21 by diegfern          #+#    #+#             */
/*   Updated: 2025/05/20 17:53:07 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

// unistd.h para usar sleep

int	main(void)
{
	while (1)
	{
		printf("zzzzzzz\n");
		sleep(2);
	}
	return (0);
}
