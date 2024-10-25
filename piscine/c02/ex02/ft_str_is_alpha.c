/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 00:12:33 by diegfern          #+#    #+#             */
/*   Updated: 2024/09/26 12:10:03 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	pos;

	pos = 0;
	if (str[0] == '\0')
	{
		return (1);
	}
	while (str[pos] != '\0')
	{
		if ((str[pos] >= 'A' && str[pos] <= 'Z') || (str[pos] >= 'a'
				&& str[pos] <= 'z'))
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
	printf("abcdefghijkl= %d\n", ft_str_is_alpha("zyxwvutsr"));
	printf("BCZHDFGKLTFV= %d\n", ft_str_is_alpha("BCZHDFGKLTFV"));
	printf("abc1defghijkl= %d\n", ft_str_is_alpha("abcdefgh42ijkl"));
	printf("AZCGc1defghijkl= %d\n", ft_str_is_alpha("ZALHFCc1descgverjkl"));
	printf("-_134556efghij67= %d\n", ft_str_is_alpha("_12345e#fghij6-7"));
	printf("%d\n", ft_str_is_alpha(""));
	return (0);
}
