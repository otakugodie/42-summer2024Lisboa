/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 08:36:24 by diegfern          #+#    #+#             */
/*   Updated: 2025/09/14 17:02:26 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Toma el primer elemento del stack b y lo pone en el stack a
** No hace nada si b está vacío
*/
void	pa(t_stack **stack_a, t_stack **stack_b, int print)
{
	t_stack	*temp;

	if (!*stack_b)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	if (print)
		ft_putstr("pa\n");
}

/*
** Toma el primer elemento del stack a y lo pone en el stack b
** No hace nada si a está vacío
*/
void	pb(t_stack **stack_a, t_stack **stack_b, int print)
{
	t_stack	*temp;

	if (!*stack_a)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	if (print)
		ft_putstr("pb\n");
}
