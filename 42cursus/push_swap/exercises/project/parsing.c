/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:30:00 by diegfern          #+#    #+#             */
/*   Updated: 2025/09/20 17:14:39 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Cuenta las palabras en una cadena separadas por espacios
** Retorna el número de palabras
*/
static int	count_words(const char *str)
{
	int	count;
	int	in_word;
	int	i;

	count = 0;
	in_word = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if ((str[i] == ' ' || str[i] == '\t') && in_word)
			in_word = 0;
		i++;
	}
	return (count);
}

/*
** Obtiene la longitud de la siguiente palabra
** Retorna la longitud de la palabra
*/
static int	get_word_len(const char *str, int start)
{
	int	len;

	len = 0;
	while (str[start + len] && str[start + len] != ' '
		&& str[start + len] != '\t')
		len++;
	return (len);
}

/*
** Extrae una palabra de la cadena
** Retorna la palabra extraída o NULL si hay error
*/
static char	*extract_word(const char *str, int start, int len)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

/*
** Procesa una palabra en la cadena y la agrega al resultado
** Retorna 1 si fue exitoso, 0 si hay error
*/
static int	process_word(const char *str, char **result, int *i, int *j)
{
	int	start;

	while (str[*i] && (str[*i] == ' ' || str[*i] == '\t'))
		(*i)++;
	start = *i;
	result[*j] = extract_word(str, start, get_word_len(str, start));
	if (!result[*j])
		return (0);
	while (str[*i] && str[*i] != ' ' && str[*i] != '\t')
		(*i)++;
	(*j)++;
	return (1);
}

/*
** Divide una cadena en palabras separadas por espacios
** Retorna un array de strings o NULL si hay error
*/
char	**ft_split_args(const char *str)
{
	char	**result;
	int		words;
	int		i;
	int		j;

	words = count_words(str);
	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && j < words)
	{
		if (!process_word(str, result, &i, &j))
			return (free_split_result(result, j));
	}
	result[j] = NULL;
	return (result);
}
