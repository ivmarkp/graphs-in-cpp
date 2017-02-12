/**
 * Given a boolean matrix, find the number of islands.
 *
 * Note: A group of connected 1s forms an island.
 */
#include <bits/stdc++.h>
using namespace std;

int rk[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int ck[] = {1, 1, 1, 0, -1, -1, -1, 0};

bool isSafe(auto& graph, int i, int j, auto& visited, int row, int col) {

	return (i >= 0 && i < row && j >= 0 && j < col
		   && graph[i][j] == 1 && !visited[i][j]);
}

void dfs(auto& graph, int i, int j, auto& visited, int row, int col) {
	visited[i][j] = true;

	for (int k = 0; k < 8; k++)
		if (isSafe(graph, i + rk[k], j + ck[k], visited, row, col))
			dfs(graph, i + rk[k], j + ck[k], visited, row, col);
}

int countIslands(int row, int col, auto& graph, auto& visited) {
	int count = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (graph[i][j] == 1 && !visited[i][j]) {
				dfs(graph, i, j, visited, row, col);
				count++;
			}
	return count;
}

int main() {
	int row, col;
	cin >> row >> col;

	vector<vector<bool>> graph(row, vector<bool>(col));
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			bool val; cin >> val;
			graph[i][j] = val;
		}

	vector<vector<bool>> visited(row, vector<bool>(col, false));

	cout << countIslands(row, col, graph, visited) << endl;

	return 0;
}
// Time Complexity: O(row*col)