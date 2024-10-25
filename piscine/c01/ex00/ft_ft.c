/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:17:24 by otakugodie        #+#    #+#             */
/*   Updated: 2024/09/23 11:54:48 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

int	main(void)
{
	int	school;
	int	*nbr;

	school = 0;
	nbr = &school;
	ft_ft(nbr);
	return (0);
}
