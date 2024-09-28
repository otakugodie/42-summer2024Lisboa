#include <unistd.h>
#include <stdio.h>

int main (int argc, char *argv[]){

    if ( argc >= 2 ){

        char *str;
        str = argv[2];

        printf("Your string is: %s\n", str);
        //printf("Your variable is: %s", typeof(str) );

    }
    else {
        write(1, "\n", 1);
    }   
    return (0);
}



/*
Write a program that takes a string and displays its first word, followed by a newline.

A word is a section of string delimited by spaces/tabs or by the start/end of the string.

If the number of parameters is not 1, or if there are no words, simply display a newline.

Examples:

$> ./first_word "FOR PONY" | cat -e
FOR$
$> ./first_word "this        ...       is sparta, then again, maybe    not" | cat -e
this$
$> ./first_word "   " | cat -e
$
$> ./first_word "a" "b" | cat -e
$
$> ./first_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
*/