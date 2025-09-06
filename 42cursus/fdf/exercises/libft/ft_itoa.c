/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:46:18 by diegfern          #+#    #+#             */
/*   Updated: 2024/11/16 21:12:11 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_number(long nbr)
{
	int	digits;

	digits = 0;
	if (nbr <= 0)
		digits++;
	while (nbr != 0)
	{
		nbr /= 10;
		digits++;
	}
	return (digits);
}

static void	create_str(char *str, int len, long nbr)
{
	int	is_negative;

	is_negative = 0;
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
		is_negative = 1;
	}
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		if (is_negative && len == 0)
			break ;
		str[len] = (nbr % 10) + '0';
		nbr /= 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	long	nbr;
	int		len;
	char	*str;

	nbr = n;
	len = len_number(nbr);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	create_str(str, len, nbr);
	return (str);
}

/* int	main(void)
{
	printf("Itoa -2147483647: %s\n", ft_itoa(-2147483647));
	printf("Itoa -2147483648: %s\n", ft_itoa(-2147483648));
	printf("Itoa -42: %s\n", ft_itoa(-42));
	printf("Itoa 0: %s\n", ft_itoa(0));
	printf("Itoa 42: %s\n", ft_itoa(42));
	printf("Itoa 2147483647: %s\n", ft_itoa(2147483647));
	return (0);
}
 */