/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:07:46 by diegfern          #+#    #+#             */
/*   Updated: 2024/10/23 21:23:47 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	fact;

	fact = 1;
	if (nb < 0)
	{
		return (0);
	}
	else
	{
		while (nb > 0)
		{
			fact *= nb;
			nb--;
		}
	}
	return (fact);
}

/* #include <stdio.h>

int	main(void)
{
	int	i;

	i = 10;
	printf("Factorial of %d is %d\n", i, ft_iterative_factorial(i));
	return (0);
}
 */