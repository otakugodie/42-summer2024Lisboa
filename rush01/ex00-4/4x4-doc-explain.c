#include <unistd.h>
#include <stdio.h>

#define SIZE 4  // Define el tamaño de la cuadrícula (4x4 en este caso)

// Funciones utilizadas más adelante
int	is_valid(int grid[SIZE][SIZE], int row, int col, int num);
int	solve_skyscrapers(int grid[SIZE][SIZE], int row, int col, int clues[4][SIZE]);
int	check_visibility(int grid[SIZE][SIZE], int clues[4][SIZE]);
void	print_grid(int grid[SIZE][SIZE]);
void	parse_clues(char *arg, int clues[4][SIZE]);

// Función para moverse a la siguiente celda en la cuadrícula
int	move_to_next_cell(int *row, int *col) {
	if (*col == SIZE) {
		(*row)++;  // Si llegamos al final de una fila, pasamos a la siguiente
		*col = 0;  // Reiniciamos la columna al principio
	}
	if (*row == SIZE) {
		return (1);  // Si llegamos al final de la cuadrícula, terminamos
	}
	return (0);  // Si no, continuamos
}

// Función que intenta colocar un número en la cuadrícula
int	try_number(int grid[SIZE][SIZE], int row, int col, int num, int clues[4][SIZE]) {
	if (is_valid(grid, row, col, num)) {
		grid[row][col] = num;  // Si el número es válido, lo colocamos en la celda
		if (solve_skyscrapers(grid, row, col + 1, clues)) {
			return (1);  // Si resolver a partir de aquí es posible, terminamos
		}
		grid[row][col] = 0;  // Si no funciona, "retrocedemos" (backtrack)
	}
	return (0);  // Si no se puede colocar el número, devolvemos 0
}

// Función principal para resolver el rompecabezas
int	solve_skyscrapers(int grid[SIZE][SIZE], int row, int col, int clues[4][SIZE]) {
	int	num;

	if (move_to_next_cell(&row, &col)) {
		return (check_visibility(grid, clues));  // Al llegar al final, comprobamos visibilidad
	}
	num = 1;
	while (num <= SIZE) {  // Probamos los números del 1 al 4 en cada celda
		if (try_number(grid, row, col, num, clues)) {
			return (1);  // Si encontramos una solución válida, retornamos 1
		}
		num++;
	}
	return (0);  // Si no hay número válido, devolvemos 0
}

// Validación de si es válido colocar un número en la fila o columna sin repetir
int	is_valid(int grid[SIZE][SIZE], int row, int col, int num) {
	int	i;

	i = 0;
	while (i < SIZE) {
		if (grid[row][i] == num || grid[i][col] == num) {
			return (0);  // Si el número ya está en la fila o columna, no es válido
		}
		i++;
	}
	return (1);  // Si no hay repeticiones, es válido
}

// Función para verificar la visibilidad desde arriba
int check_top_visibility(int grid[SIZE][SIZE], int col, int clues[4][SIZE]) {
	int visible;
	int max_height;
	int row;

	visible = 1;
	max_height = grid[0][col];  // Comenzamos con la primera fila
	row = 1;
	while (row < SIZE) {
		if (grid[row][col] > max_height) {
			visible++;  // Si el edificio es más alto, aumenta la visibilidad
			max_height = grid[row][col];
		}
		row++;
	}
	if (clues[0][col] != 0 && visible != clues[0][col]) {
		return (0);  // Si la visibilidad no coincide con las pistas, devolvemos 0
	}
	return (1);  // Si es correcta, devolvemos 1
}

// Función para verificar la visibilidad desde abajo (similar a la de arriba)
int check_bottom_visibility(int grid[SIZE][SIZE], int col, int clues[4][SIZE]) {
	int visible;
	int max_height;
	int row;

	visible = 1;
	max_height = grid[SIZE - 1][col];  // Comenzamos desde la última fila
	row = SIZE - 2;
	while (row >= 0) {
		if (grid[row][col] > max_height) {
			visible++;
			max_height = grid[row][col];
		}
		row--;
	}
	if (clues[1][col] != 0 && visible != clues[1][col]) {
		return (0);
	}
	return (1);
}

// Verificación de visibilidad vertical (desde arriba y abajo)
int check_vertical_visibility(int grid[SIZE][SIZE], int clues[4][SIZE]) {
	int col;

	col = 0;
	while (col < SIZE) {
		if (!check_top_visibility(grid, col, clues)) {
			return (0);
		}
		if (!check_bottom_visibility(grid, col, clues)) {
			return (0);
		}
		col++;
	}
	return (1);
}

// Función para verificar la visibilidad desde la izquierda
int check_left_visibility(int grid[SIZE][SIZE], int row, int clues[4][SIZE]) {
	int visible;
	int max_height;
	int col;

	visible = 1;
	max_height = grid[row][0];  // Comenzamos desde la primera columna
	col = 1;
	while (col < SIZE) {
		if (grid[row][col] > max_height) {
			visible++;
			max_height = grid[row][col];
		}
		col++;
	}
	if (clues[2][row] != 0 && visible != clues[2][row]) {
		return (0);
	}
	return (1);
}

// Función para verificar la visibilidad desde la derecha (similar a la de la izquierda)
int check_right_visibility(int grid[SIZE][SIZE], int row, int clues[4][SIZE]) {
	int visible;
	int max_height;
	int col;

	visible = 1;
	max_height = grid[row][SIZE - 1];  // Comenzamos desde la última columna
	col = SIZE - 2;
	while (col >= 0) {
		if (grid[row][col] > max_height) {
			visible++;
			max_height = grid[row][col];
		}
		col--;
	}
	if (clues[3][row] != 0 && visible != clues[3][row]) {
		return (0);
	}
	return (1);
}

// Verificación de visibilidad horizontal (izquierda y derecha)
int check_horizontal_visibility(int grid[SIZE][SIZE], int clues[4][SIZE]) {
	int row;

	row = 0;
	while (row < SIZE) {
		if (!check_left_visibility(grid, row, clues)) {
			return (0);
		}
		if (!check_right_visibility(grid, row, clues)) {
			return (0);
		}
		row++;
	}
	return (1);
}

// Verificación general de visibilidad (vertical y horizontal)
int	check_visibility(int grid[SIZE][SIZE], int clues[4][SIZE]) {
	if (!check_vertical_visibility(grid, clues)) {
		return (0);
	}
	if (!check_horizontal_visibility(grid, clues)) {
		return (0);
	}
	return (1);
}

// Función para imprimir la cuadrícula
void	print_grid(int grid[SIZE][SIZE]) {
	int	i;
	int	j;
	
	i = 0;
	while (i < SIZE) {
		j = 0;
		while (j < SIZE) {
			printf("%d", grid[i][j]);
			if (j < SIZE - 1) {
				printf(" ");
			}
			j++;
		}
		printf("\n");
		i++;
	}
}

// Imprimir error y salir del programa
int	print_error_and_exit(void) {
	write(1, "Error\n", 6);
	return (1);
}

// Verificar si un carácter es una pista válida (1 a 4)
int	is_valid_clue(char c) {
	return (c >= '1' && c <= '4');
}

// Extraer las pistas del argumento y almacenarlas en un array
void	extract_clue_values(char *arg, int clue_values[16]) {
	int	index;
	int	i;

	index = 0;
	i = 0;
	while (i < 31) {
		if (is_valid_clue(arg[i])) {
			clue_values[index] = arg[i] - '0';
			index++;
		} else if (arg[i] != ' ') {
			print_error_and_exit();
		}
		i += 2;  // Saltamos los espacios
	}
	if (index != 16) {
		print_error_and_exit();
	}
}

// Asignar las pistas al array de 4x4
void	assign_clues(int clue_values[16], int clues[4][SIZE]) {
	int	i;

	i = 0;
	while (i < SIZE) {
		clues[0][i] = clue_values[i];               // Desde arriba
		clues[1][i] = clue_values[i + SIZE];        // Desde abajo
		clues[2][i] = clue_values[i + 2 * SIZE];    // Desde la izquierda
		clues[3][i] = clue_values[i + 3 * SIZE];    // Desde la derecha
		i++;
	}
}

// Parsear (procesar) las pistas dadas como argumento
void	parse_clues(char *arg, int clues[4][SIZE]) {
	int	clue_values[16];

	extract_clue_values(arg, clue_values);
	assign_clues(clue_values, clues);
}

// Función principal
int	main(int argc, char **argv) {
	int	clues[4][SIZE];  // Almacenará las pistas
	int	grid[SIZE][SIZE] = {0};  // La cuadrícula comienza vacía (todo 0)
	
	if (argc == 2) {  // Verificamos que solo haya un argumento
		parse_clues(argv[1], clues);  // Procesamos las pistas
		if (solve_skyscrapers(grid, 0, 0, clues)) {
			print_grid(grid);  // Si hay solución, imprimimos la cuadrícula
		} else {
			write(1, "Error\n", 6);  // Si no hay solución, mostramos error
		}
	} else {
		print_error_and_exit();  // Si el número de argumentos es incorrecto
	}
	
	return (0);
}
