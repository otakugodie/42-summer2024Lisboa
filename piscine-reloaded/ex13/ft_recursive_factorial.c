/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:26:19 by diegfern          #+#    #+#             */
/*   Updated: 2024/10/23 22:12:14 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	if (nb >= 2)
		return (nb * ft_recursive_factorial(nb - 1));
	return (1);
}

/* #include <stdio.h>

int	main(void)
{
	int	i;

	i = 4;
	printf("Factorial of %d is %d\n", i, ft_recursive_factorial(i));
	return (0);
}
 */