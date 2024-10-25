/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:41:10 by diegfern          #+#    #+#             */
/*   Updated: 2024/09/22 20:30:37 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rushfirsline(int col)
{
	int	column;

	ft_putchar('A');
	if (col != 1)
	{
		column = 2;
		while (column < col)
		{
			ft_putchar('B');
			column++;
		}
		ft_putchar('C');
	}
}

void	rushblines(int n1, int n2)
{
	int	row;
	int	column;

	row = 2;
	while (row < n2)
	{
		write(1, "\n", 1);
		ft_putchar('B');
		column = 2;
		if (n1 != 1)
		{
			while (column < n1)
			{
				write(1, " ", 1);
				column++;
			}
			ft_putchar('B');
		}
		row++;
	}
}

void	rushlastline(int n1, int n2)
{
	int	column;

	if (n2 != 1)
	{
		ft_putchar('\n');
		ft_putchar('C');
		column = 2;
		while (column < n1)
		{
			ft_putchar('B');
			column++;
		}
		if (n1 != 1)
			ft_putchar('A');   
	}
    ft_putchar('\n');
}

void	rush(int x, int y)
{
	if (x < 1 || y < 1)
	{
		write(1, "os parametros estao incorretos\n", 31);
	}
	else
	{
		rushfirsline(x);
		rushblines(x, y);
		rushlastline(x, y);
	}
}
