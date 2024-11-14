/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 22:48:33 by diegfern          #+#    #+#             */
/*   Updated: 2024/11/13 18:29:02 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

/* int	main(void)
{
	char	str[50] = "This is bzero function";
	int	i;

	printf("String is: %s\n", str);
	ft_bzero(str, 5);
	printf("String after bzero is: ");

	i = 0;
	while (i < 50){
		printf("%c", str[i]);
		i++;
	}
	printf("\n");

	return (0);
}
 */