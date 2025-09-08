/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 08:37:38 by diegfern          #+#    #+#             */
/*   Updated: 2025/09/04 08:37:38 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Imprime un mensaje de error y libera la memoria
** Termina el programa con código de error
*/
void	ft_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a && *stack_a)
		free_stack(*stack_a);
	if (stack_b && *stack_b)
		free_stack(*stack_b);
	write(2, "Error\n", 6);
	exit(1);
}

/*
** Imprime una cadena de caracteres
** Usado para mostrar las operaciones realizadas
*/
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

/*
** Imprime un carácter
** Función auxiliar para la salida
*/
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
** Verifica que la solución sea correcta
** Retorna 1 si stack_a está ordenado y stack_b está vacío, 0 si no
*/
int	check_solution(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b != NULL)
		return (0);
	return (is_sorted(stack_a));
}
