#include <unistd.h>

void	ft_putstr(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos] != '\0')
	{
		write(1, &str[pos], 1);
		pos++;
	}
}

int	main(void)
{
	char	str[45] = "There is no place like ";

	ft_putstr(str);
	return (0);
}
