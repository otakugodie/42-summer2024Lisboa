/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:43:21 by diegfern          #+#    #+#             */
/*   Updated: 2024/09/26 12:10:37 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos] != '\0')
	{
		if (str[pos] >= 'a' && str[pos] <= 'z')
		{
			str[pos] -= 32;
		}
		pos++;
	}
	return (str);
}

#include <stdio.h>

int	main(void)
{
	char	str[] = "abcdefghi";
	char	str2[] = "abcdef42ghi";
	char	str3[] = "_12345e#fghij6-7";

	printf("%s\n", ft_strupcase(str));
	printf("%s\n", ft_strupcase(str2));
	printf("%s\n", ft_strupcase(str3));
	return (0);
}
