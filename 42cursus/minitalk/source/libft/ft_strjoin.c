/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:53:54 by diegfern          #+#    #+#             */
/*   Updated: 2025/02/02 19:22:27 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_join;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	s_join = malloc((sizeof(char)) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s_join)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s_join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s_join[i + j] = s2[j];
		j++;
	}
	s_join[i + j] = '\0';
	return (s_join);
}

/* int	main(void)
{
	char	*result;

	// Test 1: Concatenación de cadenas comunes (Hello + World)
	// Test 1: Common strings concatenation (Hello + World)
	result = ft_strjoin("Hello", "World");
	printf("Test 1: %d\n", strcmp(result, "HelloWorld") == 0);
	free(result);
	// Test 2: Una cadena vacía y una cadena no vacía ("Hola" + "")
	// Test 2: One empty string and one non-empty string ("Hola" + "")
	result = ft_strjoin("Hola", "");
	printf("Test 2: %d\n", strcmp(result, "Hola") == 0);
	free(result);
	// Test 3: Concat de cadena vacía con otra no vacía ("" + "Mundo")
	// Test 3: Concat of empty string with a non-empty (""+ "Mundo")
	result = ft_strjoin("", "Mundo");
	printf("Test 3: %d\n", strcmp(result, "Mundo") == 0);
	free(result);
	// Test 4: Ambas cadenas vacías ("" + "")
	// Test 4: Both strings empty ("" + "")
	result = ft_strjoin("", "");
	printf("Test 4: %d\n", strcmp(result, "") == 0);
	free(result);
	// Test 5: Concat cadena con un carácter y otra cadena ("A"+"BCDEFGHIJK")
	// Test 5: Concat of single-char with a long string ("A"+"BCDEFGHIJK")
	result = ft_strjoin("A", "BCDEFGHIJK");
	printf("Test 5: %d\n", strcmp(result, "ABCDEFGHIJK") == 0);
	free(result);
	// Test 6: Concatenación con caracteres especiales ("@#$%" + "^&*()")
	// Test 6: Concatenation with special characters ("@#$%" + "^&*()")
	result = ft_strjoin("@#$%", "^&*()");
	printf("Test 6: %d\n", strcmp(result, "@#$%^&*()") == 0);
	free(result);
	// Test 7: Paso de punteros nulos (NULL + "World")
	// Test 7: Passing null pointers (NULL + "World")
	result = ft_strjoin(NULL, "World");
	printf("Test 7: %d\n", result == NULL);
	// Test 8: Paso de punteros nulos ("Hello" + NULL)
	// Test 8: Passing null pointers ("Hello" + NULL)
	result = ft_strjoin("Hello", NULL);
	printf("Test 8: %d\n", result == NULL);
	// Test 9: Ambos punteros nulos (NULL + NULL)
	// Test 9: Both pointers null (NULL + NULL)
	result = ft_strjoin(NULL, NULL);
	printf("Test 9: %d\n", result == NULL);
	return (0);
}
 */