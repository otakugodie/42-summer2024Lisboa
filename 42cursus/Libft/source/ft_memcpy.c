/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 08:43:49 by diegfern          #+#    #+#             */
/*   Updated: 2024/11/01 08:54:30 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	else if (dest != src)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}

/* int	main(void)
{
	char	src[50] = "This is memcpy function";
	char	dest[50];

	printf("Source string is: \t%s\n", src);
	printf("Destination string is: %s\n\n\n", dest);
	ft_memcpy(&dest, &src, 9);
	printf("Source string is: \t\t\t%s\n", src);
	printf("Destination string is after memcpy: \t%s\n\n", dest);
	return (0);
}
 */