/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 07:36:11 by diegfern          #+#    #+#             */
/*   Updated: 2025/09/14 17:01:55 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Calcula el costo total considerando si se pueden combinar operaciones
** Si ambos costos tienen el mismo signo, puede usar rr/rrr (toma el máximo)
** Si tienen signos diferentes, deben ejecutarse por separado (suma ambos)
*/
static int	calculate_total_cost(int cost_a, int cost_b)
{
	int	abs_cost_a;
	int	abs_cost_b;

	if (cost_a < 0)
		abs_cost_a = -cost_a;
	else
		abs_cost_a = cost_a;
	if (cost_b < 0)
		abs_cost_b = -cost_b;
	else
		abs_cost_b = cost_b;
	if ((cost_a < 0 && cost_b < 0) || (cost_a >= 0 && cost_b >= 0))
	{
		if (abs_cost_a > abs_cost_b)
			return (abs_cost_a);
		else
			return (abs_cost_b);
	}
	else
		return (abs_cost_a + abs_cost_b);
}

/*
** Encuentra el elemento en stack_b que requiere el menor costo total
** Recorre todo stack_b comparando costos y retorna el más eficiente
*/
t_stack	*find_cheapest_element(t_stack *stack_b)
{
	t_stack	*temp;
	t_stack	*cheapest;
	int		cheapest_cost;
	int		current_cost;

	temp = stack_b;
	cheapest = stack_b;
	cheapest_cost = INT_MAX;
	while (temp)
	{
		current_cost = calculate_total_cost(temp->cost_a, temp->cost_b);
		if (current_cost < cheapest_cost)
		{
			cheapest_cost = current_cost;
			cheapest = temp;
		}
		temp = temp->next;
	}
	return (cheapest);
}
