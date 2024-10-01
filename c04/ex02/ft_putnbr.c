#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int	is_min;

	is_min = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			nb = nb + 1;
			is_min = 1;
		}
		nb = nb * (-1);
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
	}
	if (is_min && nb % 10 == 7)
	{
		ft_putchar((nb % 10) + '1');
	}
	else
	{
		ft_putchar((nb % 10) + '0');
	}
}

int	main(void)
{
	//printf("-2147483647: ");
	ft_putnbr(-2147483647);
	ft_putchar('\n');
	//printf("-2147483648: ");
	ft_putnbr(-2147483648);
	ft_putchar('\n');
	//printf("42: ");
	ft_putnbr(42);
	ft_putchar('\n');
	//printf("-42: ");
	ft_putnbr(-42);
	ft_putchar('\n');
	//printf("2147483647: ");
	ft_putnbr(2147483647);
	ft_putchar('\n');
	//printf("0: ");
	ft_putnbr(0);
	ft_putchar('\n');
	//printf("1984: ");
	ft_putnbr(1984);
	ft_putchar('\n');
	return (0);
}
