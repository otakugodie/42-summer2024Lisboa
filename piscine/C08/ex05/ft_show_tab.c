/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 01:33:27 by diegfern          #+#    #+#             */
/*   Updated: 2024/10/10 10:30:27 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	if (*str)
	{
		while (*str != '\0')
		{
			write(1, str, 1);
			str++;
		}
	}
}

void	ft_putnbr(int nb)
{
	int	is_min;

	is_min = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			nb = nb + 1;
			is_min = 1;
		}
		nb = nb * (-1);
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
	}
	if (is_min && nb % 10 == 7)
	{
		ft_putchar((nb % 10) + '1');
	}
	else
	{
		ft_putchar((nb % 10) + '0');
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	index;

	index = 0;
	while (par[index].str != 0)
	{
		ft_putstr(par[index].str);
		ft_putstr("\n");
		ft_putnbr(par[index].size);
		ft_putstr("\n");
		ft_putstr(par[index].copy);
		ft_putstr("\n");
		index++;
	}
}

/* int	main(int argc, char **argv)
{
	ft_show_tab(ft_strs_to_tab(argc, argv));
} */
