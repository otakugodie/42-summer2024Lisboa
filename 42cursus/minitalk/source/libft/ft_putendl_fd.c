/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:34:27 by diegfern          #+#    #+#             */
/*   Updated: 2025/02/02 19:22:20 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
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
	write(fd, "\n", 1);
}

/* int	main(void)
{
	char	long_str[] = "A long string that exceeds the usual
	length, to test large output handling.";
	ft_putendl_fd("Hello, World!", 1);
	ft_putendl_fd("", 1); // No debe imprimir nada en la pantalla
	ft_putendl_fd("Hello, world!\nThis is a test.\t\t\tTab!", 1);
	ft_putendl_fd("This is an error message.", 2);
	// Esperado: "This is an error message." en STDERR
	// Pasamos una cadena larga a ft_putstr_fd
	ft_putendl_fd(long_str, 1); // Esperado: imprimir la cadena en la pantalla
	return (0);
}
 */