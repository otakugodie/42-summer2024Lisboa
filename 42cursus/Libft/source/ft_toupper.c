/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:38:43 by diegfern          #+#    #+#             */
/*   Updated: 2024/11/13 18:30:48 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c -= ' ');
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
	printf("Original: %c, Upper: %c\n", char1, ft_toupper(char1));
	printf("Original: %c, Upper: %c\n", char2, ft_toupper(char2));
	printf("Original: %c, Upper: %c\n", char3, ft_toupper(char3));
	printf("Original: %c, Upper: %c\n", char4, ft_toupper(char4));
	return (0);
}
 */