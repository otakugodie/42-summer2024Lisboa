/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 08:37:42 by diegfern          #+#    #+#             */
/*   Updated: 2025/09/04 08:37:43 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Valida que todos los argumentos sean números válidos
** Retorna 1 si son válidos, 0 si hay algún error
*/
int	is_valid_input(int argc, char **argv)
{
	int		i;
	long	temp;

	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (0);
		temp = ft_atol(argv[i]);
		if (temp < INT_MIN || temp > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

/*
** Verifica si una cadena representa un número válido
** Acepta números negativos y positivos
*/
int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/*
** Verifica si hay números duplicados en el stack
** Retorna 1 si hay duplicados, 0 si no los hay
*/
int	has_duplicates(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack->next;
		while (temp)
		{
			if (stack->value == temp->value)
				return (1);
			temp = temp->next;
		}
		stack = stack->next;
	}
	return (0);
}

/*
** Convierte una cadena a un número long
** Maneja números negativos y positivos
*/
long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
