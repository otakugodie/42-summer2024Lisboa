/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:31:08 by diegfern          #+#    #+#             */
/*   Updated: 2025/02/02 19:22:35 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen((char *)s) - 1;
	if ((unsigned char)c == '\0')
		return ((char *)&s[i + 1]);
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		else
			i--;
	}
	return (NULL);
}

/* int	main(void)
{
	const char	word[] = "42 Lisboa in Portugal";
	char		c_find1;
	char		c_find2;
	char		c_find3;

	c_find1 = '2';
	c_find2 = 'z';
	c_find3 = '\0';
	printf("Char %c find in: '%s'\n", (char)c_find1, ft_strrchr(word, c_find1));
	printf("Char %c find in: '%s'\n", (char)c_find2, ft_strrchr(word, c_find2));
	printf("Char %c find in: '%s'\n", (char)c_find3, ft_strrchr(word, c_find3));
	return (0);
}
 */