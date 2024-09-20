/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otakugodie <otakugodie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:18:57 by otakugodie        #+#    #+#             */
/*   Updated: 2024/09/19 09:27:42 by otakugodie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	letter;

	letter = 'z';    
	while (letter >= 'a')
	{
		write(1, &letter, 1);
		letter = letter - 1;
	}
}

int	main(void)
{
	ft_print_reverse_alphabet();
    
	return (0);
}