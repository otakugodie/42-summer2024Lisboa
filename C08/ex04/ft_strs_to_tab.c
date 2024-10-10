/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 01:06:45 by diegfern          #+#    #+#             */
/*   Updated: 2024/10/10 02:20:52 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	dest = malloc(ft_str_len(src) * sizeof(char) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * ft_strs_to_tab - Transforma un array de cadenas en un array de estructuras.
 * ac: El número de cadenas en el array (tamaño de av).
 * av: El array de cadenas de caracteres.
 *
 * Return: Un array de estructuras t_stock_str con cada cadena y su copia,
 *         o NULL en caso de error de asignación de memoria.
 */

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*array;

	array = malloc((ac + 1) * sizeof(struct s_stock_str));
	if (!array)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		// Se almacena la longitud de la cadena
		array[i].size = ft_str_len(av[i]);
		// Se guarda la cadena original
		array[i].str = av[i];
		// Se crea una copia de la cadena original
		array[i].copy = ft_strdup(av[i]);
		i++;
	}
	array[i].str = 0;
	array[i].copy = 0;
	return (array);
}

/**
 * ft_free_structs
	- Libera la memoria asignada a un array de estructuras t_stock_str.
 * structs: El array de estructuras a liberar.
 */
void	ft_free_structs(struct s_stock_str *structs, int ac)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (structs[i].copy != NULL)
			free(structs[i].copy);
		i++;
	}
	free(structs);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	int					i;
	struct s_stock_str	*structs;

	/* Test: ./a.out "Hello" "42" "School" */
	structs = ft_strs_to_tab(argc, argv);
	i = 0;
	while (i < argc)
	{
		printf("%d\t", i);
		printf("| size : %d\n", structs[i].size);
		printf("\t| str  : $%s$ & %p\n", structs[i].str, structs[i].str);
		printf("\t| copy : $%s$ & %p\n\n", structs[i].copy, structs[i].copy);
		i++;
	}
	ft_free_structs(structs, argc);
}
