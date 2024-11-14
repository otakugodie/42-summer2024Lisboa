/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:41:00 by diegfern          #+#    #+#             */
/*   Updated: 2024/11/13 19:59:11 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		else
			i++;
	}
	if ((unsigned char)c == '\0' && s[i] == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

/* int	main(void)
{
	const char	word[] = "42 Lisboa in Portugal";
	char		c_find1;
	char		c_find2;
	char		c_find3;

	c_find1 = 'a';
	c_find2 = 'z';
	c_find3 = '\0';
	printf("Char %c find in: '%s'\n", (char)c_find1, ft_strchr(word, c_find1));
	printf("Char %c find in: '%s'\n", (char)c_find2, ft_strchr(word, c_find2));
	printf("Char %c find in: '%s'\n", (char)c_find3, ft_strchr(word, c_find3));
	return (0);
}
 */