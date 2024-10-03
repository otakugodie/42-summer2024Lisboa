#include <stdio.h>
#include <unistd.h>

int	ft_size_str(char *base)
{
	int	count;

	count = 0;
	while (base[count] != '\0')
		count++;
	return (count);
}

int	ft_check_errors(char *base)
{
	int	count;
	int	count2;

	count = 0;
	if (ft_size_str(base) <= 1)
		return (0); // Error: base vacía o de tamaño 1
	while (base[count] != '\0')
	{
		// Verificamos si base contiene (+, -, o espacios)
		if (base[count] == '+' || base[count] == '-' || base[count] == ' '
			|| (base[count] >= 9 && base[count] <= 13))
			// Espacios o caracteres invisibles
			return (0);
		// Verificamos duplicados
		count2 = count + 1;
		while (base[count2] != '\0')
		{
			if (base[count] == base[count2])
				return (0); // Error: Caracteres duplicados
			count2++;
		}
		count++;
	}
	return (1); // Base válida
}

int	ft_skip_spaces_signs(char *str, int *index)
{
	int	sign;
	int	i;

	sign = 1;
	i = 0;
	// Ignorar espacios al principio
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	// Manejo de signos
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1; // Cambia el signo
		i++;
	}
	*index = i;    // Guardamos la posición después de los espacios y signos
	return (sign); // Devolvemos el signo final
}

// Error en esta funcion para base 8
int	ft_get_base_value(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i); // Devolvemos el valor de la base si coincide
		i++;
	}
	return (-1); // Caracter no encontrado en la base
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	sign;
	int	result;
	int	i;
	int	base_val;

	// Validamos la base
	if (!ft_check_errors(base))
		return (0);
	result = 0;
	base_len = ft_size_str(base);
	sign = ft_skip_spaces_signs(str, &i);
	while (str[i] != '\0')
	{
		base_val = ft_get_base_value(str[i], base);
		if (base_val == -1)
			return (0);
		// Error si encontramos un caracter que no está en la base
		result = result * base_len + base_val;
		i++;
	}
	return (result * sign);
}

int	main(void)
{
	// Prueba con base binaria
	printf("%d \n", ft_atoi_base("   -1010", "01"));
	// Resultado: 	-10(binario)
	printf("%d\n", ft_atoi_base("	---101010", "01"));
	// Resultado: 42 (binario)
	// Prueba con base decimal
	printf("%d \n", ft_atoi_base("894867", "0123456789"));
	// Resultado: 894867 (decimal)
	printf("%d\n", ft_atoi_base("	+++++--133742", "0123456789"));
	// Resultado: 133742 (decimal)
	// Prueba con base hexadecimal
	printf("%d \n", ft_atoi_base("53", "0123456789abcdef"));
	// Resultado: 83 (hexadecimal)
	printf("%d\n", ft_atoi_base(" 	+---539A", "0123456789ABCDEF"));
	// Resultado: -21402 (hexadecimal)
	// Prueba con base personalizada "poniguay"
	printf("%d \n", ft_atoi_base("oiy", "poniguay"));
	// Resultado esperado: 95 (base octal personalizada)
	// Prueba con base personalizada "01234567"
	printf("%d \n", ft_atoi_base("71", "01234567"));
	// Resultado esperado: 57 (base octal personalizada)
	return (0);
}
