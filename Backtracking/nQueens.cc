/**
 * Given an integer n, print all distinct solutions to the n-queens puzzle.
 */
#include <bits/stdc++.h>
using namespace std;

void printSolution(int n, vector<vector<int>>& board) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout <<  board[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}

bool isValid(int n, vector<vector<int>>& board, int row, int col) {
	// If two queens share the same column
	for(int i = 0; i < n; i++)
		if (board[row][i] == 1)
			return false;

    // If two queens share the same upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // If two queens share the same lower left diagonal
    for (int i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

void allSolutions(int n, vector<vector<int>>& board, int col) {
	if (col >= n) {
		printSolution(n, board);
		return;
	}

	// Try placing queens in this column in each row one by one
	for (int row = 0; row < n; row++) {
		if (isValid(n, board, row, col)) {
			board[row][col] = 1;

			// Recur to place rest of the queens in other cols
			allSolutions(n, board, col+1);

			// If placing in out[row][col] doesn't lead to a
			// solution then backtrack i.e. unmark out[row][col]
			board[row][col] = 0;
		}
	}
}

int main() {
	int n;
	cin >> n;

	// An output board to store each distinct solution
	vector<vector<int>> board(n, vector<int>(n, 0));

	// Look for solutions starting from col 0
	allSolutions(n, board, 0);

	return 0;
}
// #TODO: Analyse time complexity! Guess: O(n!)