/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 22:52:44 by diegfern          #+#    #+#             */
/*   Updated: 2024/09/26 09:09:34 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	pos;

	pos = 0;
	while (src[pos] && pos < n)
	{
		dest[pos] = src[pos];
		pos++;
	}
	while (pos < n)
	{
		dest[pos] = '\0';
		pos++;
	}
	return (dest);
}

#include <stdio.h>

int	main(void)
{
	char str_orig[] = "Hello";
	char str_dest[] = "aaaaaaaaaa";
	char str_orig2[] = "Hell";

	// Tests
	printf("%s\n", ft_strncpy(str_dest, str_orig, 5));
	printf("%s\n", ft_strncpy(str_dest, str_orig2, 5));
	printf("%s\n", ft_strncpy(str_dest, str_orig, 3));
	printf("%s\n", ft_strncpy(str_dest, str_orig, 7));

	return (0);
}
