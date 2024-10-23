/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 23:39:00 by diegfern          #+#    #+#             */
/*   Updated: 2024/10/23 23:52:31 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	value;

	value = 1;
	if (nb > 1)
	{
		while (value < nb)
		{
			if ((value * value) == nb)
			{
				return (value);
			}
			value++;
		}
		return (0);
	}
	else
	{
		return (0);
	}
}

/* #include <stdio.h>

int	main(void)
{
	int	number;

	number = 64;
	printf("Square root of %d is: %d\n", number, ft_sqrt(number));
	return (0);
}
 */