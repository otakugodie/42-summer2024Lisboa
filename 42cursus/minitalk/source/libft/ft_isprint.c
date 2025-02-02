/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:16:15 by diegfern          #+#    #+#             */
/*   Updated: 2025/02/02 19:22:11 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
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
	printf("H is print?: %d\n", ft_isprint('H'));
	printf("$ is print?: %d\n", ft_isprint('$'));
	printf("9 is print?: %d\n", ft_isprint('9'));
	printf("tab is print?: %d\n", ft_isprint('\t'));
	printf("new line is print?: %d\n", ft_isprint('\n'));
	return (0);
}
 */