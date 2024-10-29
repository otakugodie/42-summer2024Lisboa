/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 21:53:16 by diegfern          #+#    #+#             */
/*   Updated: 2024/10/29 23:03:51 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
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
	printf("9 is alphanumeric?: %d\n", ft_isalnum('9'));
	printf("H is alphanumeric?: %d\n", ft_isalnum('H'));
	printf("$ is alphanumeric?: %d\n", ft_isalnum('$'));
	return (0);
}
 */