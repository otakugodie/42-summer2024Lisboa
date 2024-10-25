/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:07:47 by diegfern          #+#    #+#             */
/*   Updated: 2024/09/26 09:11:00 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_str_is_uppercase(char *str)
{
	int	pos;

	pos = 0;
	if (str[0] == '\0')
	{
		return (1);
	}
	while (str[pos] != '\0')
	{
		if ( str[pos] >= 'A' && str[pos] <= 'Z' )
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
    printf("abcdefghijkl= %d\n", ft_str_is_uppercase("zyxwvutsr"));
	printf("BCZHDFGKLTFV= %d\n", ft_str_is_uppercase("BCZHDFGKLTFV"));
	printf("abc1defghijkl= %d\n", ft_str_is_uppercase("abcdefgh42ijkl"));
	printf("AZCGc1defghijkl= %d\n", ft_str_is_uppercase("ZALHFCc1descgverjkl"));
	printf("-_134556efghij67= %d\n", ft_str_is_uppercase("_12345e#fghij6-7"));
	printf("%d\n", ft_str_is_uppercase(""));

	return (0);
}
