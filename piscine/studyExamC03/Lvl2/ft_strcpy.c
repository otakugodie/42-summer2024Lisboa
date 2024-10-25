

char    *ft_strcpy(char *s1, char *s2){
	int i;

	i = 0;
	while (s2[i] != '\0'){
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	// s1 -> dest
	// s2 -> src
	return (s1);

}

#include <stdio.h>

int main (void){
	char src[20]="Hi my world";
	char dest[30]="";
	
	printf ("src: %s\n", src);
	printf ("dest: %s\n", dest);

	ft_strcpy(dest,  src);

	printf ("src: %s\n", src);
	printf ("dest: %s\n", dest);

	return 0;

}
/*
Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions: 
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2);
*/