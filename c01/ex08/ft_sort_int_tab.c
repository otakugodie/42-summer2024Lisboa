


void ft_sort_int_tab(int *tab, int size){
    int pos;
    int is_finish;
    int temp;

    is_finish = 0;
    while (!is_finish){        
        is_finish=1;
        pos = 0;
        while (pos <= size-2){

            if ( tab[pos] > tab[pos+1]   ){
                temp = tab[pos];
                tab[pos] = tab[pos+1];
                tab[pos+1] = temp;
                is_finish=0;
            }
            pos++;
            //print_array(tab, size);
        }
        //print_array(tab, size);
    }
}


#include <stdio.h>

void print_array (int *tab, int size){
    int i;
    //printf("Size= %d\n", size);
    for (i=0; i<size; i++){
        printf("%d ", tab[i]);
    }
    printf("\n");
   
}

int main (void){
    int size;
    int array_int[]={4,3,-200, 21,7,2,-12,14,14,69,42,24,39,10};
    int *tab;
   
    size = sizeof(array_int)/sizeof(array_int[0]);
    tab = array_int;

    print_array(tab, size);

    ft_sort_int_tab(tab, size);
   
    print_array(tab, size);
   
    return (0);
}
