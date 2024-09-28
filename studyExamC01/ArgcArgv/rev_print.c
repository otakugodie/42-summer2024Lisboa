#include <stdio.h>
#include <unistd.h>

/*
int main (int argc, char *argv[]){

    printf("Número de argumentos (int argc): %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("Argumento %d: %s\n", i, argv[i]);
    }

    return (0);
}
*/

int	ft_strlen(char *str)
{
	int	i;
	i = 0;
	while(str[i] != '\0')
		i++;
	return (i);
}
char *ft_rev_print(char *str)
{
	int	i;

	i = ft_strlen(str);
	i--;
	while (i >= 0)
	{
		write(1, &str[i], 1);
		i--;
	}
	return(str);
}

int main(int argc, char *argv[])
{
	//char str[] = "gbrireugneb";
    /* printf("Número de argumentos (int argc): %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("Argumento %d: %s\n", i, argv[i]);
    } */
   if (argc == 2){
    ft_rev_print(argv[1]);
   }
   write(1,"\n",1);
   
   return (0);
}