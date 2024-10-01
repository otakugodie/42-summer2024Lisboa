#include <stdio.h>

/* Función encargdaa de saltar espacios en blanco y signos (+ o -) al inicio de la cadena.
Devuelve el signo (-1 si hay un signo negativo, 1 si es positivo) y actualiza el índice (index) para apuntar al primer carácter numérico.
*/
int	skip_paces_signs(char *str, int *index)

{
	int	sign;
	int	i;

	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	*index = i;
	return (sign);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	result;
	int	i;

	result = 0;
	sign = skip_paces_signs(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		// Convertimos cada carácter a su valor numérico
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	main(void)
{
	char *string = "   ---+--+01234506789ab567";
	char *string1 = "1234";
	char *string2 = "-567";
	char *string3 = "   42";
	char *string4 = "100abc";
	char *string5 = "   -1234ab567";
		
	printf("%d\n", ft_atoi(string));
	printf("%d\n", ft_atoi(string1));
	printf("%d\n", ft_atoi(string2));
	printf("%d\n", ft_atoi(string3));
	printf("%d\n", ft_atoi(string4));
	printf("%d\n", ft_atoi(string5));

	return (0);
}
