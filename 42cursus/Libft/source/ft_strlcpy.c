/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 17:02:13 by diegfern          #+#    #+#             */
/*   Updated: 2024/11/03 17:03:44 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	size_src;
	int		i;

	size_src = ft_strlen((char *)src);
	i = 0;
	if (!src)
		return (0);
	if (size == 0)
	{
		return (size_src);
	}
	while (i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen((char *)src));
	/*
	if (size > (size_src+1)){
		ft_memcpy(dst, src, (size_src+1));
	}
	*/
	/* get the length of src */
	/* check if dstsize is big enough to accomodate src length plus the NUL character
		*/
	/* copy the whole src into dst */
	/* else */
	/* copy dstsize - 1 characters into dst */
}

int	main(void)
{
	char dest[20];
	const char *src = "Hello, World!";

	// Caso 1: Copiar una cadena que cabe en el destino
	size_t result1 = ft_strlcpy(dest, src, sizeof(dest));
	printf("Caso 1: Copiar cadena completa\n");
	printf("Resultado: %zu, Destino: '%s'\n\n", result1, dest);

	// Caso 2: Copiar una cadena que excede el tamaño del destino
	char dest2[10];
	size_t result2 = ft_strlcpy(dest2, src, sizeof(dest2));
	printf("Caso 2: Copiar cadena truncada\n");
	printf("Resultado: %zu, Destino: '%s'\n\n", result2, dest2);

	// Caso 3: Copiar a un destino de tamaño 0
	char dest3[1]; // Cambiar a tamaño 1 para evitar comportamiento indefinido
	size_t result3 = ft_strlcpy(dest3, src, 0);
	printf("Caso 3: Copiar a tamaño 0\n");
	printf("Resultado: %zu\n\n", result3);

	// Caso 4: Cadena fuente vacía
	char dest4[20];
	const char *src_empty = "";
	size_t result4 = ft_strlcpy(dest4, src_empty, sizeof(dest4));
	printf("Caso 4: Copiar cadena vacía\n");
	printf("Resultado: %zu, Destino: '%s'\n\n", result4, dest4);

	// Caso 5: Cadena fuente igual al destino
	char dest5[20];
	size_t result5 = ft_strlcpy(dest5, dest, sizeof(dest5));
	printf("Caso 5: Copiar cadena igual a destino\n");
	printf("Resultado: %zu, Destino: '%s'\n\n", result5, dest5);

	// Caso 6: Cadena fuente menor al destino
	char dest6[30];
	size_t result6 = ft_strlcpy(dest6, "Short", sizeof(dest6));
	printf("Caso 6: Copiar cadena menor a destino\n");
	printf("Resultado: %zu, Destino: '%s'\n\n", result6, dest6);

	return (0);
}