/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 08:35:53 by diegfern          #+#    #+#             */
/*   Updated: 2025/09/16 21:44:30 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Crea el stack desde argumentos separados (formato original)
** Retorna el stack creado o NULL si hay error
*/
static t_stack	*create_stack_from_args(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;

	stack_a = NULL;
	if (!is_valid_input(argc, argv))
		return (NULL);
	i = 1;
	while (i < argc)
	{
		stack_add_back(&stack_a, new_stack((int)ft_atol(argv[i])));
		i++;
	}
	return (stack_a);
}

/*
** Crea el stack desde una cadena con números separados por espacios
** Retorna el stack creado o NULL si hay error
*/
static t_stack	*create_stack_from_string(char *str)
{
	t_stack	*stack_a;
	char	**split_args;
	int		i;

	stack_a = NULL;
	split_args = ft_split_args(str);
	if (!split_args || !is_valid_split_input(split_args))
	{
		free_split_args(split_args);
		return (NULL);
	}
	i = 0;
	while (split_args[i])
	{
		stack_add_back(&stack_a, new_stack((int)ft_atol(split_args[i])));
		i++;
	}
	free_split_args(split_args);
	return (stack_a);
}

/*
** Función principal que inicia el algoritmo push_swap
** Maneja tanto argumentos separados como cadena única
*/
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
		stack_a = create_stack_from_string(argv[1]);
	else
		stack_a = create_stack_from_args(argc, argv);
	if (!stack_a || has_duplicates(stack_a))
		ft_error(&stack_a, &stack_b);
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a, stack_size);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

/*
** FUNCION ORIGINAL
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

/*
** FUNCION DE DEPURACIÓN - Declaraciones
*/
//void	debug_print_stack(t_stack *stack, char *name);
//int		ft_strlen(char *str);
//void	ft_putnbr_fd(int n, int fd);
//void	debug_target_positions(t_stack *stack_a, t_stack *stack_b);
//
/*
** FUNCION DE DEPURACIÓN
** Determina qué algoritmo de ordenación usar según el tamaño del stack
** Para 2-5 elementos usa algoritmos simples, para más usa algoritmo complejo
*/
/*
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

	if (!check_solution(*stack_a, *stack_b))
	{
		write(2, "DEBUG: Solution failed!\n", 24);
		debug_print_stack(*stack_a, "Stack A");
		debug_print_stack(*stack_b, "Stack B");
		if (*stack_b != NULL)
			write(2, "DEBUG: Stack B not empty\n", 25);
		if (!is_sorted(*stack_a))
			write(2, "DEBUG: Stack A not sorted\n", 26);
	}
	else
	{
		write(2, "DEBUG: Solution SUCCESS!\n", 25);
		debug_print_stack(*stack_a, "Stack A");
		debug_print_stack(*stack_b, "Stack B");
	}
}
*/

/*
** FUNCION DE DEPURACIÓN
** Muestra las posiciones objetivo calculadas para stack_b
*/
/*
void	debug_target_positions(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*temp;

	write(2, "DEBUG: Target positions for stack_b elements:\n", 46);
	temp = stack_b;
	while (temp)
	{
		write(2, "  Element ", 10);
		ft_putnbr_fd(temp->value, 2);
		write(2, " (index ", 8);
		ft_putnbr_fd(temp->index, 2);
		write(2, ") -> target_pos: ", 17);
		ft_putnbr_fd(temp->target_pos, 2);
		write(2, "\n", 1);
		temp = temp->next;
	}
	write(2, "DEBUG: Current stack_a positions:\n", 34);
	temp = stack_a;
	while (temp)
	{
		write(2, "  Pos ", 6);
		ft_putnbr_fd(temp->pos, 2);
		write(2, ": value ", 8);
		ft_putnbr_fd(temp->value, 2);
		write(2, " (index ", 8);
		ft_putnbr_fd(temp->index, 2);
		write(2, ")\n", 2);
		temp = temp->next;
	}
}
*/

/*
** FUNCION DE DEPURACIÓN
** Función auxiliar para imprimir números
*/
/*
void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}
*/

/*
** FUNCION DE DEPURACIÓN
** Función de debug para imprimir un stack
*/
/*
void	debug_print_stack(t_stack *stack, char *name)
{
	t_stack	*temp;

	write(2, "DEBUG: ", 7);
	write(2, name, ft_strlen(name));
	write(2, ": ", 2);
	temp = stack;
	while (temp)
	{
		ft_putnbr_fd(temp->value, 2);
		if (temp->next)
			write(2, " -> ", 4);
		temp = temp->next;
	}
	if (!stack)
		write(2, "(empty)", 7);
	write(2, "\n", 1);
}
*/

/*
** FUNCION DE DEPURACIÓN
** Función auxiliar para obtener longitud de string
*/
/*
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
*/