#include <stdio.h>

int	ft_atoi(const char *str){

	int result = 0;
	int i = 0;

	while (str[i] != '\0'){
		result = result * 10 + (str[i]+'0');
		printf("result: %d\n" , result);
		i++;
	}

	return result;
}


int main (void){

	int valor;

	printf("Int is: %d\n", ft_atoi("157") );



	return 0;
}


/*
Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);
*/