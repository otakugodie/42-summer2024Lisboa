/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 08:36:48 by diegfern          #+#    #+#             */
/*   Updated: 2025/09/06 07:37:39 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Desplaza hacia arriba todos los elementos del stack a una posición
** El primer elemento se convierte en el último
*/
void	ra(t_stack **stack_a, int print)
{
	t_stack	*temp;
	t_stack	*bottom;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	bottom = get_stack_bottom(*stack_a);
	temp->next = NULL;
	bottom->next = temp;
	if (print)
		ft_putstr("ra\n");
}

/*
** Desplaza hacia arriba todos los elementos del stack b una posición
** El primer elemento se convierte en el último
*/
void	rb(t_stack **stack_b, int print)
{
	t_stack	*temp;
	t_stack	*bottom;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	bottom = get_stack_bottom(*stack_b);
	temp->next = NULL;
	bottom->next = temp;
	if (print)
		ft_putstr("rb\n");
}

/*
** Ejecuta ra y rb al mismo tiempo
** Rota ambos stacks hacia arriba una posición
*/
void	rr(t_stack **stack_a, t_stack **stack_b, int print)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (print)
		ft_putstr("rr\n");
}
