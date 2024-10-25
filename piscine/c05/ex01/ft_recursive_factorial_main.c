

#include <stdio.h>

int	ft_recursive_factorial(int	nb)
{
	int	fact;

	fact = 1;
	if (nb > 0)
	{
		fact *= nb * ft_recursive_factorial(nb - 1);
		nb -= 1;
	}
	if (nb < 0)
		return (0);
	return (fact);
}

int	main(void)
{
	printf("%d\n", ft_recursive_factorial(12));
}