
int ft_strlen(char *str){
	int i = 0;
	while (str[i] != '\0'){
		i++;
	}

	return (i);
}


char    *ft_strrev(char *str){
	int i = 0;
	int size;
	char temp;
	
	size = ft_strlen(str) - 1;
	while (size > i)
	{
		temp = str[i];
		str[i] = str[size];
		str[size] = temp;
		i++;
		size--;
	}
	return (str);

}

#include <stdio.h>

int main (void){
	char s1[15]="Hi world";
	printf("Reverse string: %s\n", ft_strrev(s1));
	return 0;
}

/*
Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions: 
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);

*/