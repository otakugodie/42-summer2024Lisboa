/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:23:17 by diegfern          #+#    #+#             */
/*   Updated: 2024/12/03 14:05:10 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_char(char c, long int *counter)
{
	write(1, &c, 1);
	(*counter)++;
}

void ft_print_str(char *str, long int *counter){
	int	i;
	i = 0;
	/*********************/
	while (str[i]){
		ft_print_char(va_arg(ap, int), counter);
		i++;
	}
	/*********************/
}

void	ft_parser_args(char type_arg, va_list ap, long int *counter)
{
	if (type_arg == 'c')
		ft_print_char(va_arg(ap, int), counter);
	if (type_arg == 's')
		ft_print_str(va_arg(ap, char *), counter);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	long int	counter;
	char		*strtemp;

	va_list ap; // ap> argument pointer
	if (!str)
		return (-1);
	i = 0;
	counter = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;			
			ft_parser_args(str[i], ap, &counter);
		}
		else
		{
			ft_print_char(str[i], &counter);			
		}
		i++;
	}
	return ((int)counter);
}

int	main(void)
{
	int		total;
	char	*str;

	//str = NULL;
	// total = sumatoria(3, 1,2,3);
	// printf ("Total: %d\n", total);
	// ft_printf ("Hello my name is %s, I am tudent in %d\n", "Diego", 42);
	//ft_printf ("__%c__\n", 'H');
	ft_printf ("__%s__\n", "Diego");
	//total = printf("Str is: %s\n", str);
	//printf("Total: %d \n", total);
	return (0);
}
