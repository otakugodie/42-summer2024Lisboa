#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	pos_str;
	int	pos_to_find;

	pos_str = 0;
	pos_to_find = 0;
	if (to_find[pos_to_find] == '\0')
		return (str);
	while (str[pos_str] != '\0')
	{
		while (str[pos_str + pos_to_find] == to_find[pos_to_find] && str[pos_str
			+ pos_to_find] != '\0')
		{
			pos_to_find++;
		}
		if (to_find[pos_to_find] == '\0')
			return (str + pos_str);
		pos_str++;
		pos_to_find = 0;
	}
	return (0);
}

int	main(void)
{
	char	str[] = "Hello Lisbon, Hello Portugal";
	char	find[] = "Lisbon";

	printf("%s", ft_strstr(str, find));
	return (0);
}
