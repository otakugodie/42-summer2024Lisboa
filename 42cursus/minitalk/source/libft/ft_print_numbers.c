/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:28:35 by diegfern          #+#    #+#             */
/*   Updated: 2025/02/07 19:23:17 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_num(long int n, long int *counter)
{
	if (n < 0)
	{
		ft_print_char('-', counter);
		n *= (-1);
	}
	if (n >= 10)
		ft_print_num((n / 10), counter);
	ft_print_char((n % 10) + '0', counter);
}

void	ft_print_hex_upper(unsigned long int n, long int *counter)
{
	if (n >= 16)
		ft_print_hex_upper(n / 16, counter);
	ft_print_char("0123456789ABCDEF"[n % 16], counter);
}

void	ft_print_hex_lower(unsigned long int n, long int *counter)
{
	if (n >= 16)
		ft_print_hex_lower(n / 16, counter);
	ft_print_char("0123456789abcdef"[n % 16], counter);
}
