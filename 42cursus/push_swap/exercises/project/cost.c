/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 23:41:23 by diegfern          #+#    #+#             */
/*   Updated: 2025/09/04 08:33:25 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Calcula el costo de mover un elemento a la posición objetivo en stack_a
** Considera si es más eficiente rotar hacia arriba o hacia abajo
*/
int	calculate_cost_a(t_stack **stack_a, int target_pos)
{
	int	size;

	size = get_stack_size(*stack_a);
	if (target_pos < size / 2)
		return (target_pos);
	else
		return (-(size - target_pos));
}

/*
** Calcula el costo de mover un elemento desde su posición actual en stack_b
** Considera si es más eficiente rotar hacia arriba o hacia abajo
*/
int	calculate_cost_b(t_stack **stack_b, int pos)
{
	int	size;

	size = get_stack_size(*stack_b);
	if (pos < size / 2)
		return (pos);
	else
		return (-(size - pos));
}

/*
** Calcula y asigna los costos para todos los elementos en stack_b
** El costo representa el número de operaciones necesarias
*/
void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_b;

	temp_b = *stack_b;
	while (temp_b)
	{
		temp_b->cost_b = calculate_cost_b(stack_b, temp_b->pos);
		temp_b->cost_a = calculate_cost_a(stack_a, temp_b->target_pos);
		temp_b = temp_b->next;
	}
}

/*
** Encuentra y ejecuta el movimiento más barato
** Compara todos los costos y ejecuta el que requiere menos operaciones
*/
void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*cheapest;
	int		cheapest_cost;
	int		cost_a;
	int		cost_b;

	temp = *stack_b;
	cheapest_cost = INT_MAX;
	while (temp)
	{
		if ((temp->cost_a < 0 && temp->cost_b < 0) || (temp->cost_a >= 0
				&& temp->cost_b >= 0))
		{
			if (temp->cost_a < 0)
				cost_a = -temp->cost_a;
			else
				cost_a = temp->cost_a;
			if (temp->cost_b < 0)
				cost_b = -temp->cost_b;
			else
				cost_b = temp->cost_b;
			if (cost_a > cost_b)
				cost_a = cost_a;
			else
				cost_a = cost_b;
		}
		else
		{
			if (temp->cost_a < 0)
				cost_a = -temp->cost_a;
			else
				cost_a = temp->cost_a;
			if (temp->cost_b < 0)
				cost_b = -temp->cost_b;
			else
				cost_b = temp->cost_b;
			cost_a = cost_a + cost_b;
		}
		if (cost_a < cheapest_cost)
		{
			cheapest_cost = cost_a;
			cheapest = temp;
		}
		temp = temp->next;
	}
	do_move(stack_a, stack_b, cheapest->cost_a, cheapest->cost_b);
}
