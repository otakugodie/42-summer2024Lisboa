/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:17:12 by diegfern          #+#    #+#             */
/*   Updated: 2025/02/02 19:22:33 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/* int	main(void)
{
	printf("Test 1: %d\n", ft_strncmp("apple", "apple", 5) == 0);
		// Ambos son iguales en 5 caracteres
	printf("Test 2: %d\n", ft_strncmp("apple", "apple", 10) == 0);
		// Ambos son iguales incluso con n > longitud
	printf("Test 3: %d\n", ft_strncmp("banana", "apple", 1) > 0); // 'b' > 'a',
		así que debe devolver positivo
	printf("Test 4: %d\n", ft_strncmp("apple", "apricot", 4) < 0);
		// 'l' < 'r' en el cuarto carácter
	printf("Test 5: %d\n", ft_strncmp("apple", "applesauce", 5) == 0);
		// Los primeros 5 caracteres son iguales
	printf("Test 6: %d\n", ft_strncmp("apple", "applesauce", 10) < 0);
		// "apple" es menor porque es más corto
	printf("Test 7: %d\n", ft_strncmp("Apple", "apple", 5) < 0);
		// 'A' < 'a' en ASCII
	printf("Test 8: %d\n", ft_strncmp("", "apple", 3) < 0);
		// Cadena vacía es menor que cualquier cadena no vacía
	printf("Test 9: %d\n", ft_strncmp("apple", "", 3) > 0);
		// "apple" es mayor que cadena vacía
	printf("Test 10: %d\n", ft_strncmp("apple", "banana", 0) == 0);
		// Si n es 0, siempre devuelve 0
	printf("Test 11: %d\n", ft_strncmp("apple\0tree", "apple\0banana",
			10) == 0); // Son iguales hasta el \0 en el índice 5
	return (0);
}
 */