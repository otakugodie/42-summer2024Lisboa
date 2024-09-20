/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otakugodie <otakugodie@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 01:09:37 by otakugodie        #+#    #+#             */
/*   Updated: 2024/09/20 08:12:23 by otakugodie       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_prepare_print(int a, int b, int end)
{
	ft_putchar((a / 10) + '0');
	ft_putchar((a % 10) + '0');
	ft_putchar(' ');
	ft_putchar((b / 10) + '0');
	ft_putchar((b % 10) + '0');
	if (!end)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb2(void)
{
	int	first;
	int	second;
	int	end;

	first = 0;
	second = 1;
	end = 0;
	while (first <= 98 && end == 0)
	{
		while (second > first && second <= 99 && end == 0)
		{
			if (first == 98 && second == 99)
			{
				end = 1;
				ft_prepare_print(first, second, end);
				break ;
			}
			ft_prepare_print(first, second, end);
			second++;
		}
		first++;
		second = first + 1;
	}
}

int	main(void)
{
	ft_print_comb2();
	return (0);
}
