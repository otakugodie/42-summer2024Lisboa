/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:09:04 by diegfern          #+#    #+#             */
/*   Updated: 2024/11/12 21:01:52 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	uns_c;

	i = 0;
	str = (unsigned char *)s;
	uns_c = (unsigned char)c;
	while (str[i] && i < n)
	{
		if (str[i] == uns_c)
		{
			return ((void *)&str[i]);
		}
		i++;
	}
	if (uns_c == '\0' && str[i] == '\0')
		return ((void *)&str[i]);
	return (NULL);
}

/* int main(void)
{
	char	str1[] = "42 is awesome";
	char	str2[] = "Hello, 42!";
	char	str3[] = "Hello, World!";
	char	str4[] = "Find the end!";
	char	str5[] = "Hello\0World";
	char	str6[] = "Look here, 42!";
	char	str7[] = "";

	// Test 1: Character found at the beginning
	printf("Test 1: %s\n", (char *)ft_memchr(str1, '4', sizeof(str1)));
	// Test 2: Character found in the middle
	printf("Test 2: %s\n", (char *)ft_memchr(str2, '4', sizeof(str2)));
	// Test 3: Character not found in the range
	printf("Test 3: %s\n", (char *)ft_memchr(str3, 'x',
			sizeof(str3)) ? "Found" : "Not found");
	// Test 4: Character found at the end of the range
	printf("Test 4: %s\n", (char *)ft_memchr(str4, '!', sizeof(str4)));
	// Test 5: Searching for a null terminator
	printf("Test 5: %s\n", (char *)ft_memchr(str5, '\0', sizeof(str5)));
	// Test 6: Character within a limited range
	printf("Test 6: %s\n", (char *)ft_memchr(str6, '4',
			5) ? "Found" : "Not found");
	// Test 7: Empty string input
	printf("Test 7: %s\n", (char *)ft_memchr(str7, 'a',
			sizeof(str7)) ? "Found" : "Not found");
	return (0);
}
 */