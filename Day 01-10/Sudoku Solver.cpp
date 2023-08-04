#include <bits/stdc++.h> 

bool isSafe(vector<vector<int>>& sudoku, int row, int col, int val) {
    for(int i=0; i<9; i++) {
        // Row check
        if(sudoku[row][i] == val) {
            return false;
        }
    
        // Column check
        if(sudoku[i][col] == val) {
            return false;
        }

        // 3x3 Matrix check
        if(sudoku[3*(row/3) + i/3][3*(col/3) + i%3] == val) {
            return false;
        }
    }

    return true;
}

bool solve(vector<vector<int>>& sudoku) {

    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {

            // Checking empty slot
            if(sudoku[i][j] == 0) {
                // Trying Values from (1-9)
                for(int val=1; val<=9; val++) {
                    if(isSafe(sudoku, i, j, val)) {
                        sudoku[i][j] = val;

                        bool nextSol = solve(sudoku);
                        if(nextSol) {
                            return true;
                        } else {
                            // Backtracking
                            sudoku[i][j] = 0;
                        }
                    }
                }

                return false;
            }

        }
    }

    return true;
}

void solveSudoku(vector<vector<int>>& sudoku) {
	// Write your code here
    // No need to print the final sudoku
    // Just fill the values in the given matrix

    solve(sudoku);

}
