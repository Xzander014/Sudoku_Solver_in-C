#include <stdio.h>
#include <stdbool.h>

#define SIZE 9 // Define the size of the Sudoku grid

// Function prototypes
bool isValidPlacement(int row, int col, int num, int grid[SIZE][SIZE]);
void printGrid(int grid[SIZE][SIZE]);
bool solveSudoku(int grid[SIZE][SIZE]);
bool findEmptyCell(int grid[SIZE][SIZE], int *row, int *col);

int main()
{
    // Sample Sudoku puzzle (0 represents an empty cell)
    int grid[SIZE][SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    // Solve the puzzle and print the result
    if (solveSudoku(grid))
    {
        printf("Solved Sudoku:\n");
        printGrid(grid);
    }
    else
    {
        printf("No solution exists.\n");
    }

    return 0;
}

// Function to check if placing 'num' at grid[row][col] is valid
bool isValidPlacement(int row, int col, int num, int grid[SIZE][SIZE])
{
    int boxStartRow = row - row % 3;
    int boxStartCol = col - col % 3;

    // Check the row and column for duplicates
    for (int i = 0; i < SIZE; i++)
    {
        if (grid[row][i] == num || grid[i][col] == num)
        {
            return false;
        }
    }

    // Check the 3x3 subgrid for duplicates
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[boxStartRow + i][boxStartCol + j] == num)
            {
                return false;
            }
        }
    }
    return true;
}

// Function to print the Sudoku grid
void printGrid(int grid[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%2d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to find an empty cell in the Sudoku grid
bool findEmptyCell(int grid[SIZE][SIZE], int *row, int *col)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (grid[i][j] == 0)
            { // Check if the cell is empty
                *row = i;
                *col = j;
                return true;
            }
        }
    }
    return false; // No empty cell found
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(int grid[SIZE][SIZE])
{
    int row, col;

    // Find the next empty cell
    if (!findEmptyCell(grid, &row, &col))
    {
        return true; // No empty cells left, puzzle is solved
    }

    // Try placing numbers from 1 to 9 in the empty cell
    for (int num = 1; num <= SIZE; num++)
    {
        if (isValidPlacement(row, col, num, grid))
        {
            grid[row][col] = num; // Place the number

            // Recursively try solving the rest of the puzzle
            if (solveSudoku(grid))
            {
                return true;
            }

            // Backtrack if no solution is found
            grid[row][col] = 0;
        }
    }

    return false; // No valid number can be placed, trigger backtracking
}
