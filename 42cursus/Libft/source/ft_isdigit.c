/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:45:58 by diegfern          #+#    #+#             */
/*   Updated: 2024/10/29 23:03:46 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/* #include <stdio.h>

int	main(void)
{
	printf("9 is digit?: %d\n", ft_isdigit('9'));
	printf("* is digit?: %d\n", ft_isdigit('*'));
	printf("$ is digit?: %d\n", ft_isdigit('$'));
	return (0);
}
 */