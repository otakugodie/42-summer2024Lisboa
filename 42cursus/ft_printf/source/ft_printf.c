/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:23:17 by diegfern          #+#    #+#             */
/*   Updated: 2024/11/29 12:44:54 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...){
	int	ac;
	int	sig;
	
	va_list ap;		//ap> argument pointer
	va_start(ap, str);

	printf("Iniciamos argumentos\n");
	printf ("Lenght is: %ld\n", ft_strlen(str));

	//va_arg(ap, int);


	return (0);
}

int sumatoria (int n, ...){
	int	i;
	int	ac;
	int	sig;

	ac = 0;
	
	va_list ap;		//ap> argument pointer
	va_start(ap, n);

	i = 0;
	printf("Iniciamos argumentos\n");
	
	while (i < n){		
		sig = va_arg(ap, int);
		printf("El siguiente argumento es: %d\n", sig);
		ac += sig;
		i++;
	}

	va_end(ap);
	return (ac);
}

int	main(void)
{
	int	total;

	//total = sumatoria(3, 1,2,3);
	//printf ("Total: %d\n", total);
	ft_printf ("Hello my name is %s, I am student in %d\n", "Diego", 42);

	return (0);
}
