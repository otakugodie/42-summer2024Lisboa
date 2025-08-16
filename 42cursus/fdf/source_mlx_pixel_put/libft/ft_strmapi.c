/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 23:22:36 by diegfern          #+#    #+#             */
/*   Updated: 2024/11/17 15:39:23 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_s;

	if (!s || !f)
		return (NULL);
	new_s = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!new_s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_s[i] = f(i, s[i]);
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

/* static char	ft_upper(unsigned int i, char digit)
{
	if (i % 2 == 0 && (digit >= 'a' && digit <= 'z'))
		return ((digit -= ' '));
	return (digit);
}

static char	ft_lower(unsigned int i, char digit)
{
	if (i % 2 == 0 && (digit >= 'A' && digit <= 'Z'))
		return ((digit += ' '));
	return (digit);
}

int	main(void)
{
	char	*transform;

	transform = ft_strmapi("Hi, Lisboa!, from 42", ft_upper);
	if (transform)
	{
		printf("Transformation: %s\n", transform);
		free(transform);
	}
	transform = ft_strmapi("Hi, 42 Lisboa!, from 42", ft_lower);
	if (transform)
	{
		printf("Transformation: %s\n", transform);
		free(transform);
	}
	return (0);
}
 */