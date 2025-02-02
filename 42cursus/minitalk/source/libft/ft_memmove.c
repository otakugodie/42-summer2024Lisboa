/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:01:41 by diegfern          #+#    #+#             */
/*   Updated: 2025/02/02 19:22:15 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_temp;
	unsigned char	*src_temp;

	dest_temp = (unsigned char *)dest;
	src_temp = (unsigned char *)src;
	i = 0;
	if (dest_temp <= src_temp)
	{
		while (i < n)
		{
			dest_temp[i] = src_temp[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
		{
			dest_temp[n] = src_temp[n];
		}
	}
	return (dest);
}

/* int  main(void)
{
	char	src2[] = "Overlap test";
	char	src3[] = "123456789";
	char	src4[] = "Zero copy";
	char	dest4[20] = "Initial data";
	char	src1[] = "Hello, world!";
	char	dest1[20];

	// Copy without overlap
	ft_memmove(dest1, src1, ft_strlen(src1) + 1); // +1 for \0
	printf("Without overlap: %s\n", dest1);
	// Copy with overlap (src -> part of dest)
	ft_memmove(src2 + 4, src2, ft_strlen(src2));
	// Copy "Overlap test" in "rlap test"
	printf("Overlap: %s\n", src2);
	// Copy front to back (inverse overlap)
	ft_memmove(src3, src3 + 2, 7); // Copy "3456789" over "1234567"
	printf("Inverse overlap: %s\n", src3);
	// Copy 0 bytes (must keep the destination unchanged)
	ft_memmove(dest4, src4, 0);
	printf("Copy 0 bytes: %s\n", dest4);
	return (0);
}
 */