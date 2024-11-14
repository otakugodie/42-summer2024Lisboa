/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:01:03 by diegfern          #+#    #+#             */
/*   Updated: 2024/11/13 19:52:35 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	i;

	len_src = ft_strlen((char *)src);
	len_dst = ft_strlen((char *)dst);
	if (size <= len_dst)
	{
		return (size + len_src);
	}
	i = 0;
	while (src[i] != '\0' && (len_dst + i) < (size - 1))
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}

/* int  main(void)
{
	char		dst1[30] = "Brave new ";
	const char	*src1 = "World!";
	size_t		result1;
	char		dst2[8] = "In a ";
	const char	*src2 = "brave new world";
	size_t		result2;
	char		dst3[8] = "In a ";
	const char	*src3 = "brave new world";
	size_t		result3;
	char		dst4[5] = "42 ";
	const char	*src4 = "its great";
	size_t		result4;
	char		dst5[5] = "42 ";
	const char	*src5 = "its great";
	size_t		result5;
	char		dst6[10] = "Hello";
	const char	*src6 = "Test";
	size_t		result6;
	char		dst7[20] = "Hello";
	const char	*src7 = "";
	size_t		result7;
	char		dst8[20] = "";
	const char	*src8 = "Empty Destination";
	size_t		result8;

	// Case 1: Concatenate when dst has enough space for src
	//(dst tiene suficiente espacio para src)
	result1 = ft_strlcat(dst1, src1, sizeof(dst1));
	printf("Case 1: Concatenate when dst has enough space for src\n");
	printf("Result: %zu, Destination: '%s'\n\n", result1, dst1);
	// Case 2: Concatenate when dst does not have enough space for src
	//(truncation)
	//(dst no tiene suficiente espacio para src (truncamiento)
	result2 = ft_strlcat(dst2, src2, sizeof(dst2));
	printf("Case 2 ft_strlcat: Concatenate dst not have enough space for src\n");
	printf("Result: %zu, Destination: '%s'\n\n", result2, dst2);
	// Case 2: Concatenate when dst does not have enough space for src
	//(truncation)
	//(dst no tiene suficiente espacio para src (truncamiento)
	result3 = strlcat(dst3, src3, sizeof(dst3));
	printf("Case 2 strlcat': Concate when dst not have enough space for src\n");
	printf("Result: %zu, Destination: '%s'\n\n", result3, dst3);
	// Case 3: dstsize is less than or equal to the length of dst
	//(dstsize es menor o igual a la longitud de dst)
	result4 = ft_strlcat(dst4, src4, sizeof(dst4));
	printf("Case 3 ft_strlcat': dstsize is less than or equal to size of dst\n");
	printf("Result: %zu, Destination: '%s'\n\n", result4, dst4);
	// Case 3: dstsize is less than or equal to the length of dst
	//(dstsize es menor o igual a la longitud de dst)
	result5 = strlcat(dst5, src5, sizeof(dst5));
	printf("Case 3 strlcat': dstsize is less than or equal to size of dst\n");
	printf("Result: %zu, Destination: '%s'\n\n", result5, dst5);
	// Case 4: `dstsize` = 0
	result6 = ft_strlcat(dst6, src6, 0);
	printf("Case 4: dstsize = 0\n");
	printf("Result: %zu, Destination: '%s'\n\n", result6, dst6);
	// Case 5: src = empty
	result7 = ft_strlcat(dst7, src7, sizeof(dst7));
	printf("Case 5: src empty\n");
	printf("Result: %zu, Destination: '%s'\n\n", result7, dst7);
	// Case 6: dst = empty
	result8 = ft_strlcat(dst8, src8, sizeof(dst8));
	printf("Case 5: dst empty\n");
	printf("Result: %zu, Destination: '%s'\n\n", result8, dst8);
	return (0);
}
 */