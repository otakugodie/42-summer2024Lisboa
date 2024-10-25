#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_size_str(char *base)
{
	int	count;

	count = 0;
	while (base[count] != '\0')
	{
		count++;
	}
	return (count);
}

int	check_errors(char *base)
{
	int	count;
	int	count2;

	count = 0;
	if (ft_size_str(base) <= 1)
		return (0);
	while (base[count] != '\0')
	{	
		if ((base[count] >= '0' && base[count] <= '9') || (base[count] > 'a'
				&& base[count] < 'y') || (base[count] > 'A'
				&& base[count] < 'F'))
		{
			count2 = count + 1;
			while (count2 < ft_size_str(base))
			{
				if (base[count] == base[count2])
					return (0);
				count2++;
			}
			count++;
		}
		else
			return (0);
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (check_errors(base) == 1)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr *= (-1);
		}
		if (nbr < ft_size_str(base))
			ft_putchar(base[nbr]);
		if (nbr > ft_size_str(base))
		{
			ft_putnbr_base((nbr / ft_size_str(base)), base);
			ft_putnbr_base((nbr % ft_size_str(base)), base);
		}
	}
}

int	main(void)
{
	/*
	char	*base_dec[] = "0123456789";
	char	*base_bin[] = "01";
	char	*base_hex[] = "0123456789ABCDEF";
	char	*base_oct[] = "poniguay";
	*/

	ft_putnbr_base(-12, "01");
	printf("\n");
	ft_putnbr_base(40, "poniguay");
	printf("\n");
	ft_putnbr_base(894867, "0123456789");
	printf("\n");
	ft_putnbr_base(53, "0123456789abcdef");
	printf("\n");
	return (0);
}
