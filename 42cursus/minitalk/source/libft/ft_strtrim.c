/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:34:53 by diegfern          #+#    #+#             */
/*   Updated: 2025/02/02 19:22:36 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
	{
		i++;
	}
	j = ft_strlen(s1);
	while (j && ft_strchr(set, s1[j - 1]))
		j--;
	return (ft_substr(s1, i, j - i));
}

/* int	main(void)
{
	char *result;

	// Test 1: Basic trimming from both ends
	// Prueba 1: Recorte básico en ambos extremos
	// s1 = "123 hello world 213", set = "213"
	result = ft_strtrim("123 hello world 213", "213");
	printf("Test 1 - Expected: ' hello world ' | Result: '%s'\n", result);
	free(result);

	// Test 2: No trimming needed / Prueba 2: No se requiere recorte
	// s1 = "hello", set = "xyz"
	result = ft_strtrim("hello", "xyz");
	printf("Test 2 - Expected: 'hello' | Result: '%s'\n", result);
	free(result);

	// Test 3: Trimming characters from both ends
	// Prueba 3: Recorte de caracteres en ambos extremos
	// s1 = "xxxyyyxx", set = "xy"
	result = ft_strtrim("xxxyyyxx", "xy");
	printf("Test 3 - Expected: '' | Result: '%s'\n", result);
	free(result);

	// Test 4: All characters in s1 are in set
	// Prueba 4: Todos los caracteres de s1 están en set
	// s1 = "aaaaaa", set = "a"
	result = ft_strtrim("aaaaaa", "a");
	printf("Test 4 - Expected: '' | Result: '%s'\n", result);
	free(result);

	// Test 5: Only trimming from the beginning
	// Prueba 5: Solo recorte al inicio
	// s1 = "!!hello", set = "!"
	result = ft_strtrim("!!hello", "!");
	printf("Test 5 - Expected: 'hello' | Result: '%s'\n", result);
	free(result);

	// Test 6: Only trimming from the end / Prueba 6: Solo recorte al final
	// s1 = "world***", set = "*"
	result = ft_strtrim("world***", "*");
	printf("Test 6 - Expected: 'world' | Result: '%s'\n", result);
	free(result);

	// Test 7: Empty s1 string / Prueba 7: Cadena s1 vacía
	// s1 = "", set = "abc"
	result = ft_strtrim("", "abc");
	printf("Test 7 - Expected: '' | Result: '%s'\n", result);
	free(result);

	// Test 8: Empty set string (no trimming)
	// Prueba 8: Cadena set vacía (sin recorte)
	// s1 = "hello world", set = ""
	result = ft_strtrim("hello world", "");
	printf("Test 8 - Expected: 'hello world' | Result: '%s'\n", result);
	free(result);

	// Test 9: Large trimming range / Prueba 9: Rango de recorte amplio
	// s1 = "123 hello world 213", set = "2134"
	result = ft_strtrim("123 hello world 213", "2134");
	printf("Test 9 - Expected: ' hello world ' | Result: '%s'\n", result);
	free(result);

	// Test 10: NULL set or s1 (edge case)
	// Prueba 10: set o s1 NULL (caso límite)
	result = ft_strtrim(NULL, "abc");
	printf("Test 10 - Expected: 'NULL' | Result: '%s'\n",
		result ? result : "NULL");
	result = ft_strtrim("hello world", NULL);
	printf("Test 10b - Expected: 'NULL' | Result: '%s'\n",
		result ? result : "NULL");

	return (0);
}
 */