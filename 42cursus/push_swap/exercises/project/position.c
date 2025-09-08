/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 08:37:03 by diegfern          #+#    #+#             */
/*   Updated: 2025/09/08 20:50:47 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Obtiene la posición del elemento con el índice más bajo en el stack
** Retorna la posición (0-indexada) del elemento más pequeño
*/
int	get_lowest_index_position(t_stack **stack)
{
	t_stack	*temp;
	int		lowest_index;
	int		lowest_pos;
	int		pos;

	temp = *stack;
	lowest_index = INT_MAX;
	lowest_pos = 0;
	pos = 0;
	while (temp)
	{
		if (temp->index < lowest_index)
		{
			lowest_index = temp->index;
			lowest_pos = pos;
		}
		temp = temp->next;
		pos++;
	}
	return (lowest_pos);
}

/*
** Asigna posiciones a todos los elementos del stack
** La posición representa la distancia desde el top del stack
*/
void	assign_positions(t_stack **stack)
{
	t_stack	*temp;
	int		pos;

	temp = *stack;
	pos = 0;
	while (temp)
	{
		temp->pos = pos;
		temp = temp->next;
		pos++;
	}
}

/*
** Encuentra la posición objetivo en stack_a para un elemento de stack_b
** Determina dónde debe insertarse el elemento para mantener el orden
*/
static int	get_target_position(t_stack **stack_a, int index_b)
{
	t_stack	*temp_a;
	int		target_pos;
	int		target_index;

	/* target_pos = 1; */
	target_pos = 0;			/* BUG FIX: posiciones empiezan en 0, no en 1 */
	target_index = INT_MAX;
	temp_a = *stack_a;
	while (temp_a)
	{
		if (temp_a->index > index_b && temp_a->index < target_index)
		{
			target_index = temp_a->index;
			target_pos = temp_a->pos;
		}
		temp_a = temp_a->next;
	}
	if (target_index == INT_MAX)
		target_pos = get_lowest_index_position(stack_a);
	return (target_pos);
}

/*
** Asigna las posiciones objetivo para todos los elementos en stack_b
** Calcula dónde debe ir cada elemento de stack_b en stack_a
*/
void	assign_target_positions(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_b;

	assign_positions(stack_a);
	assign_positions(stack_b);
	temp_b = *stack_b;
	while (temp_b)
	{
		temp_b->target_pos = get_target_position(stack_a, temp_b->index);
		temp_b = temp_b->next;
	}
}
