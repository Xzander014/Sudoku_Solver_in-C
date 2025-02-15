# Sudoku Solver in C

## Overview
This project is a Sudoku Solver written in C that uses backtracking to solve a given 9x9 Sudoku puzzle. The program takes an incomplete Sudoku grid as input and finds a valid solution if one exists.

## Features
- Uses backtracking to solve Sudoku puzzles efficiently.
- Checks for validity before placing numbers in the grid.
- Prints the solved Sudoku board to the console.

## Installation & Usage

### Compilation
To compile the program, use a C compiler like GCC:
```bash
gcc sudoku_solver.c -o sudoku_solver
```

### Running the Program
After compilation, run the executable:
```bash
./sudoku_solver
```

### Input
The Sudoku grid is defined in the `grid[9][9]` array inside `main()`. Modify it to test different puzzles.

### Example Output
**Given input Sudoku puzzle:**
```
 5  3  0  0  7  0  0  0  0  
 6  0  0  1  9  5  0  0  0  
 0  9  8  0  0  0  0  6  0  
 8  0  0  0  6  0  0  0  3  
 4  0  0  8  0  3  0  0  1  
 7  0  0  0  2  0  0  0  6  
 0  6  0  0  0  0  2  8  0  
 0  0  0  4  1  9  0  0  5  
 0  0  0  0  8  0  0  7  9  
```
**Solved Sudoku puzzle:**
```
 5  3  4  6  7  8  9  1  2  
 6  7  2  1  9  5  3  4  8  
 1  9  8  3  4  2  5  6  7  
 8  5  9  7  6  1  4  2  3  
 4  2  6  8  5  3  7  9  1  
 7  1  3  9  2  4  8  5  6  
 9  6  1  5  3  7  2  8  4  
 2  8  7  4  1  9  6  3  5  
 3  4  5  2  8  6  1  7  9  
```

## How It Works
1. Finds an empty cell (cell with `0`).
2. Attempts to place numbers from `1-9`, ensuring:
   - No duplicates in the same row.
   - No duplicates in the same column.
   - No duplicates in the 3x3 subgrid.
3. If a valid number is placed, it recursively tries to solve the rest of the puzzle.
4. If a conflict occurs, it backtracks and tries another number.
5. If no solution is possible, it reports "No solution exists."

## Code Structure
| Function  | Description |
|-----------|------------|
| `solver()` | Solves the Sudoku using backtracking. |
| `check()` | Checks if a number is valid at a given position. |
| `prnt()` | Prints the Sudoku grid. |
| `isepty()` | Checks if a cell is empty. |

## Contributing
Feel free to fork this repository and submit pull requests with improvements or additional features.

## License
This project is open-source and available under the MIT License.

