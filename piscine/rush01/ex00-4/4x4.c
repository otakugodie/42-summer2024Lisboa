/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4x4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 08:19:28 by diegfern          #+#    #+#             */
/*   Updated: 2024/09/29 09:54:01 by diegfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#define SIZE 4

int	is_valid(int grid[SIZE][SIZE], int row, int col, int num );
int	solve_skyscrapers(int grid[SIZE][SIZE], int row, int col,
			int clues[4][SIZE]);
int	check_visibility(int grid[SIZE][SIZE], int clues[4][SIZE]);
void	print_grid(int grid[SIZE][SIZE]);
void	parse_clues(char *arg, int clues[4][SIZE]);

// Solvers
int	move_to_next_cell(int *row, int *col)
{
	if (*col == SIZE)
	{
		(*row)++;
		*col = 0;
	}
	if (*row == SIZE)
	{
		return (1);
	}
	return (0);
}

int	try_number(int grid[SIZE][SIZE], int row, int col, int num,
		int clues[4][SIZE])
{
	if (is_valid(grid, row, col, num /*, clues*/))
	{
		grid[row][col] = num;
		if (solve_skyscrapers(grid, row, col + 1, clues))
		{
			return (1);
		}
		grid[row][col] = 0; // Backtrack
	}
	return (0);
}

int	solve_skyscrapers(int grid[SIZE][SIZE], int row, int col,
		int clues[4][SIZE])
{
	int	num;

	if (move_to_next_cell(&row, &col))
	{
		return (check_visibility(grid, clues));
	}
	num = 1;
	while (num <= SIZE)
	{
		if (try_number(grid, row, col, num, clues))
		{
			return (1);
		}
		num++;
	}
	return (0); // No valid number found, need to backtrack
}

//Validations
int	is_valid(int grid[SIZE][SIZE], int row, int col, int num /* , int clues[4][SIZE] */)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		if (grid[row][i] == num || grid[i][col] == num)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

// Function to check visibility from top
int check_top_visibility(int grid[SIZE][SIZE], int col, int clues[4][SIZE])
{
    int visible;
    int max_height;
    int row;

    visible = 1;
    max_height = grid[0][col];
    row = 1;
    while (row < SIZE)
    {
        if (grid[row][col] > max_height)
        {
            visible++;
            max_height = grid[row][col];
        }
        row++;
    }
    if (clues[0][col] != 0 && visible != clues[0][col])
        return (0);
    return (1);
}

// Function to check visibility from bottom
int check_bottom_visibility(int grid[SIZE][SIZE], int col, int clues[4][SIZE])
{
    int visible;
    int max_height;
    int row;

    visible = 1;
    max_height = grid[SIZE - 1][col];
    row = SIZE - 2;
    while (row >= 0)
    {
        if (grid[row][col] > max_height)
        {
            visible++;
            max_height = grid[row][col];
        }
        row--;
    }
    if (clues[1][col] != 0 && visible != clues[1][col])
        return (0);
    return (1);
}

// Function to check vertical visibility
int check_vertical_visibility(int grid[SIZE][SIZE], int clues[4][SIZE])
{
    int col;

    col = 0;
    while (col < SIZE)
    {
        if (!check_top_visibility(grid, col, clues))
            return (0);
        if (!check_bottom_visibility(grid, col, clues))
            return (0);
        col++;
    }
    return (1);
}

// Function to check visibility from left
int check_left_visibility(int grid[SIZE][SIZE], int row, int clues[4][SIZE])
{
    int visible;
    int max_height;
    int col;

    visible = 1;
    max_height = grid[row][0];
    col = 1;
    while (col < SIZE)
    {
        if (grid[row][col] > max_height)
        {
            visible++;
            max_height = grid[row][col];
        }
        col++;
    }
    if (clues[2][row] != 0 && visible != clues[2][row])
        return (0);
    return (1);
}

// Function to check visibility from right
int check_right_visibility(int grid[SIZE][SIZE], int row, int clues[4][SIZE])
{
    int visible;
    int max_height;
    int col;

    visible = 1;
    max_height = grid[row][SIZE - 1];
    col = SIZE - 2;
    while (col >= 0)
    {
        if (grid[row][col] > max_height)
        {
            visible++;
            max_height = grid[row][col];
        }
        col--;
    }
    if (clues[3][row] != 0 && visible != clues[3][row])
        return (0);
    return (1);
}

// Function to check horizontal visibility
int check_horizontal_visibility(int grid[SIZE][SIZE], int clues[4][SIZE])
{
    int row;

    row = 0;
    while (row < SIZE)
    {
        if (!check_left_visibility(grid, row, clues))
            return (0);
        if (!check_right_visibility(grid, row, clues))
            return (0);
        row++;
    }
    return (1);
}

int	check_visibility(int grid[SIZE][SIZE], int clues[4][SIZE])
{
	if (!check_vertical_visibility(grid, clues))
		return (0); // Invalid vertical visibility
	if (!check_horizontal_visibility(grid, clues))
		return (0); // Invalid horizontal visibility
	return (1);     // All visibility checks passed
}

void	print_grid(int grid[SIZE][SIZE])
{
	int	i;
	int	j;
	
	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			printf("%d", grid[i][j]);
			//write (1, &grid[i][j], 1);
			if (j < SIZE - 1)
			{
				printf(" ");
				//write(1, " ", 1);
			}
			j++;
		}
		printf("\n");
		//write(1, "\n", 1);
		i++;
	}
}

int	print_error_and_exit(void)
{
	write(1, "Error\n", 6);
	return (1);
}

//Clues
int	is_valid_clue(char c)
{
	return (c >= '1' && c <= '4');
}

void	extract_clue_values(char *arg, int clue_values[16])
{
	int	index;
	int	i;

	index = 0;
	i = 0;
	while (i < 31)
	{
		if (is_valid_clue(arg[i]))
		{
			clue_values[index] = arg[i] - '0';
			index++;
		}
		else if (arg[i] != ' ')
		{
			print_error_and_exit();
		}
		i += 2;
	}
	if (index != 16)
	{
		print_error_and_exit();
	}
}

void	assign_clues(int clue_values[16], int clues[4][SIZE])
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		clues[0][i] = clue_values[i];
		clues[1][i] = clue_values[i + SIZE];
		clues[2][i] = clue_values[i + 2 * SIZE];
		clues[3][i] = clue_values[i + 3 * SIZE];
		i++;
	}
}

void	parse_clues(char *arg, int clues[4][SIZE])
{
	int	clue_values[16];

	extract_clue_values(arg, clue_values);
	assign_clues(clue_values, clues);
}

int	main(int argc, char **argv)
{
	int	clues[4][SIZE];
	int	grid[SIZE][SIZE] = {0};
	
	if (argc <= 2){
		parse_clues(argv[1], clues);
		if (solve_skyscrapers(grid, 0, 0, clues))
		{
			print_grid(grid);
		}
		else
		{
			write(1, "Error\n", 6); // No solution exists
		}
	}
	else {
		print_error_and_exit();
	}
	
	return (0);
}
