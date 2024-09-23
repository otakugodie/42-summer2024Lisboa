/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:46:42 by diegfern          #+#    #+#             */
/*   Updated: 2024/09/23 19:11:18 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b != 0)
	{
		*div = (a / b);
		*mod = (a % b);
	}
}

/*
#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;
	int	*div;
	int	*mod;
	int	res_div;
	int	res_mod;

	a = 15;
	b = 4;
	div = &res_div;
	mod = &res_mod;
	ft_div_mod(a, b, div, mod);
	printf(" %d / %d = %d, and remainder: %d\n", a, b, res_div, res_mod);
	return (0);
}
*/