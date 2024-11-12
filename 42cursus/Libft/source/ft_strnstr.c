/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:51:40 by diegfern          #+#    #+#             */
/*   Updated: 2024/11/09 17:56:03 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*little)
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j] && (i + j) < len)
			j++;
		if (!little[j])
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

/* int  main(void)
{
	const char	*big;
	const char	*little;
	size_t		len;

	// Test 1: Substring found in middle of big
	big = "42 is the answer to life, the universe, and everything";
	little = "answer";
	len = 30;
	printf("Test 1: %d\n", ft_strnstr(big, little, len) == big + 10);
	// Test 2: Substring not found within length
	big = "42 is the answer to life, the universe, and everything";
	little = "universe";
	len = 20;
	printf("Test 2: %d\n", ft_strnstr(big, little, len) == NULL);
	// Test 3: Empty little string should return big
	big = "42 is the answer to life, the universe, and everything";
	little = "";
	len = 30;
	printf("Test 3: %d\n", ft_strnstr(big, little, len) == big);
	// Test 4: Substring found at the end of big
	big = "42 is the answer to life, the universe, and everything";
	little = "everything";
	len = 55;
	printf("Test 4: %d\n", ft_strnstr(big, little, len) == big + 44);
	// Test 5: Length limit too short to find little
	big = "42 is the answer to life, the universe, and everything";
	little = "universe";
	len = 25;
	printf("Test 5: %d\n", ft_strnstr(big, little, len) == NULL);
	return (0);
}
 */