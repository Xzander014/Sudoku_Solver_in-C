#include <stdio.h>
#include <stdbool.h>

const int N = 9;

int check(int row, int column, int num, int grid[N][N]);
void prnt(int grid[N][N]);
int solver(int grid[N][N]);
int isepty(int grid[N][N], int i, int j);

int main() {
    int grid[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solver(grid)) {
        printf("Result\n");
        prnt(grid);
    } else {
        printf("No solution Exists\n");
    }

    return 0;
}

int check(int row, int column, int num, int grid[N][N]) {
    int startrow, startclm;
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num || grid[i][column] == num) {
            return 0;
        }
    }
    startrow = row - row % 3;
    startclm = column - column % 3;
    for (int i = startrow; i < startrow + 3; i++) {
        for (int j = startclm; j < startclm + 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

void prnt(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d", grid[i][j]);
        }
        printf("\n");
    }
}

int isepty(int grid[N][N], int i, int j) {
    if (grid[i][j] == 0) {
        return 1;
    }
    return 0;
}

int solver(int grid[N][N]) {
    int row = -1, col = -1;
    bool empty = false;

    // Find the first empty cell
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (isepty(grid, i, j)) {
                row = i;
                col = j;
                empty = true;
                break;
            }
        }
        if (empty)
            break;
    }

    // If no empty cell is found, the puzzle is solved
    if (!empty) {
        return 1;
    }

    // Try placing numbers from 1 to 9 in the current cell
    for (int num = 1; num <= 9; num++) {
        if (check(row, col, num, grid)) {
            grid[row][col] = num; // Place the number

            // Recursively solve the rest of the puzzle
            if (solver(grid)) {
                return 1; // If solved, return success
            }

            // Backtrack: Reset the cell if the number doesn't lead to a solution
            grid[row][col] = 0;
        }
    }

    // If no number can be placed in the current cell, backtrack
    return 0;
}