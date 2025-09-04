/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 08:35:53 by diegfern          #+#    #+#             */
/*   Updated: 2025/09/04 08:35:58 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Función principal que inicia el algoritmo push_swap
** Valida la entrada, crea el stack y ejecuta el algoritmo de ordenación
*/
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (!is_valid_input(argc, argv))
		ft_error(&stack_a, &stack_b);
	i = 1;
	while (i < argc)
	{
		stack_add_back(&stack_a, new_stack((int)ft_atol(argv[i])));
		i++;
	}
	if (has_duplicates(stack_a))
		ft_error(&stack_a, &stack_b);
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a, stack_size);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

/*
** Determina qué algoritmo de ordenación usar según el tamaño del stack
** Para 2-5 elementos usa algoritmos simples, para más usa algoritmo complejo
*/
void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		sa(stack_a, 1);
	else if (stack_size == 3)
		sort_three(stack_a);
	else if (stack_size == 4)
		sort_four(stack_a, stack_b);
	else if (stack_size == 5)
		sort_five(stack_a, stack_b);
	else if (stack_size > 5 && !is_sorted(*stack_a))
		complex_sort(stack_a, stack_b);
}
