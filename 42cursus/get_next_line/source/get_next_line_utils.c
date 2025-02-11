/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:08:36 by diegfern          #+#    #+#             */
/*   Updated: 2025/02/01 08:42:07 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	i;

	i = 0;
	dst = malloc(ft_strlen(s) + 1);
	if (!dst)
		return (NULL);
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_join;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	s_join = malloc((sizeof(char)) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s_join)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s_join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s_join[i + j] = s2[j];
		j++;
	}
	s_join[i + j] = '\0';
	return (s_join);
}

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (str == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}
