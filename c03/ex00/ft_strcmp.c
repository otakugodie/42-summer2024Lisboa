/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:45:09 by diegfern          #+#    #+#             */
/*   Updated: 2024/09/26 13:22:31 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	pos;

	pos = 0;
	while (s1[pos] == s2[pos] && (s1[pos] != '\0' || s2[pos] != '\0'))
	{
		pos++;
	}
	return (s1[pos] - s2[pos]);
}

#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_strcmp("Hello", "Hello1"));
	printf("%d\n", ft_strcmp("Hello", "He"));
	printf("%d\n", ft_strcmp("He", "Hello"));
	printf("%d\n", ft_strcmp("Hello", "Hello"));
	return (0);
}
