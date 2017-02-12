/**
 * Determine whether a given graph contains Hamiltonian Cycle or not. If
 * yes, then print the path.
 */
#include <bits/stdc++.h>
using namespace std;

bool isSafe(int u, auto& graph, vector<int>& path, int p) {
	// Check if the vertex is adjacent to the last added vertex
	if (graph[path[p-1]][u] == 0)
		return false;

	// Check if the vertex is already in hamiltonian path
	for (int i = 0; i < path.size(); i++)
		if (path[i] == u)
			return false;
	return true;
}

bool hamiltonian(int v, auto& graph, auto& path, int s, int index) {
	// If all vertices are included in Hamiltonian cycle
	if (index >= v) {
		// And if most recently inserted vertex is adjacent to the first
		// vertex
		if (graph[path[index-1]][path[0]]) {
			for (int i = 0; i < v; i++)
				cout << path[i] << ' ';
			cout << path[0] << endl;
		return true;
		}
		return false;
	}

	// Look for other vertices that can be included in path
	for (int i = 0; i < v; i++) {
		if (isSafe(i, graph, path, index)) {
			path[index] = i;

			// Recur
			if (hamiltonian(v, graph, path, s, index+1))
				return true;

			// Backtrack: If adding vertex i doesn't lead to a solution
			// (hamiltonian cycle), then remove it
			path[index] = -1;
		}
	}
	return false;
}

int main() {
	int v, s;
	cin >> v >> s;

	vector<vector<int>> graph(v, vector<int>(v));
	for (int i = 0; i < v; i++)
		for (int j = 0; j < v; j++)
			cin >> graph[i][j];

	// Initialise path vector to store hamiltonian path
	vector<int> path(v, -1);
	// First node of hamiltonian path is s
	path[0] = s;

	if (!hamiltonian(v, graph, path, s, 1))
		cout << "No solution exists...\n";

	return 0;
}
// #TODO: Analyse time complexity!