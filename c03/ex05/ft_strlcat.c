#include <stdio.h>
#include <string.h>

int	ft_strlen(char *src)
{
	int	size_len;

	size_len = 0;
	while (src[size_len] != '\0')
		size_len++;
	return (size_len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	size_dest;
	unsigned int	size_src;
	unsigned int	i;
	unsigned int	j;

	size_dest = ft_strlen(dest);
	size_src = ft_strlen(src);
	if (size <= size_dest)
		return (size + size_src);
	i = size_dest;
	j = 0;
	while (src[j] != '\0' && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (size_dest + size_src);
}

int	main(void)
{
	char			dest[45] = "There is no place like ";
	char			src[] = "127.0.0.1";
	unsigned int	n;

	n = 45;	
	printf("%d\n", ft_strlcat(dest, src, n));
	printf("%s \n", dest);
	return (0);
}
