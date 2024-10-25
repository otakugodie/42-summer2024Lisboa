/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otakugodie <otakugodie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 23:40:56 by otakugodie        #+#    #+#             */
/*   Updated: 2024/09/20 01:19:27 by otakugodie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '1';
	b = '2';
	c = '3';
	for (a = '0'; a <= '9'; a++)
	{
		for (b = a + 1; b <= '9'; b++)
		{
			for (c = b + 1; c <= '9'; c++)
			{
				write(1, &a, 1);
				write(1, &b, 1);
				write(1, &c, 1);
				if (!(c == '9' && b == '8' && a == '7'))
				{
					write(1, ", ", 2);
				}
			}
			c = b + 1;
		}
		b = a + 1;
	}
}

int	main(void)
{
	ft_print_comb();
	return (0);
}
