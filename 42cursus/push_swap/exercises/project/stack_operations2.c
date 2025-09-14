/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 08:37:31 by diegfern          #+#    #+#             */
/*   Updated: 2025/09/14 17:02:59 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Obtiene el penúltimo nodo del stack
** Retorna NULL si el stack tiene menos de 2 elementos
*/
t_stack	*get_stack_before_bottom(t_stack *stack)
{
	while (stack && stack->next && stack->next->next)
		stack = stack->next;
	return (stack);
}

/*
** Libera toda la memoria del stack
** Recorre la lista enlazada y libera cada nodo
*/
void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

/*
** Verifica si el stack está ordenado en orden ascendente
** Retorna 1 si está ordenado, 0 si no
*/
int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/*
** Asigna índices a todos los elementos del stack
** El índice representa la posición que debe ocupar en el stack ordenado
*/
void	assign_index(t_stack *stack_a, int stack_size)
{
	t_stack	*temp;
	t_stack	*highest;
	int		value;

	while (--stack_size > 0)
	{
		temp = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (temp)
		{
			if (temp->value == INT_MIN && temp->index == 0)
				temp->index = 1;
			if (temp->value > value && temp->index == 0)
			{
				value = temp->value;
				highest = temp;
			}
			temp = temp->next;
		}
		if (highest)
			highest->index = stack_size;
	}
}
