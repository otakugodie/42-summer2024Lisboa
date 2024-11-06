/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:01:03 by diegfern          #+#    #+#             */
/*   Updated: 2024/11/04 21:32:58 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	i;

	len_src = ft_strlen((char *)src);
	len_dst = ft_strlen((char *)dst);
	if (dstsize <= len_dst)
	{
		return (len_dst + len_src);
	}
	i = 0;
	while (src[i] != '\0' && (len_dst + i) < (dstsize - 1))
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}

/* int	main(void)
{
	char			dest[45] = "Today ";
	char			src[] = "yes";
	unsigned int	n;

	n = 45;
	printf("Initial destination: %s \n", dest);
	printf("%ld\n", ft_strlcat(dest, src, n));
	printf("Final destination: %s \n", dest);
	return (0);
}
 */