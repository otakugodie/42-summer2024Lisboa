/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:39:31 by diegfern          #+#    #+#             */
/*   Updated: 2025/02/02 19:22:40 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c += ' ');
	else
		return (c);
}

/* int  main(void)
{
	char	char1;
	char	char2;
	char	char3;
	char	char4;

	char1 = 'z';
	char2 = 'A';
	char3 = '1';
	char4 = '<';
	printf("Original: %c, Lower: %c\n", char1, ft_tolower(char1));
	printf("Original: %c, Lower: %c\n", char2, ft_tolower(char2));
	printf("Original: %c, Lower: %c\n", char3, ft_tolower(char3));
	printf("Original: %c, Lower: %c\n", char4, ft_tolower(char4));
	return (0);
}
 */