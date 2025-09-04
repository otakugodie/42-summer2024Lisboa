/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 08:36:16 by diegfern          #+#    #+#             */
/*   Updated: 2025/09/04 08:36:18 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Ejecuta las rotaciones inversas restantes para stack_a
** Usa rra cuando el costo es negativo
*/
void	do_reverse_rotate_a(t_stack **stack_a, int *cost_a)
{
	while (*cost_a < 0)
	{
		rra(stack_a, 1);
		(*cost_a)++;
	}
}

/*
** Ejecuta las rotaciones inversas restantes para stack_b
** Usa rrb cuando el costo es negativo
*/
void	do_reverse_rotate_b(t_stack **stack_b, int *cost_b)
{
	while (*cost_b < 0)
	{
		rrb(stack_b, 1);
		(*cost_b)++;
	}
}
