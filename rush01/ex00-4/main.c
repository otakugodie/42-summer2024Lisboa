/*

// Matrix 4X4

#include <stdio.h>
#include <stdlib.h>

#define N 4

int is_valid(int grid[N][N], int row, int col, int num, int clues[4][N]);
int solve_skyscrapers(int grid[N][N], int row, int col, int clues[4][N]);
int check_visibility(int grid[N][N], int clues[4][N]);
void print_grid(int grid[N][N]);

int solve_skyscrapers(int grid[N][N], int row, int col, int clues[4][N]) {
    if (col == N) {
        row++;
        col = 0;
    }
    
    if (row == N) {
        return check_visibility(grid, clues);
    }
    
    for (int num = 1; num <= N; num++) {
        if (is_valid(grid, row, col, num, clues)) {
            grid[row][col] = num;
            
            if (solve_skyscrapers(grid, row, col + 1, clues)) {
                return 1;
            }
            
            grid[row][col] = 0;  // Backtrack
        }
    }
    
    return 0;
}

int is_valid(int grid[N][N], int row, int col, int num, int clues[4][N]) {
    // Check row and column
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return 0;
        }
    }
    
    return 1;
}

int check_visibility(int grid[N][N], int clues[4][N]) {
    // Check top and bottom visibility
    for (int col = 0; col < N; col++) {
        int visible_top = 1, max_height_top = grid[0][col];
        int visible_bottom = 1, max_height_bottom = grid[N-1][col];
        
        for (int row = 1; row < N; row++) {
            if (grid[row][col] > max_height_top) {
                visible_top++;
                max_height_top = grid[row][col];
            }
            if (grid[N-1-row][col] > max_height_bottom) {
                visible_bottom++;
                max_height_bottom = grid[N-1-row][col];
            }
        }
        
        if (clues[0][col] != 0 && visible_top != clues[0][col]) return 0;
        if (clues[1][col] != 0 && visible_bottom != clues[1][col]) return 0;
    }
    
    // Check left and right visibility
    for (int row = 0; row < N; row++) {
        int visible_left = 1, max_height_left = grid[row][0];
        int visible_right = 1, max_height_right = grid[row][N-1];
        
        for (int col = 1; col < N; col++) {
            if (grid[row][col] > max_height_left) {
                visible_left++;
                max_height_left = grid[row][col];
            }
            if (grid[row][N-1-col] > max_height_right) {
                visible_right++;
                max_height_right = grid[row][N-1-col];
            }
        }
        
        if (clues[2][row] != 0 && visible_left != clues[2][row]) return 0;
        if (clues[3][row] != 0 && visible_right != clues[3][row]) return 0;
    }
    
    return 1;
}

void print_grid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d", grid[i][j]);
            if (j < N - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Error\n");	//Error: Please provide clues as a single string argument
        return 1;
    }

    int clues[4][N];
    char *arg = argv[1];
    int clue_values[16];
    int index = 0;

    // Parse the input string and convert to integers
    for (int i = 0; i < 31; i += 2) {
        if (arg[i] >= '1' && arg[i] <= '4') {
            clue_values[index] = arg[i] - '0';
            index++;
        } else if (arg[i] != ' ') {
            printf("Error\n");	//Invalid input format
            return 1;
        }
    }

    if (index != 16) {
        printf("Error\n"); //Incorrect number of clues
        return 1;
    }

    // Fill the clues matrix
    for (int i = 0; i < N; i++) {
        clues[0][i] = clue_values[i];       // Top clues
        clues[1][i] = clue_values[i + N];   // Bottom clues
        clues[2][i] = clue_values[i + 2*N]; // Left clues
        clues[3][i] = clue_values[i + 3*N]; // Right clues
    }

    int grid[N][N] = {0};

    if (solve_skyscrapers(grid, 0, 0, clues)) {
        //printf("Solution found:\n");
        print_grid(grid);
    } else {
        printf("Error\n");	//No solution exists
    }

    return 0;
}

*/

#include <stdio.h>
#include <stdlib.h>

void print_grid(int **grid, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d", grid[i][j]);
            if (j < N - 1) {
                printf(" ");
            }
        }
        printf("$\n");
    }
}

int solve_skyscrapers(int **grid, int row, int col, int N, int **clues);
int check_visibility(int **grid, int N, int **clues);
int is_valid(int **grid, int row, int col, int num, int N, int **clues);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Error\n");
        return 1;
    }

    // Contar los números en la entrada
    char *arg = argv[1];
    int clue_count = 0;
    for (int i = 0; arg[i] != '\0'; i++) {
        if (arg[i] >= '1' && arg[i] <= '9') {
            clue_count++;
        }
    }

    // Determinar N basado en la cantidad de pistas (asumimos que es un cuadrado perfecto)
    int N = 1;
    while (N * N < clue_count) {
        N++;
    }

    if (N * N != clue_count) {
        printf("Error\n");
        return 1;
    }

    // Asignar memoria para la matriz de pistas
    int **clues = (int **)malloc(4 * sizeof(int *));
    for (int i = 0; i < 4; i++) {
        clues[i] = (int *)malloc(N * sizeof(int));
    }

    // Asignar memoria para la matriz del tablero
    int **grid = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        grid[i] = (int *)malloc(N * sizeof(int));
    }

    // Inicializar el grid
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = 0;
        }
    }

    // Parsear los valores de las pistas
    int clue_values[clue_count];
    int index = 0;

    for (int i = 0; arg[i] != '\0'; i++) {
        if (arg[i] >= '1' && arg[i] <= '9') {
            clue_values[index] = arg[i] - '0';
            index++;
        }
    }

    // Asignar las pistas a la matriz de pistas
    for (int i = 0; i < N; i++) {
        clues[0][i] = clue_values[i];       // Clues de arriba
        clues[1][i] = clue_values[i + N];   // Clues de abajo
        clues[2][i] = clue_values[i + 2*N]; // Clues de la izquierda
        clues[3][i] = clue_values[i + 3*N]; // Clues de la derecha
    }

    // Resolver el rompecabezas
    if (solve_skyscrapers(grid, 0, 0, N, clues)) {
        print_grid(grid, N);
    } else {
        printf("Error\n");
    }

    // Liberar la memoria asignada
    for (int i = 0; i < N; i++) {
        free(grid[i]);
    }
    free(grid);

    for (int i = 0; i < 4; i++) {
        free(clues[i]);
    }
    free(clues);

    return 0;
}
