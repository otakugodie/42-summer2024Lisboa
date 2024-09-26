/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:15:43 by diegfern          #+#    #+#             */
/*   Updated: 2024/09/26 12:10:32 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos] != '\0')
	{
		if (str[pos] >= 'A' && str[pos] <= 'Z')
		{
			str[pos] += 32;
		}
		pos++;
	}
	return (str);
}

#include <stdio.h>

int	main(void)
{
	char str[] = "BCZHDFGKLTFV";
	char str2[] = "ABCdef42ghi";
	char str3[] = "_12345E#FGhij6-7";

	printf("BCZHDFGKLTFV= %s\n", ft_strlowcase(str));
	printf("ABCdef42ghi= %s\n", ft_strlowcase(str2));
	printf("_12345E#FGhij6-7= %s\n", ft_strlowcase(str3));

	return (0);
}