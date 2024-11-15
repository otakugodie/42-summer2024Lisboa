/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:07:28 by diegfern          #+#    #+#             */
/*   Updated: 2024/11/14 20:36:33 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	if (nmemb && size > SIZE_MAX / nmemb)
		return (NULL);
	array = malloc(nmemb * size);
	if (!array)
		return (NULL);
	ft_bzero(array, (nmemb * size));
	return (array);
}

/* int	main(void)
{
	void	*result;

	// Prueba 1: Tamaños normales (debe asignar memoria correctamente)
	result = ft_calloc(10, sizeof(int));
	printf("Test 1: %s\n", result != NULL ? "OK" : "FAIL");
	free(result);
	// Prueba 2: Prueba con tamaño cero en nmemb (puede devolver NULL
	//o un puntero no nulo dependiendo de la implementación)
	result = ft_calloc(0, sizeof(int));
	printf("Test 2: %s\n", result != NULL ? "OK" : "FAIL");
	free(result);
	// Prueba 3: Prueba con tamaño cero en size (puede devolver NULL
	//o un puntero no nulo dependiendo de la implementación)
	result = ft_calloc(10, 0);
	printf("Test 3: %s\n", result != NULL ? "OK" : "FAIL");
	free(result);
	// Prueba 4: Desbordamiento al multiplicar nmemb y size (debe devolver NULL)
	result = ft_calloc(SIZE_MAX, 2);
		// Intentar asignar más memoria de la que cabe en size_t
	printf("Test 4: %s\n", result == NULL ? "OK" : "FAIL");
	// Prueba 5: Compatibilidad con puntero nulo (nmemb = 0, size = 0,
		//puede devolver NULL o un puntero válido)
	result = ft_calloc(0, 0);
	printf("Test 5: %s\n", result != NULL ? "OK" : "FAIL");
	free(result);
	return (0);
}
 */