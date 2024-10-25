/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:31:21 by diegfern          #+#    #+#             */
/*   Updated: 2024/10/08 14:43:34 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

int	ft_total_length(int size, char **strs, char *sep)
{
	int	total_len;
	int	sep_len;
	int	i;

	total_len = 0;
	sep_len = ft_strlen(sep);
	i = 0;
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		if (i < size - 1)
			total_len += sep_len;
		i++;
	}
	return (total_len);
}

char	*ft_empty_str(void)
{
	char	*result;

	result = (char *)malloc(1);
	if (!result)
		return (NULL);
	result[0] = '\0';
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		pos;	
	int		i;

	if (size == 0)
		return (ft_empty_str());
	result = (char *)malloc(ft_total_length(size, strs, sep) + 1);
	if (!result)
		return (NULL);
	i = 0;
	pos = 0;
	while (i < size)
	{
		ft_strcpy(result + pos, strs[i]);
		pos += ft_strlen(strs[i]);
		if (i < size - 1)
		{
			ft_strcpy(result + pos, sep);
			pos += ft_strlen(sep);
		}
		i++;
	}
	result[pos] = '\0';
	return (result);
}

/* #include <stdio.h>

int	main(void)
{
	char	*strs[] = {"Hi", "my", "Goddess", "from", "C"};
	char	*sep;
	char	*result;

	sep = " ";
	result = ft_strjoin(4, strs, sep);
	printf("%s\n", result);
	free(result);
	return (0);
}
 */