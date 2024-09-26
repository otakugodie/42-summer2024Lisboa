/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 08:47:32 by diegfern          #+#    #+#             */
/*   Updated: 2024/09/26 09:09:27 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	pos;

	pos = 0;
	if (str[0] == '\0')
	{
		return (1);
	}
	while (str[pos] != '\0')
	{
		if (str[pos] >= '0' && str[pos] <= '9')
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
	printf("1984202442= %d\n", ft_str_is_numeric("1984202442"));
	printf("19r84202t442= %d\n", ft_str_is_numeric("19r84202t442"));
	printf("1234-56efghij67_= %d\n", ft_str_is_numeric("1234-56efghij67_"));
	printf("@&$@12342= %d\n", ft_str_is_numeric("@&$@12342"));
	printf("%d\n", ft_str_is_numeric(""));

	return (0);
}
