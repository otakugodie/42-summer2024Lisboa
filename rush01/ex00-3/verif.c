// functions.c
void	ft_rev_int_tab(int *tab, int size);
int		el_in_tab(int *row);
void	get_cols(int col_tab[4], int tab[4][4], int col_num);

/*
Comprueba que la línea pasada contiene el número correcto de casillas visibles, "val" es el valor dado por la instrucción Row puede representar tanto una fila como una columna
 */
int	check(int *row, int val)
{
	int	stock;
	int	cur;
	int	num;

	cur = 1;
	stock = row[0];
	num = 1;
	while (num < 4)
	{
		if (row[num] > stock)
		{
			cur++;
			stock = row[num];
		}
		num++;
	}
	if (cur == val && el_in_tab(row) == 0)
		return (1);
	else
		return (0);
}

/*
 Invierta la línea/columna de paso, hágala pasar por control y vuelva a ponerla al revés. Utiliza la misma función de comprobación para comprobar ambos sentidos de una línea/columna.
 */
int	check_reverse(int *row, int val)
{
	int	ret;

	ft_rev_int_tab(row, 4);
	ret = check(row, val);
	ft_rev_int_tab(row, 4);
	return (ret);
}

/*
 Llama a las funciones check y check_reverse en esa línea val[n] es el valor pasado por el usuario para esa línea
 */
int	verif_rows(int tab[4][4], int *val)
{
	if (check(tab[0], val[8]) == 0 || check_reverse(tab[0], val[12]) == 0)
		return (0);
	if (check(tab[1], val[9]) == 0 || check_reverse(tab[1], val[13]) == 0)
		return (0);
	if (check(tab[2], val[10]) == 0 || check_reverse(tab[2], val[14]) == 0)
		return (0);
	if (check(tab[3], val[11]) == 0 || check_reverse(tab[3], val[15]) == 0)
		return (0);
	return (1);
}

/*
 Llama a las funciones check y check_reverse en cada columna val[n] es el valor pasado por el usuario para esta columna. Usamos get_cols para poner en test_tab todos los valores de la columna
 */
int	verif_cols(int tab[4][4], int *val)
{
	int	test_tab[4];

	get_cols(test_tab, tab, 0);
	if (check(test_tab, val[0]) == 0 || check_reverse(test_tab, val[4]) == 0)
		return (0);
	get_cols(test_tab, tab, 1);
	if (check(test_tab, val[1]) == 0 || check_reverse(test_tab, val[5]) == 0)
		return (0);
	get_cols(test_tab, tab, 2);
	if (check(test_tab, val[2]) == 0 || check_reverse(test_tab, val[6]) == 0)
		return (0);
	get_cols(test_tab, tab, 3);
	if (check(test_tab, val[3]) == 0 || check_reverse(test_tab, val[7]) == 0)
		return (0);
	return (1);
}

/*
 Función principal que llama a las funciones de vista previa de filas y columnas
 */
int	verif(int tab[4][4], int *val)
{
	if (verif_rows(tab, val) == 0 || verif_cols(tab, val) == 0)
		return (0);
	return (1);
}

