/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:16:29 by diegfern          #+#    #+#             */
/*   Updated: 2024/09/23 19:32:35 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	swap_val;

	swap_val = *a;
	*a = *b;
	*b = swap_val;
}

/*
int	main(void)
{
	int	value_a;
	int	value_b;

	value_a = 24;
	value_b = 42;
	printf("value_a = %d and value_b = %d\n", value_a, value_b);
	ft_swap(&value_a, &value_b);
	printf("After pointers: value_a = %d and value_b = %d\n", value_a, value_b);
	return (0);
}
*/