/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 08:35:26 by diegfern          #+#    #+#             */
/*   Updated: 2025/09/04 08:35:29 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

/* Estructura para representar un nodo del stack */
typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

/* Funciones principales */
int					main(int argc, char **argv);
void				push_swap(t_stack **stack_a, t_stack **stack_b,
						int stack_size);

/* Funciones de validación y parsing */
int					is_valid_input(int argc, char **argv);
int					is_number(char *str);
int					has_duplicates(t_stack *stack);
long				ft_atol(const char *str);

/* Funciones de stack */
t_stack				*new_stack(int value);
void				stack_add_back(t_stack **stack, t_stack *new);
int					get_stack_size(t_stack *stack);
t_stack				*get_stack_bottom(t_stack *stack);
t_stack				*get_stack_before_bottom(t_stack *stack);
void				free_stack(t_stack *stack);

/* Operaciones básicas */
void				sa(t_stack **stack_a, int print);
void				sb(t_stack **stack_b, int print);
void				ss(t_stack **stack_a, t_stack **stack_b, int print);
void				pa(t_stack **stack_a, t_stack **stack_b, int print);
void				pb(t_stack **stack_a, t_stack **stack_b, int print);
void				ra(t_stack **stack_a, int print);
void				rb(t_stack **stack_b, int print);
void				rr(t_stack **stack_a, t_stack **stack_b, int print);
void				rra(t_stack **stack_a, int print);
void				rrb(t_stack **stack_b, int print);
void				rrr(t_stack **stack_a, t_stack **stack_b, int print);

/* Algoritmos de ordenación */
void				simple_sort(t_stack **stack_a, t_stack **stack_b);
void				sort_three(t_stack **stack_a);
void				sort_four(t_stack **stack_a, t_stack **stack_b);
void				sort_five(t_stack **stack_a, t_stack **stack_b);
void				complex_sort(t_stack **stack_a, t_stack **stack_b);

/* Funciones de utilidad para el algoritmo complejo */
void				assign_index(t_stack *stack_a, int stack_size);
void				assign_target_positions(t_stack **stack_a,
						t_stack **stack_b);
void				assign_costs(t_stack **stack_a, t_stack **stack_b);
void				do_cheapest_move(t_stack **stack_a, t_stack **stack_b);

/* Funciones de posicionamiento */
int					get_lowest_index_position(t_stack **stack);
void				assign_positions(t_stack **stack);
int					get_target_position(t_stack **stack_a, int index_b);

/* Funciones de cálculo de costos */
int					calculate_cost_a(t_stack **stack_a, int target_pos);
int					calculate_cost_b(t_stack **stack_b, int pos);
void				get_cost(t_stack **stack_a, t_stack **stack_b);

/* Funciones de ejecución de movimientos */
void				do_move(t_stack **stack_a, t_stack **stack_b, int cost_a,
						int cost_b);
void				do_rotate_both(t_stack **stack_a, t_stack **stack_b,
						int *cost_a, int *cost_b);
void				do_reverse_rotate_both(t_stack **stack_a, t_stack **stack_b,
						int *cost_a, int *cost_b);
void				do_rotate_a(t_stack **stack_a, int *cost_a);
void				do_rotate_b(t_stack **stack_b, int *cost_b);
void				do_reverse_rotate_a(t_stack **stack_a, int *cost_a);
void				do_reverse_rotate_b(t_stack **stack_b, int *cost_b);

/* Funciones de verificación */
int					is_sorted(t_stack *stack);

/* Funciones de error */
void				ft_error(t_stack **stack_a, t_stack **stack_b);

/* Funciones auxiliares */
void				ft_putstr(char *str);
void				ft_putchar(char c);

#endif
