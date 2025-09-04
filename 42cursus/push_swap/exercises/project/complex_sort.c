/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 08:35:37 by diegfern          #+#    #+#             */
/*   Updated: 2025/09/04 08:35:39 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Algoritmo principal para ordenar stacks grandes (más de 5 elementos)
** Usa el método del "costo más barato" para optimizar el número de operaciones
*/
void	complex_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pushed;
	int	i;

	size = get_stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (size > 6 && i < size && pushed < size / 2)
	{
		if ((*stack_a)->index <= size / 2)
		{
			pb(stack_a, stack_b, 1);
			pushed++;
		}
		else
			ra(stack_a, 1);
		i++;
	}
	while (size - pushed > 3)
	{
		pb(stack_a, stack_b, 1);
		pushed++;
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		assign_target_positions(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
	{
		size = get_lowest_index_position(stack_a);
		if (size < get_stack_size(*stack_a) / 2)
		{
			while (size--)
				ra(stack_a, 1);
		}
		else
		{
			size = get_stack_size(*stack_a) - size;
			while (size--)
				rra(stack_a, 1);
		}
	}
}
