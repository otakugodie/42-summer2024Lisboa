#include <stdio.h>

int	ft_atoi(const char *str){
	int	i;
	int sign;
	int real_index;
	int result;

	i = 0;
	real_index = 0;
	sign = 1;

	/*

	while (str[i] != '\0' && ){
		if (str[i] >= '\t' &&  str[i] <= '\r')
			i++;
		if (str[i]=='-' || str[i]=='+'){
			if (str[i]=='-'){
				sign *= (-1);
			}				
			i++;
		}
		
		else if (     ){}

	}
	*/
	result = 0;
	while (str[i] >= '0' && str[i] <= '9' &&  str[i] != '\0'){
		result = result * 10 + (str[i] - '0');
		//printf ("%c\n", str[i]);
		i++;
	}
	return (result);

}



int main (void){

	printf ("Result is: %d\n" , ft_atoi ("425"));
	return (0);
}