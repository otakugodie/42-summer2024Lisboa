/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:36:25 by diegfern          #+#    #+#             */
/*   Updated: 2025/02/02 19:22:08 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
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
	printf("H is alpha?: %d\n", ft_isalpha('H'));
	printf("* is alpha?: %d\n", ft_isalpha('*'));
	printf("- is alpha?: %d\n", ft_isalpha('-'));
	return (0);
}
 */