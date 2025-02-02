/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:10:54 by diegfern          #+#    #+#             */
/*   Updated: 2025/02/02 19:22:14 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/* int	main(void)
{
	// Test 1: Two identical strings
	char str1[] = "Hello, 42!";
	char str2[] = "Hello, 42!";
	printf("Test 1: %d\n", ft_memcmp(str1, str2, sizeof(str1)) == 0);

	// Test 2: Strings with a difference at the beginning
	char str3[] = "hello, 42!";
	char str4[] = "Hello, 42!";
	printf("Test 2: %d\n", ft_memcmp(str3, str4, sizeof(str3)) == memcmp(str3,
			str4, sizeof(str3)));

	// Test 3: Strings with a difference in the middle
	char str5[] = "Hello, 42!";
	char str6[] = "Hello, 43!";
	printf("Test 3: %d\n", ft_memcmp(str5, str6, sizeof(str5)) == memcmp(str5,
			str6, sizeof(str5)));

	// Test 4: Different lengths, shorter n value
	char str7[] = "Short";
	char str8[] = "Shorter";
	printf("Test 4: %d\n", ft_memcmp(str7, str8, 5) == memcmp(str7, str8, 5));
	// printf("Test 4: %d\n", ft_memcmp(str7, str8, 5));

	// Test 5: Different lengths, longer n value
	printf("Test 5: %d\n", ft_memcmp(str7, str8, 7) == memcmp(str7, str8, 7));

	// Test 6: Comparison of empty strings
	char str9[] = "";
	char str10[] = "";
	printf("Test 6: %d\n", ft_memcmp(str9, str10, 1) == 0);

	// Test 7: One string is empty, the other has content
	printf("Test 7: %d\n", ft_memcmp(str9, str7, 1) == memcmp(str9, str7, 1));

	// Test 8: Comparison within a longer string
	char str11[] = "This is a simple test string";
	char str12[] = "This is a simple test string";
	printf("Test 8: %d\n", ft_memcmp(str11, str12, 10) == 0);

	return (0);
}
 */