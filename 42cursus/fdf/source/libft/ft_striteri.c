/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:26:14 by diegfern          #+#    #+#             */
/*   Updated: 2024/11/17 15:45:47 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/* static void	ft_to_upper_even(unsigned int i, char *c)
{
	if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
		*c -= ' ';
}

static void	ft_replace_odd_with_underscore(unsigned int i, char *c)
{
	if (i % 2 != 0)
		*c = '_';
}

static void	ft_add_index_to_char(unsigned int i, char *c)
{
	*c += i;
}

static void	ft_replace_all_with_x(unsigned int i, char *c)
{
	(void)i; // Ignore index
	*c = 'X';
}

int	main(void)
{
	// Test case 1: Convert even-index characters to uppercase
	char str1[] = "hello, world!";
	printf("Original string: %s\n", str1); // Print original string
	// Convertir caracteres en índices pares a mayúsculas
	ft_striteri(str1, ft_to_upper_even);
	printf("Modified string: %s\n\n", str1);

	// Test case 2: Replace odd-index characters with '_'
	char str2[] = "hello, world!";
	printf("Original string: %s\n", str2); // Print original string
	// Reemplazar caracteres en índices impares con '_'
	ft_striteri(str2, ft_replace_odd_with_underscore);
	printf("Modified string: %s\n\n", str2);

	// Test case 3: Add index to each character
	char str3[] = "abcd";
	printf("Original string: %s\n", str3); // Print original string
	// Sumar el índice al valor ASCII de cada carácter
	ft_striteri(str3, ft_add_index_to_char);
	printf("Modified string: %s\n\n", str3);

	// Test case 4: Replace all characters with 'X'
	char str4[] = "123456789";
	printf("Original string: %s\n", str4); // Print original string
	// Reemplazar todos los caracteres con 'X'
	ft_striteri(str4, ft_replace_all_with_x);
	printf("Modified string: %s\n\n", str4);

	// Test case 5: Null string (Edge Case)
	char *str5 = NULL;
	printf("Original string: (null)\n"); // Null case test
	// Prueba con cadena nula
	ft_striteri(str5, ft_replace_all_with_x);
	printf("Modified string: (null)\n\n");

	// Test case 6: Empty string (Edge Case)
	char str6[] = "";
	printf("Original string: \"%s\"\n", str6); // Empty case test
	// Prueba con cadena vacía
	ft_striteri(str6, ft_replace_all_with_x);
	printf("Modified string: \"%s\"\n\n", str6);

	return (0);
}
 */