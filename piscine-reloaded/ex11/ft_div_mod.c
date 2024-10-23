/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 06:51:40 by diegfern          #+#    #+#             */
/*   Updated: 2024/10/23 07:00:22 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/* #include <stdio.h>

int	main(void)
{
	int	a;
	int	b;
	int	div;
	int	mod;

	a = 11;
	b = 2;
	div = 0;
	mod = 0;
	printf("%d / %d = %d & reminder is: %d\n", a, b, div, mod);
	ft_div_mod(a, b, &div, &mod);
	printf("%d / %d = %d & reminder is: %d\n", a, b, div, mod);
	return (0);
}
 */