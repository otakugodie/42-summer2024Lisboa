/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:41:35 by diegfern          #+#    #+#             */
/*   Updated: 2024/09/23 21:39:22 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	if (*str)
	{
		while (*str != '\0')
		{
			write(1, str, 1);
			str++;
		}
	}
}
/*
#include <stdio.h>

int	main(void)
{
	char	*str;

	str = "Hello world";
	ft_putstr(str);
	return (0);
}
*/