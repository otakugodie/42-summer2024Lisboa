/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 08:36:55 by diegfern          #+#    #+#             */
/*   Updated: 2025/09/14 17:02:32 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Intercambia los dos primeros elementos del stack a
** No hace nada si hay uno o menos elementos
*/
void	sa(t_stack **stack_a, int print)
{
	t_stack	*temp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = (*stack_a)->next;
	(*stack_a)->next = temp;
	if (print)
		ft_putstr("sa\n");
}

/*
** Intercambia los dos primeros elementos del stack b
** No hace nada si hay uno o menos elementos
*/
void	sb(t_stack **stack_b, int print)
{
	t_stack	*temp;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = (*stack_b)->next;
	(*stack_b)->next = temp;
	if (print)
		ft_putstr("sb\n");
}

/*
** Ejecuta sa y sb al mismo tiempo
** Intercambia los dos primeros elementos de ambos stacks
*/
void	ss(t_stack **stack_a, t_stack **stack_b, int print)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (print)
		ft_putstr("ss\n");
}
