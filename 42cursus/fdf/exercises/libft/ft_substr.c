/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 07:02:29 by diegfern          #+#    #+#             */
/*   Updated: 2024/11/14 17:53:22 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;
	size_t	str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_calloc(1, sizeof(char)));
	if (start + len > str_len)
		len = str_len - start;
	i = 0;
	s2 = malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	while (i < len)
	{
		s2[i] = s[i + start];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

/* int	main(void)
{
	char	*result;

	// Test 1: Normal string with start and len within limits
	// Cadena normal con start y len dentro de límites
	result = ft_substr("Hello, world!", 7, 5);
	printf("Test 1: %d\n", strcmp(result, "world") == 0);
	free(result);
	// Test 2: Start at the beginning of the string
	// Start al comienzo de la cadena
	result = ft_substr("Hello, world!", 0, 5);
	printf("Test 2: %d\n", strcmp(result, "Hello") == 0);
	free(result);
	// Test 3: Start in the middle and len larger than the rest of the string
	// Start en el medio y len mayor al resto de la cadena
	result = ft_substr("Hello, world!", 7, 20);
	printf("Test 3: %d\n", strcmp(result, "world!") == 0);
	free(result);
	// Test 4: Start out of the string length
	// Start fuera de la longitud de la cadena
	result = ft_substr("Hello, world!", 20, 5);
	printf("Test 4: %d\n", strcmp(result, "") == 0);
	free(result);
	// Test 5: len = 0 should return an empty string
	// len = 0 debería devolver una cadena vacía
	result = ft_substr("Hello, world!", 5, 0);
	printf("Test 5: %d\n", strcmp(result, "") == 0);
	free(result);
	// Test 6: Empty string with start = 0 and len = 5
	// Cadena vacía con start = 0 y len = 5
	result = ft_substr("", 0, 5);
	printf("Test 6: %d\n", strcmp(result, "") == 0);
	free(result);
	// Test 7: Start within the string but len = 0
	// Start dentro de la cadena, pero len = 0
	result = ft_substr("Hello, world!", 7, 0);
	printf("Test 7: %d\n", strcmp(result, "") == 0);
	free(result);
	// Test 8: Start at the limit of the string, but len larger than the rest
	// Start en el límite de la cadena, pero len mayor que el resto
	result = ft_substr("Libft", 4, 10);
	printf("Test 8: %d\n", strcmp(result, "t") == 0);
	free(result);
	// Test 9: Start and len are both 0, should return an empty string
	// Start y len son ambos 0, debería devolver una cadena vacía
	result = ft_substr("Libft", 0, 0);
	printf("Test 9: %d\n", strcmp(result, "") == 0);
	free(result);
	return (0);
}
 */