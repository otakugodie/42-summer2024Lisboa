/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 08:35:37 by diegfern          #+#    #+#             */
/*   Updated: 2025/09/08 20:50:42 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Fase 1: Empuja elementos pequeños (índice <= size/2) a stack_b
** Rota stack_a si el elemento actual es grande para optimizar
*/
static void	push_small_elements(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pushed;
	int	i;

	size = get_stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (size > 6 && i < size && pushed < size / 2)
	{
		if ((*stack_a)->index <= size / 2)
		{
			pb(stack_a, stack_b, 1);
			pushed++;
		}
		else
			ra(stack_a, 1);
		i++;
	}
}

/*
** Fase 2: Empuja elementos restantes hasta dejar solo 3 en stack_a
** Garantiza que stack_a tenga exactamente 3 elementos para sort_three
*/
static void	push_remaining_elements(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pushed;

	size = get_stack_size(*stack_a);
	pushed = get_stack_size(*stack_b);
	while (size - pushed > 3)
	{
		pb(stack_a, stack_b, 1);
		pushed++;
	}
}

/*
** Fase 3: Ordena los 3 elementos de stack_a y devuelve elementos de stack_b
** Usa el algoritmo de costo más barato para cada elemento de stack_b
*/
static void	sort_and_return_elements(t_stack **stack_a, t_stack **stack_b)
{
	int	debug_count = 0;		/* DEPURACIÓN: contador de iteraciones */

	sort_three(stack_a);
	while (*stack_b)
	{
		assign_target_positions(stack_a, stack_b);
		if (debug_count < 3)		/* DEPURACIÓN: mostrar primeras 3 iteraciones */
		{
			write(2, "\n--- ITERACION ", 15);
			ft_putnbr_fd(debug_count + 1, 2);
			write(2, " ---\n", 5);
			debug_target_positions(*stack_a, *stack_b);
			debug_count++;		/* DEPURACIÓN: incrementar contador */
		}
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
}

/*
** Fase 4: Rotación final para posicionar el elemento más pequeño en el top
** Determina si es más eficiente rotar hacia arriba o hacia abajo
*/
static void	final_rotation(t_stack **stack_a)
{
	int	size;

	if (!is_sorted(*stack_a))
	{
		size = get_lowest_index_position(stack_a);
		if (size < get_stack_size(*stack_a) / 2)
		{
			while (size--)
				ra(stack_a, 1);
		}
		else
		{
			size = get_stack_size(*stack_a) - size;
			while (size--)
				rra(stack_a, 1);
		}
	}
}

/*
** Algoritmo principal para ordenar stacks grandes (más de 5 elementos)
** Usa el método del "costo más barato" dividido en 4 fases optimizadas
*/
void	complex_sort(t_stack **stack_a, t_stack **stack_b)
{
	push_small_elements(stack_a, stack_b);
	push_remaining_elements(stack_a, stack_b);
	sort_and_return_elements(stack_a, stack_b);
	final_rotation(stack_a);
}
