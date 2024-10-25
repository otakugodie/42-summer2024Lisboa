/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:15:01 by diegfern          #+#    #+#             */
/*   Updated: 2024/09/23 20:39:36 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a;
	mod = *b;
	*a = div / mod;
	*b = div % mod;
}

/*
#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;

	a = 42;
	b = 10;
	printf("a= %d, b= %d \n", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("a= %d, b= %d \n", a, b);
	return (0);
}
*/