/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 06:44:56 by diegfern          #+#    #+#             */
/*   Updated: 2024/10/23 06:50:30 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/* #include <stdio.h>

int	main(void)
{
	int	val1;
	int	val2;

	val1 = 2;
	val2 = 4;
	printf("val1: %d and val2: %d\n", val1, val2);
	ft_swap(&val1, &val2);
	printf("val1: %d and val2: %d\n", val1, val2);
	return (0);
}
 */