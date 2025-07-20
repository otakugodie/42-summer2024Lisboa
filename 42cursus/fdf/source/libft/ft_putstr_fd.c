/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:11:51 by diegfern          #+#    #+#             */
/*   Updated: 2024/11/17 16:31:16 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	pos;

	if (!s)
		return ;
	pos = 0;
	while (s[pos] != '\0')
	{
		write(fd, &s[pos], 1);
		pos++;
	}
}

/* int	main(void)
{
	char	long_str[] = "A long string that exceeds the usual length,
			to test large output handling.\n";

	ft_putstr_fd("Hello, World!\n", 1);
	ft_putstr_fd("", 1); // No debe imprimir nada en la pantalla
	ft_putstr_fd("Hello, world!\nThis is a test.\t\t\tTab!\n", 1);
	ft_putstr_fd("This is an error message.\n", 2);
	// Esperado: "This is an error message." en STDERR
	// Pasamos una cadena larga a ft_putstr_fd
	ft_putstr_fd(long_str, 1); // Esperado: imprimir la cadena en la pantalla
	return (0);
}
 */