/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:02:39 by diegfern          #+#    #+#             */
/*   Updated: 2024/10/28 22:15:02 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
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
	printf("H is ascii?: %d\n", ft_isascii('H'));
	printf("$ is ascii?: %d\n", ft_isascii('$'));
	printf("9 is ascii?: %d\n", ft_isascii('9'));	
	printf("-1 is ascii?: %d\n", ft_isascii(-1));
	printf("128 is ascii?: %d\n", ft_isascii(128));
	return (0);
}
 */