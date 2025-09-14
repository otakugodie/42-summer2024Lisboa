/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 08:36:08 by diegfern          #+#    #+#             */
/*   Updated: 2025/09/14 17:02:19 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Ejecuta rotaciones simultáneas cuando ambos costos son positivos
** Optimiza usando la operación rr
*/
static void	do_rotate_both(t_stack **stack_a, t_stack **stack_b, int *cost_a,
		int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(stack_a, stack_b, 1);
		(*cost_a)--;
		(*cost_b)--;
	}
}

/*
** Ejecuta rotaciones inversas simultáneas cuando ambos costos son negativos
** Optimiza usando la operación rrr
*/
static void	do_reverse_rotate_both(t_stack **stack_a, t_stack **stack_b,
		int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(stack_a, stack_b, 1);
		(*cost_a)++;
		(*cost_b)++;
	}
}

/*
** Ejecuta las rotaciones restantes para stack_a
** Usa ra o rra según el signo del costo
*/
static void	do_rotate_a(t_stack **stack_a, int *cost_a)
{
	while (*cost_a > 0)
	{
		ra(stack_a, 1);
		(*cost_a)--;
	}
}

/*
** Ejecuta las rotaciones restantes para stack_b
** Usa rb o rrb según el signo del costo
*/
static void	do_rotate_b(t_stack **stack_b, int *cost_b)
{
	while (*cost_b > 0)
	{
		rb(stack_b, 1);
		(*cost_b)--;
	}
}

/*
** Ejecuta el movimiento óptimo basado en los costos calculados
** Optimiza usando operaciones combinadas cuando es posible
*/
void	do_move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_reverse_rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	do_rotate_a(stack_a, &cost_a);
	do_rotate_b(stack_b, &cost_b);
	do_reverse_rotate_a(stack_a, &cost_a);
	do_reverse_rotate_b(stack_b, &cost_b);
	pa(stack_a, stack_b, 1);
}
