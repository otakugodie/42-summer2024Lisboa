/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 21:36:44 by diegfern          #+#    #+#             */
/*   Updated: 2024/09/23 21:51:33 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (*str)
	{
		while (*str != '\0')
		{
			str++;
			i++;
		}
	}
	return (i);
}

/*
#include <stdio.h>

int	main(void)
{
	int		size;
	char	*str;

	str = "Hello world";
	size = ft_strlen(str);
	printf("Lenght size is: %d\n", size);
	return (0);
}
*/