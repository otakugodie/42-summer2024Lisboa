/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:16:08 by diegfern          #+#    #+#             */
/*   Updated: 2024/10/22 19:41:03 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char letter)
{
	write(1, &letter, 1);
}

void	ft_print_numbers(void)
{
	char	digit;

	digit = '0';
	while (digit != ':')
	{
		ft_putchar(digit);
		digit++;
	}
}

/* int	main(void)
{
	ft_print_numbers();
	return (0);
}
 */