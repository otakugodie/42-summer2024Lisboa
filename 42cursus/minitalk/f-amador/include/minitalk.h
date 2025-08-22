#ifndef MINITALK_H
# define MINITALK_H

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>

void	ft_putnbr(int n);
void	ft_putchar(char c);
void	ft_putstr(char *str);
#endif