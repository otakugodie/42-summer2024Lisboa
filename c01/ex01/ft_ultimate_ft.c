/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:58:12 by diegfern          #+#    #+#             */
/*   Updated: 2024/09/23 12:33:14 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void ft_ultimate_ft(int *********nbr){

    /*
    reciba como parámetro 
        un puntero a 
        un puntero a 
        un puntero a 
        un puntero a 
        un puntero a 
        un puntero a 
        un puntero a 
        un puntero a 
        un puntero a un int y dé al int el valor 42
    */
   *********nbr=42;
   //printf("El valor es %d\n", *********nbr);
}
    
int main (void){
    int value;
    int *nbr1, **nbr2, ***nbr3, ****nbr4, *****nbr5, ******nbr6, *******nbr7, ********nbr8, *********nbr;

    nbr1 = &value;
    nbr2 = &nbr1;
    nbr3 = &nbr2;
    nbr4 = &nbr3;
    nbr5 = &nbr4;
    nbr6 = &nbr5;
    nbr7 = &nbr6;
    nbr8 = &nbr7;
    nbr= &nbr8;    
    
    ft_ultimate_ft(nbr);

    return 0;
}
