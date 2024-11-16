/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:30:52 by diegfern          #+#    #+#             */
/*   Updated: 2024/11/16 18:42:43 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_array(char **array_v, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(array_v[i]);
		i++;
	}
	free(array_v);
}

static int	word_count(char const *s, char c)
{
	size_t	words;
	int		is_word;
	int		i;

	i = 0;
	words = 0;
	while (s[i])
	{
		is_word = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			if (is_word == 0)
			{
				words++;
				is_word = 1;
			}
			i++;
		}
	}
	return (words);
}

static int	fill_word(char **array_v, char const *s, char c)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			start = i;
			while (s[i] != c && s[i])
				i++;
			array_v[j] = ft_substr(s, start, (i - start));
			if (!array_v[j])
				return (free_array(array_v, j), 0);
			j++;
		}
	}
	array_v[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**array_v;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	array_v = malloc((words + 1) * sizeof(char *));
	if (!array_v)
		return (NULL);
	array_v[words] = NULL;
	if (!fill_word(array_v, s, c))
		return (NULL);
	return (array_v);
}

/* int	main(void)
{
	char	**result;

	// Test 1: String with words separated by spaces
	result = ft_split("Hello world 42", ' ');
	printf("Test 1:\n");
	for (int i = 0; result[i] != NULL; i++)
	{
		printf("Word %d: %s\n", i + 1, result[i]);
	}
	// Free memory after test
	free_array(result, 3); // 3 is the number of words in this test
	// Test 2: String with words separated by commas
	result = ft_split("apple,banana,grape,orange", ',');
	printf("\nTest 2:\n");
	for (int i = 0; result[i] != NULL; i++)
	{
		printf("Word %d: %s\n", i + 1, result[i]);
	}
	free_array(result, 4); // 4 words in this test
	// Test 3: String with spaces at the beginning and the end
	result = ft_split("   Hello    World   42   ", ' ');
	printf("\nTest 3:\n");
	for (int i = 0; result[i] != NULL; i++)
	{
		printf("Word %d: %s\n", i + 1, result[i]);
	}
	free_array(result, 3); // 3 words despite extra spaces
	// Test 4: String with a single character (no delimiter)
	result = ft_split("A", ' ');
	printf("\nTest 4:\n");
	for (int i = 0; result[i] != NULL; i++)
	{
		printf("Word %d: %s\n", i + 1, result[i]);
	}
	free_array(result, 1); // 1 word
	// Test 5: Empty string
	result = ft_split("", ' ');
	printf("\nTest 5:\n");
	if (result == NULL)
	{
		printf("Empty string: NULL\n");
	}
	else
	{
		for (int i = 0; result[i] != NULL; i++)
		{
			printf("Word %d: %s\n", i + 1, result[i]);
		}
	}
	free_array(result, 0); // 0 words
	return (0);
}
 */