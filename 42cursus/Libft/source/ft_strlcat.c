/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:01:03 by diegfern          #+#    #+#             */
/*   Updated: 2024/11/06 06:36:57 by diegfern         ###   ########.fr       */
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

int main(void)
{
    char        dst1[30] = "Brave new ";
    const char  *src1 = "World!";
    size_t      result1;

    char    dst2[8] = "In a ";
    const char  *src2 = "brave new world";
    size_t  result2;

    char    dst3[8] = "In a ";
    const char  *src3 = "brave new world";
    size_t  result3;
    

    // Case 1: Concatenate when dst has enough space for src (dst tiene suficiente espacio para src)
    result1 = ft_strlcat(dst1, src1, sizeof(dst1));
    printf("Case 1: Concatenate when dst has enough space for src\n");
    printf("Result: %zu, Destination: '%s'\n\n", result1, dst1);

    //Case 2: Concatenate when dst does not have enough space for src (truncation) (dst no tiene suficiente espacio para src (truncamiento)
    result2 = ft_strlcat(dst2, src2, sizeof(dst2));
    printf("Case 2: Concatenate when dst does not have enough space for src\n");
    printf("Result: %zu, Destination: '%s'\n\n", result2, dst2);

    //Case 2: Concatenate when dst does not have enough space for src (truncation) (dst no tiene suficiente espacio para src (truncamiento)
    result3 = strlcat(dst3, src3, sizeof(dst3));
    printf("Case 2': Concatenate when dst does not have enough space for src\n");
    printf("Result: %zu, Destination: '%s'\n\n", result3, dst3);
    

    return (0);
}