/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:37:10 by diegfern          #+#    #+#             */
/*   Updated: 2024/09/26 12:10:23 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos] != '\0')
	{
		if (str[pos] >= 'A' && str[pos] <= 'Z')
		{
			str[pos] += 32;
		}
		pos++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	pos;
	int	is_first_letter;

	pos = 0;
	is_first_letter = 1;
	ft_strlowcase(str);
	while (str[pos] != '\0')
	{
		if ((str[pos] >= 'a' && str[pos] <= 'z'))
		{
			if (is_first_letter == 1)
			{
				str[pos] -= 32;
				is_first_letter = 0;
			}
		}
		else if (str[pos] >= '0' && str[pos] <= '9')
		{
			is_first_letter = 0;
		}
		else
		{
			is_first_letter = 1;
		}
		/*
		else if ( ( str[pos]>=32 && str[pos]<=47 ) || ( str[pos]>=58
				&& str[pos]<=64 ) || ( str[pos]>=91 && str[pos]<=96 )
			|| ( str[pos]>=123 && str[pos]<=126 )  ){
			is_first_letter = 1;
		}
		*/
		pos++;
	}
	return (str);
}

#include <stdio.h>

int	main(void)
{
	char	str[] = "once upon a time in a faraway kingdom";
	char	str3[] = "I am a T-800 Exterminator model 101 manufactured by cyberdyne_systems and I was sent in the year 2029";

	char str2[] = "I mean,
		why not just use Vim over emacs
		? i do use Vim over Emac.";
			char str4[] = "salut,
		comment tu vas
		? 42mots quarante - deux;
	cinquante + et +
		un ";
		// Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un
		printf("%s\n", ft_strcapitalize(str));
	printf("%s\n", ft_strcapitalize(str2));
	printf("%s\n", ft_strcapitalize(str3));
	printf("%s\n", ft_strcapitalize(str4));
	return (0);
}
