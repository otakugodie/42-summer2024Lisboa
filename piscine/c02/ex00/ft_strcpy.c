/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 22:52:03 by diegfern          #+#    #+#             */
/*   Updated: 2024/09/26 09:09:38 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	pos;

	pos = 0;
	while (src[pos])
	{
		dest[pos] = src[pos];
		pos++;
	}
	dest[pos] = '\0';
	return (dest);
}

#include <stdio.h>

int	main(void)
{
	char str_orig[] = "Hello world";
	char str_copy[] = "";

	printf("Original: %s\n", str_orig);
	printf("Copy before: %s\n", str_copy);

	ft_strcpy(str_copy, str_orig);

	printf("Copy: %s\n", str_copy);

	return (0);
}
