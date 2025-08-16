/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:23:32 by diegfern          #+#    #+#             */
/*   Updated: 2024/11/14 06:16:26 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	i;

	i = 0;
	dst = malloc(ft_strlen(s) + 1);
	if (!dst)
		return (NULL);
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

/* int	main(void)
{
	char	*test1;
	char	*result1;
	char	*test2;
	char	*result2;
	char	*test3;
	char	*result3;
	char	*test4;
	char	*result4;	
	char	*test5;
	char	*result5;

	// Test 1: Empty string
	test1 = "";
	result1 = ft_strdup(test1);
	printf("Test 1: %d\n", strcmp(result1, test1) == 0);
	free(result1);
	// Test 2: Short string
	test2 = "42";
	result2 = ft_strdup(test2);
	printf("Test 2: %d\n", strcmp(result2, test2) == 0);
	free(result2);
	// Test 3: Longer string
	test3 = "School 42 is great!";
	result3 = ft_strdup(test3);
	printf("Test 3: %d\n", strcmp(result3, test3) == 0);
	free(result3);
	// Test 4: String with special characters
	test4 = "Hello\n\tWorld!";
	result4 = ft_strdup(test4);
	printf("Test 4: %d\n", strcmp(result4, test4) == 0);
	free(result4);
	
	// Test 5: Independent memory test
	test5 = "Memory test";
	result5 = strdup(test5);
	result5[0] = 'm';
	printf("Test 5: %d\n", strcmp(result5, "memory test") == 0
		&& strcmp(result5, test5) != 0);
	free(result5);
	return (0);
}
 */