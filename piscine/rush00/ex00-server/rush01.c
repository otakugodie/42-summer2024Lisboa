/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaludzy <dpaludzy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:14:43 by dfilipe-          #+#    #+#             */
/*   Updated: 2024/09/22 21:23:51 by jluiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rushfirsline(int col)
{
	int	coluna;

	ft_putchar('/');
	if (col != 1)
	{
		coluna = 2;
		while (coluna < col)
		{
			ft_putchar ('*');
			coluna++;
		}
		ft_putchar ('\\');
	}
}

void	rushblines(int n1, int n2)
{
	int	linha;
	int	coluna;

	linha = 2;
	while (linha < n2)
	{
		write(1, "\n", 1);
		ft_putchar ('*');
		coluna = 2;
		if (n1 != 1)
		{
			while (coluna < n1)
			{
				write(1, " ", 1);
				coluna++;
			}
			ft_putchar('*');
		}
		linha++;
	}
}

void	rushlastline(int n1, int n2)
{
	int	coluna;

	if (n2 != 1)
	{
		write(1, "\n", 1);
		ft_putchar('\\');
		coluna = 2;
		while (coluna < n1)
		{
			ft_putchar('*');
			coluna++;
		}
		if (n1 != 1)
			ft_putchar('/');
	}
}

void	rush(int numero1, int numero2)
{
	if (numero1 < 1 || numero2 < 1)
	{
		write(1, "os parametros estao incorretos", 30);
	}
	else
	{
		rushfirsline(numero1);
		rushblines(numero1, numero2);
		rushlastline(numero1, numero2);
	}
}
