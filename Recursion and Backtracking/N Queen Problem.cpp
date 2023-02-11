#include <iostream>
using namespace std;

bool check(int grid[4][4], int row, int col) {
	int i, j;
	/*Check the row on the left side*/
	for (i = 0; i < col; i++) {
		if (grid[row][i])
			return false;
	}
	/*Check the upper diagonal on the left side*/
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
		if (grid[i][j])
			return false;
	}
	/*Check the lower diagonal on the left side*/
	for (i = row, j = col; i < 4 && j >= 0; i++, j--) {
		if (grid[i][j])
			return false;
	}
	return true;
}

int SolveNQueen(int grid[4][4], int col) {
	if (col >= 4)
		return true;
	for (int i = 0; i < 4; i++) {
		/*check if the queen can be placed, then place it */
		if (check(grid, i, col)) {
			grid[i][col] = 1;

			/*Recursively call function to place rest of the queens*/
			if (SolveNQueen(grid, col + 1))
				return true;

			/*If placing queens on the grid does not lead to the solution, then backtrack and remove the queen*/
			grid[i][col] = 0;  //Backtracking
		}
	}
	return false;
}

void printGrid(int grid[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int grid[4][4] = { { 0, 0, 0, 0 },
					   { 0, 0, 0, 0 },
					   { 0, 0, 0, 0 },
					   { 0, 0, 0, 0 } };

	if (SolveNQueen(grid, 0) == false)
		cout << "Solution does not exits!";
	else 
		printGrid(grid);

	return 0;
}