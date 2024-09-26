/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:03:24 by diegfern          #+#    #+#             */
/*   Updated: 2024/09/26 09:10:49 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	pos;

	pos = 0;
	if (str[0] == '\0')
	{
		return (1);
	}
	while (str[pos] != '\0')
	{
		if (str[pos] >= 'a' && str[pos] <= 'z')
		{
			pos++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

#include <stdio.h>

int	main(void)
{
	printf("abcdefghijkl= %d\n", ft_str_is_lowercase("zyxwvutsr"));
	printf("BCZHDFGKLTFV= %d\n", ft_str_is_lowercase("BCZHDFGKLTFV"));
	printf("abc1defghijkl= %d\n", ft_str_is_lowercase("abcdefgh42ijkl"));
	printf("AZCGc1defghijkl= %d\n", ft_str_is_lowercase("ZALHFCc1descgverjkl"));
	printf("-_134556efghij67= %d\n", ft_str_is_lowercase("_12345e#fghij6-7"));
	printf("%d\n", ft_str_is_lowercase(""));

	return (0);
}
