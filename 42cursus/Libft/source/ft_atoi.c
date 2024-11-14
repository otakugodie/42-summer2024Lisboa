/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:52:07 by diegfern          #+#    #+#             */
/*   Updated: 2024/11/13 18:28:59 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	sign;

	sign = 1;
	result = 0;
	i = 0;
	while ((nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r')) && nptr[i])
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= (-1);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i])
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

/* int  main(void)
{
	char	*string1;
	char	*string2;
	char	*string3;
	char	*string5;
	char	*string6;
	char	*string18;
	char	*string7;
	char	*string8;
	char	*string14;
	char	*string16;
	char	*string15;
	char	*string17;
	char	*string4;
	char	*string9;
	char	*string10;
	char	*string11;
	char	*string12;
	char	*string13;
	char	*string19;

	string1 = "3";
	string2 = "384";
	string3 = "42ab5";
	string5 = "+2000";
	string6 = "-2020";
	string18 = " -2020";
	string7 = "   3845";
	string8 = "   484  5";
	string14 = "2147483647";
	string16 = "2147483649";
	string15 = "-2147483648";
	string17 = "- 2020";
	string4 = "ab1984";
	string9 = "--42";
	string10 = "---42";
	string11 = "   ---42";
	string12 = " + --+-42";
	string13 = "";
	string19 = " - 2020";
	printf("ATOI C\n");
	printf("Test '%s': \t\t'%d'\n", string1, atoi(string1));
	printf("Test '%s': \t\t'%d'\n", string2, atoi(string2));
	printf("Test '%s': \t\t'%d'\n", string3, atoi(string3));
	printf("Test '%s': \t\t'%d'\n", string5, atoi(string5));
	printf("Test '%s': \t\t'%d'\n", string6, atoi(string6));
	printf("Test '%s': \t\t'%d'\n", string18, atoi(string18));
	printf("Test '%s': \t'%d'\n", string7, atoi(string7));
	printf("Test '%s': \t'%d'\n", string8, atoi(string8));
	printf("Test '%s': \t'%d'\n", string14, atoi(string14));
	printf("Test '%s': \t'%d'\n", string16, atoi(string16));
	printf("Test '%s': \t'%d'\n", string15, atoi(string15));
	printf("Test '%s': \t\t'%d'\n", string17, atoi(string17));
	printf("Test '%s': \t\t'%d'\n", string4, atoi(string4));
	printf("Test '%s': \t\t'%d'\n", string9, atoi(string9));
	printf("Test '%s': \t\t'%d'\n", string10, atoi(string10));
	printf("Test '%s': \t'%d'\n", string11, atoi(string11));
	printf("Test '%s': \t'%d'\n", string12, atoi(string12));
	printf("Test '%s': \t\t'%d'\n", string13, atoi(string13));
	printf("Test '%s': \t'%d'\n", string19, atoi(string19));
	printf("\n\nMy ATOI\n");
	printf("Test '%s': \t\t'%d'\n", string1, ft_atoi(string1));
	printf("Test '%s': \t\t'%d'\n", string2, ft_atoi(string2));
	printf("Test '%s': \t\t'%d'\n", string3, ft_atoi(string3));
	printf("Test '%s': \t\t'%d'\n", string5, ft_atoi(string5));
	printf("Test '%s': \t\t'%d'\n", string6, ft_atoi(string6));
	printf("Test '%s': \t\t'%d'\n", string18, ft_atoi(string18));
	printf("Test '%s': \t'%d'\n", string7, ft_atoi(string7));
	printf("Test '%s': \t'%d'\n", string8, ft_atoi(string8));
	printf("Test '%s': \t'%d'\n", string14, ft_atoi(string14));
	printf("Test '%s': \t'%d'\n", string16, ft_atoi(string16));
	printf("Test '%s': \t'%d'\n", string15, ft_atoi(string15));
	printf("Test '%s': \t\t'%d'\n", string17, ft_atoi(string17));
	printf("Test '%s': \t\t'%d'\n", string4, ft_atoi(string4));
	printf("Test '%s': \t\t'%d'\n", string9, ft_atoi(string9));
	printf("Test '%s': \t\t'%d'\n", string10, ft_atoi(string10));
	printf("Test '%s': \t'%d'\n", string11, ft_atoi(string11));
	printf("Test '%s': \t'%d'\n", string12, ft_atoi(string12));
	printf("Test '%s': \t\t'%d'\n", string13, ft_atoi(string13));
	printf("Test '%s': \t'%d'\n", string19, ft_atoi(string19));
	return (0);
}
 */