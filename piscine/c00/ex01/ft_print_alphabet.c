/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otakugodie <otakugodie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:17:12 by otakugodie        #+#    #+#             */
/*   Updated: 2024/09/19 09:14:36 by otakugodie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(char element)
{
	write(1, &element, 1);
}

int	main(void)
{
	char	letter;

	letter = 'a';
	while (letter <= 'z')
	{
		ft_print_alphabet(letter);
		letter = letter + 1;
	}
	return (0);
}
