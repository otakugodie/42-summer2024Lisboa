/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:19:10 by diegfern          #+#    #+#             */
/*   Updated: 2024/09/26 12:10:45 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	pos;

	pos = 0;
	if (str[0] == '\0')
	{
		return (1);
	}
	while (str[pos] != '\0')
	{
		if ((str[pos] >= 32 && str[pos] <= 126))
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
	printf("%d\n", ft_str_is_printable("ABCDEabcde?I34%0990"));
	printf("%d\n", ft_str_is_printable("\n\t\v\f"));
	return (0);
}
