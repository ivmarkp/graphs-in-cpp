/**
 * Floyd-Warshal algorithm for all-pairs shortest paths using DP in a given
 * weighted directed Graph.
 */
#include <bits/stdc++.h>
using namespace std;

void floydWarshal(int v, vector<vector<int>>& graph) {
	// Output matrix to store computed shortest paths
	int out[v][v];

	// Initialise output matrix same as input graph matrix except
	// changing -1s with INT_MAX
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			if (graph[i][j] == -1)
				out[i][j] = INT_MAX;
			else
				out[i][j] = graph[i][j];
		}
	}

	for (int k = 0; k < v; k++)
		for (int i = 0; i < v; i++)
			for (int j = 0; j < v; j++)
				if (out[i][k] != INT_MAX && out[k][j] != INT_MAX)
					out[i][j] =  min(out[i][k] + out[k][j], out[i][j]);

	// Print the output matrix
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++) {
			if (out[i][j] == INT_MAX)
				cout << "~" << ' ';
			else
				cout << out[i][j] << ' ';
		}
		cout << endl;
	}
}


int main() {
	int v;
	cin >> v;

	vector<vector<int>> graph(v, vector<int>(v));
	// Input -1 if there's no edge between two vertices
	// Input 0 if vertices are same i.e. (u,u) or (v,v)
	for (int i = 0; i < v; i++)
		for (int j = 0; j < v; j++)
			cin >> graph[i][j];

	floydWarshal(v, graph);

	return 0;
}
// Time complexity: O(V^3)