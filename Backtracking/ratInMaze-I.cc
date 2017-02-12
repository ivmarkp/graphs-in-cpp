/**
 * Consider a rat placed at (0, 0) in a square matrix of order n and with a
 * destination to reach at (n-1, n-1). Find one possible path to do so.
 * Store the path in a binary output matrix. The directions in which the
 * rat can move are right and down only.
 */
#include <bits/stdc++.h>
using namespace std;

bool isValid(int n, int x, int y, vector<vector<int>>& in) {
	if (x >= 0 && x < n && y >=0 && y < n && in[x][y] == 1)
		return true;
	return false;
}

bool findPathHelper(int n, int x, int y, auto& out, auto& in) {
	if (x == n - 1 && y == n -1) {
		out[x][y] = 1;
		return true;
	} else {
		if (isValid(n, x, y, in)) {
			out[x][y] = 1;

			// Explore righward path
			if (findPathHelper(n, x+1, y, out, in))
				return true;

			// Explore downward path
			if (findPathHelper(n, x, y+1, out, in))
				return true;

			// If path not found yet then backtrack i.e. unmark x, y
			out[x][y] = 0;
			return false;
		}
		return false;
	}
}

void findPath(int n, vector<vector<int>>& in) {
	// Output matrix with all cells initialised to zero
	vector<vector<int>> outMaze(n, vector<int>(n, 0));

	findPathHelper(n, 0, 0, outMaze, in);

	// Print output matrix with solution path
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << outMaze[i][j] << ' ';
		cout << endl;
	}

}

int main() {
	int n;
	cin >> n;

	vector<vector<int>> inMaze(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> inMaze[i][j];

	findPath(n, inMaze);

	return 0;
}
// #TODO: Analyse time complexity!