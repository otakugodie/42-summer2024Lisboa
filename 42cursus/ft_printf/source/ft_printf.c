/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:23:17 by diegfern          #+#    #+#             */
/*   Updated: 2024/12/05 17:41:46 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(char c, long int *counter)
{
	write(1, &c, 1);
	(*counter)++;
}

void	ft_print_str(char *str, long int *counter)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_print_str("(null)", counter);
		return ;
	}
	while (str[i])
	{
		ft_print_char(str[i], counter);
		i++;
	}
}

void	ft_print_ptr(void *ptr, long int *counter)
{
	if (!ptr)
	{
		ft_print_str("(nil)", counter);
		return ;
	}
	ft_print_str("0x", counter);
	ft_print_hex_lower((unsigned long)ptr, counter);
}

void	ft_parser_args(char type_arg, va_list *ap, long int *counter)
{
	if (type_arg == 'c')
		ft_print_char(va_arg(*ap, int), counter);
	if (type_arg == 's')
		ft_print_str(va_arg(*ap, char *), counter);
	if (type_arg == 'd' || type_arg == 'i')
		ft_print_num(va_arg(*ap, int), counter);
	if (type_arg == 'u')
		ft_print_num(va_arg(*ap, unsigned int), counter);
	if (type_arg == 'X')
		ft_print_hex_upper(va_arg(*ap, unsigned int), counter);
	if (type_arg == 'x')
		ft_print_hex_lower(va_arg(*ap, unsigned int), counter);
	if (type_arg == '%')
		ft_print_char('%', counter);
	if (type_arg == 'p')
		ft_print_ptr(va_arg(*ap, void *), counter);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	long int	counter;
	va_list		ap;

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
			ft_parser_args(str[i], &ap, &counter);
		}
		else
		{
			ft_print_char(str[i], &counter);
		}
		i++;
	}
	return ((int)counter);
}

/*int	main(void)
{
	int		ft_ret, std_ret;
	char	c = 'A';
	char	*str = "Hello, 42!";
	void	*ptr = (void *)0x12345678;
	int		decimal = -42;
	int		integer = 2147483647;
	unsigned int uint = 4294967295;
	int		hex_lower = 305419896; // 0x12345678
	int		hex_upper = 305419896; // 0x12345678

	printf("===== NORMAL TESTING =====\n");

	printf("===== TESTING ft_printf vs printf =====\n");

	// Test %c
	printf("\nTesting %%c:\n");
	std_ret = printf("printf:    [%c]\n", c);
	ft_ret = ft_printf("ft_printf: [%c]\n", c);
	printf("Return values: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

	// Test %s
	printf("\nTesting %%s:\n");
	std_ret = printf("printf:    [%s]\n", str);
	ft_ret = ft_printf("ft_printf: [%s]\n", str);
	printf("Return values: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

	// Test %p
	printf("\nTesting %%p:\n");
	std_ret = printf("printf:    [%p]\n", ptr);
	ft_ret = ft_printf("ft_printf: [%p]\n", ptr);
	printf("Return values: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

	// Test %d
	printf("\nTesting %%d:\n");
	std_ret = printf("printf:    [%d]\n", decimal);
	ft_ret = ft_printf("ft_printf: [%d]\n", decimal);
	printf("Return values: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

	// Test %i
	printf("\nTesting %%i:\n");
	std_ret = printf("printf:    [%i]\n", integer);
	ft_ret = ft_printf("ft_printf: [%i]\n", integer);
	printf("Return values: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

	// Test %u
	printf("\nTesting %%u:\n");
	std_ret = printf("printf:    [%u]\n", uint);
	ft_ret = ft_printf("ft_printf: [%u]\n", uint);
	printf("Return values: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

	// Test %x
	printf("\nTesting %%x:\n");
	std_ret = printf("printf:    [%x]\n", hex_lower);
	ft_ret = ft_printf("ft_printf: [%x]\n", hex_lower);
	printf("Return values: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

	// Test %X
	printf("\nTesting %%X:\n");
	std_ret = printf("printf:    [%X]\n", hex_upper);
	ft_ret = ft_printf("ft_printf: [%X]\n", hex_upper);
	printf("Return values: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

	// Test %%
	printf("\nTesting %%%%:\n");
	std_ret = printf("printf:    [%%]\n");
	ft_ret = ft_printf("ft_printf: [%%]\n");
	printf("Return values: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

	printf("\n\n\n===== EDGE CASES TESTING =====\n");

	int		ft_ret, std_ret;
	char	c = '\0'; // Null character
	char	*empty_str = ""; // Empty string
	char	*null_str = NULL; // Null string
	void	*null_ptr = NULL; // Null pointer
	void	*valid_ptr = (void *)0xABCDEF;
	int		min_int = -2147483648; // Minimum int
	int		max_int = 2147483647;  // Maximum int
	unsigned int uint_zero = 0;    // Unsigned zero
	unsigned int uint_max = 4294967295; // Max unsigned int
	int		zero = 0;

	printf("===== TESTING ft_printf vs printf =====\n");

	// Test %c with null character
	printf("\nTesting %%c with null character:\n");
	std_ret = printf("printf:    [%c]\n", c);
	ft_ret = ft_printf("ft_printf: [%c]\n", c);
	printf("Return values: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

	// Test %s with empty string
	printf("\nTesting %%s with empty string:\n");
	std_ret = printf("printf:    [%s]\n", empty_str);
	ft_ret = ft_printf("ft_printf: [%s]\n", empty_str);
	printf("Return values: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

	// Test %s with null string
	printf("\nTesting %%s with null string:\n");
	std_ret = printf("printf:    [%s]\n", null_str);
	ft_ret = ft_printf("ft_printf: [%s]\n", null_str);
	printf("Return values: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

	// Test %p with null pointer
	printf("\nTesting %%p with null pointer:\n");
	std_ret = printf("printf:    [%p]\n", null_ptr);
	ft_ret = ft_printf("ft_printf: [%p]\n", null_ptr);
	printf("Return values: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

	// Test %p with valid pointer
	printf("\nTesting %%p with valid pointer:\n");
	std_ret = printf("printf:    [%p]\n", valid_ptr);
	ft_ret = ft_printf("ft_printf: [%p]\n", valid_ptr);
	printf("Return values: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

	// Test %d with minimum integer
	printf("\nTesting %%d with minimum integer:\n");
	std_ret = printf("printf:    [%d]\n", min_int);
	ft_ret = ft_printf("ft_printf: [%d]\n", min_int);
	printf("Return values: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

	// Test %d with maximum integer
	printf("\nTesting %%d with maximum integer:\n");
	std_ret = printf("printf:    [%d]\n", max_int);
	ft_ret = ft_printf("ft_printf: [%d]\n", max_int);
	printf("Return values: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

	// Test %u with zero
	printf("\nTesting %%u with zero:\n");
	std_ret = printf("printf:    [%u]\n", uint_zero);
	ft_ret = ft_printf("ft_printf: [%u]\n", uint_zero);
	printf("Return values: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

	// Test %u with maximum unsigned int
	printf("\nTesting %%u with maximum unsigned int:\n");
	std_ret = printf("printf:    [%u]\n", uint_max);
	ft_ret = ft_printf("ft_printf: [%u]\n", uint_max);
	printf("Return values: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

	// Test %x with zero
	printf("\nTesting %%x with zero:\n");
	std_ret = printf("printf:    [%x]\n", zero);
	ft_ret = ft_printf("ft_printf: [%x]\n", zero);
	printf("Return values: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

	// Test %X with zero
	printf("\nTesting %%X with zero:\n");
	std_ret = printf("printf:    [%X]\n", zero);
	ft_ret = ft_printf("ft_printf: [%X]\n", zero);
	printf("Return values: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

	// Test %% with multiple %
	printf("\nTesting %%%% with multiple %%:\n");
	std_ret = printf("printf:    [%%%%%%%%]\n");
	ft_ret = ft_printf("ft_printf: [%%%%%%%%]\n");
	printf("Return values: printf = %d, ft_printf = %d\n", std_ret, ft_ret);

	return (0);
}
*/