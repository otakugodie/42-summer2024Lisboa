/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 08:37:17 by diegfern          #+#    #+#             */
/*   Updated: 2025/09/04 08:37:18 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Ordena un stack de 3 elementos usando el algoritmo óptimo
** Maneja todos los casos posibles de 3 elementos
*/
void	sort_three(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	if (is_sorted(*stack_a))
		return ;
	first = (*stack_a)->index;
	second = (*stack_a)->next->index;
	third = (*stack_a)->next->next->index;
	if (first > second && second < third && first < third)
		sa(stack_a, 1);
	else if (first > second && second > third && first > third)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a, 1);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a, 1);
}

/*
** Ordena un stack de 4 elementos
** Mueve el elemento más pequeño a stack_b, ordena los 3 restantes y lo devuelve
*/
void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	if (is_sorted(*stack_a))
		return ;
	distance = get_lowest_index_position(stack_a);
	if (distance == 1)
		ra(stack_a, 1);
	else if (distance == 2)
	{
		ra(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (distance == 3)
		rra(stack_a, 1);
	if (is_sorted(*stack_a))
		return ;
	pb(stack_a, stack_b, 1);
	sort_three(stack_a);
	pa(stack_a, stack_b, 1);
}

/*
** Ordena un stack de 5 elementos
** Mueve los dos elementos más pequeños a stack_b, ordena los 3 restantes
*/
void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	if (is_sorted(*stack_a))
		return ;
	distance = get_lowest_index_position(stack_a);
	if (distance == 1)
		ra(stack_a, 1);
	else if (distance == 2)
	{
		ra(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (distance == 3)
	{
		rra(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (distance == 4)
		rra(stack_a, 1);
	if (is_sorted(*stack_a))
		return ;
	pb(stack_a, stack_b, 1);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b, 1);
}
