/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:06:30 by diegfern          #+#    #+#             */
/*   Updated: 2024/09/26 14:05:14 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	pos;

	pos = 0;
	while ((s1[pos] != '\0' || s2[pos] != '\0') && pos < n)
	{
		if (s1[pos] > s2[pos])
		{
			return (pos);
		}
		else if (s1[pos] < s2[pos])
		{
			return (-pos);
		}
		pos++;
	}
	return (0);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("%d\n", ft_strncmp("Hello", "Hello world", 7));
    printf("%d\n", strncmp ("Hello", "Hello world", 7));
	/*
	printf("%d\n", ft_strcmp("Hello", "He"));
	printf("%d\n", ft_strcmp("He", "Hello"));
	printf("%d\n\n", ft_strcmp("Hello", "Hello"));
	*/
	printf("%d\n", ft_strncmp("Helo world", "Hello", 4));
    printf("%d\n", strncmp("Helo world", "Hello", 4));
	/*
	printf("%d\n", strcmp("Hello", "He"));
	printf("%d\n", strcmp("He", "Hello"));
	printf("%d\n", strcmp("Hello", "Hello"));
	*/
	return (0);
}
