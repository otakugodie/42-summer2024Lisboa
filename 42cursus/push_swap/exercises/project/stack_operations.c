/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 08:37:23 by diegfern          #+#    #+#             */
/*   Updated: 2025/09/14 17:02:52 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Crea un nuevo nodo del stack con el valor dado
** Inicializa todos los campos de la estructura
*/
t_stack	*new_stack(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = 0;
	new->target_pos = 0;
	new->cost_a = 0;
	new->cost_b = 0;
	new->next = NULL;
	return (new);
}

/*
** Añade un nuevo nodo al final del stack
** Si el stack está vacío, el nuevo nodo se convierte en la cabeza
*/
void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	temp = get_stack_bottom(*stack);
	temp->next = new;
}

/*
** Calcula y retorna el tamaño del stack
** Recorre toda la lista enlazada contando los nodos
*/
int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

/*
** Obtiene el último nodo del stack
** Retorna NULL si el stack está vacío
*/
t_stack	*get_stack_bottom(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}
