#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

int ft_strlen (char *str){
	int i;
	i=0;

	while (str[i]!='\0'){
		i++;
	}
	return (i);
}

int ft_count_uppercase (char *str){
	int i;
	int counter;
	i=0;
	counter=0;
	
	while (str[i]!='\0'){
		if (str[i] >= 'A' && str[i] <= 'Z')
			counter++;
		i++;
	}
	return (counter);
}



int main (int argc, char *argv[]){

	if (argc == 2 && argv[1][0] != '\0'){
		
		int	size;
		int	new_size;
		int	i;
		int j;

		size = ft_strlen (argv[1]);
		new_size = size + ft_count_uppercase(argv[1]);	

		char *snake_str = malloc(new_size*sizeof(char));

		i = 0;
		j = 0;
		while (argv[1][i] != '\0'){
			if (argv[1][i] >= 'A' &&  argv[1][i] <= 'Z'){
				snake_str[j] = '_';
				j++;
				snake_str[j] = argv[1][i] + 32;
			} else{
				snake_str[j] = argv[1][i];
			}
			j++;
			i++;
		}
		snake_str[j] = '\0';
		write(1, snake_str, ft_strlen(snake_str));
		write(1, "\n", 1);
		free (snake_str);

		//printf ("La cadena final es: %s\n", snake_str);
	}
	else {
		write(1, "\n", 1);
	}
	return 0;
}


/*
/*

Assignment name  : camel_to_snake
Expected files   : camel_to_snake.c
Allowed functions: malloc, free, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in lowerCamelCase format
and converts it into a string in snake_case format.

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

Examples:
$>./camel_to_snake "hereIsACamelCaseWord"
here_is_a_camel_case_word
$>./camel_to_snake "helloWorld" | cat -e
hello_world$
$>./camel_to_snake | cat -e
$

*/