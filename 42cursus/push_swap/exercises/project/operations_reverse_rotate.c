/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 08:36:33 by diegfern          #+#    #+#             */
/*   Updated: 2025/09/04 08:36:42 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Desplaza hacia abajo todos los elementos del stack a una posición
** El último elemento se convierte en el primero
*/
void	rra(t_stack **stack_a, int print)
{
	t_stack	*temp;
	t_stack	*bottom;
	t_stack	*before_bottom;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	bottom = get_stack_bottom(*stack_a);
	before_bottom = get_stack_before_bottom(*stack_a);
	temp = *stack_a;
	*stack_a = bottom;
	(*stack_a)->next = temp;
	before_bottom->next = NULL;
	if (print)
		ft_putstr("rra\n");
}

/*
** Desplaza hacia abajo todos los elementos del stack b una posición
** El último elemento se convierte en el primero
*/
void	rrb(t_stack **stack_b, int print)
{
	t_stack	*temp;
	t_stack	*bottom;
	t_stack	*before_bottom;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	bottom = get_stack_bottom(*stack_b);
	before_bottom = get_stack_before_bottom(*stack_b);
	temp = *stack_b;
	*stack_b = bottom;
	(*stack_b)->next = temp;
	before_bottom->next = NULL;
	if (print)
		ft_putstr("rrb\n");
}

/*
** Ejecuta rra y rrb al mismo tiempo
** Rota ambos stacks hacia abajo una posición
*/
void	rrr(t_stack **stack_a, t_stack **stack_b, int print)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (print)
		ft_putstr("rrr\n");
}
