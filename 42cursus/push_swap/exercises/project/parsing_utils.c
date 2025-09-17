/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:35:00 by diegfern          #+#    #+#             */
/*   Updated: 2025/09/16 21:54:55 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Libera la memoria del array de strings
** Retorna NULL para facilitar el manejo de errores
*/
char	**free_split_result(char **result, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

/*
** Libera completamente un array de strings
** Útil para liberar el resultado de ft_split_args
*/
void	free_split_args(char **split_args)
{
	int	i;

	if (!split_args)
		return ;
	i = 0;
	while (split_args[i])
	{
		free(split_args[i]);
		i++;
	}
	free(split_args);
}

/*
** Valida que todos los argumentos del split sean números válidos
** Retorna 1 si son válidos, 0 si hay algún error
*/
int	is_valid_split_input(char **split_args)
{
	int		i;
	long	temp;

	if (!split_args)
		return (0);
	i = 0;
	while (split_args[i])
	{
		if (!is_number(split_args[i]))
			return (0);
		temp = ft_atol(split_args[i]);
		if (temp < INT_MIN || temp > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}
