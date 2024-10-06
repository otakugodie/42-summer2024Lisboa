/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 09:44:25 by diegfern          #+#    #+#             */
/*   Updated: 2024/10/06 09:44:25 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int fact;

	fact = 1;
	while (nb > 0)
	{
		fact *= nb;
		nb--;
	}
	if (nb < 0)
	{
		return (0);
	}
	return (fact);
}

int	main(void)
{
	printf("%d\n", ft_iterative_factorial(10));
}
