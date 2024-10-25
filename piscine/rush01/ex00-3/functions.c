#include <unistd.h>

/*
 Devuelve 1 si el mismo elemento está presente dos veces en la matriz, devuelve 0 si todos los elementos son diferentes.
 */
int	el_in_tab(int *row)
{
	int	cur;
	int	cur2;

	cur = 0;
	while (cur < 4)
	{
		cur2 = 0;
		while (cur2 < 4)
		{
			if (row[cur] == row[cur2] && cur != cur2)
				return (1);
			cur2++;
		}
		cur++;
	}
	return (0);
}

/*
 Rellena la matriz checktab con las filas de permutaciones especificadas por linesnum.
 */
void	lines_to_array(int checktab[4][4], int permut[24][4], int linesnum[4])
{
	int	cur;
	int	cur2;

	cur = 0;
	cur2 = 0;
	while (cur < 4)
	{
		cur2 = 0;
		while (cur2 < 4)
		{
			checktab[cur][cur2] = permut[linesnum[cur]][cur2];
			cur2++;
		}
		cur++;
	}
}

/*
 Tome una tabla bidimensional que mida 4*4 y visualícela
 */
void	print_solution(int tab[4][4])
{
	int		cur;
	int		cur2;
	char	c;

	cur = 0;
	while (cur < 4)
	{
		cur2 = 0;
		while (cur2 < 4)
		{
			c = tab[cur][cur2] + '0';
			write(1, &c, 1);
			if (cur2 != 3)
				write(1, " ", 1);
			cur2++;
		}
		write(1, "\n", 1);
		cur++;
	}
}

/*
 Funciones que invierten los elementos de la matriz pasados como parámetros
 */
void	ft_rev_int_tab(int *tab, int size)
{
	int	cur;
	int	t;

	cur = 0;
	while (cur < size / 2)
	{
		t = tab[cur];
		tab[cur] = tab[size - 1 - cur];
		tab[size - 1 - cur] = t;
		cur++;
	}
}

/*
 Rellena un array de 4 elementos con los elementos de la columna numérica "col_num".
 */
void	get_cols(int col_tab[4], int tab[4][4], int col_num)
{
	col_tab[0] = tab[0][col_num];
	col_tab[1] = tab[1][col_num];
	col_tab[2] = tab[2][col_num];
	col_tab[3] = tab[3][col_num];
}

