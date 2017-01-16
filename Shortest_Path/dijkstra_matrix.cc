/**
 * Djikstra's shortest path algorithm for adjacency matrix representation
 * of undirected, connected and weighted graphs.
 */
#include <bits/stdc++.h>
using namespace std;

int minDist(vector<bool>& spt, vector<int>& dist, int v) {
	int min = INT_MAX, index = 0;

	for (int i = 0; i < v; i++) {
		if (spt[i] == false && dist[i] < min) {
			min = dist[i];
			index = i;
		}
	}

	return index;
}

void djikstra(vector<vector<int>>& g, int v, int s) {

	vector<bool> spt_set(v, false);
	vector<int> dist(v, INT_MAX);
	vector<int> parent(v);

	dist[s] = 0;
	parent[s] = -1;

	for (int i = 0; i < v; i++) {

		int u = minDist(spt_set, dist, v);
		spt_set[u] = true;

		for (int j = 0; j < v; j++) {
			if (spt_set[j] == false && g[u][j] != 0
									&& dist[u] + g[u][j] < dist[j]) {
				dist[j] = dist[u] + g[u][j];
				parent[j] = u;
			}
		}
	}

	// Print the shortest path edges.
	for (int i = 1; i < v; i++)
		// Starting from i = 1 because parent[0] = -1
		cout << parent[i] << " -- " << i << endl;
}

int main() {
	int nv;
	cin >> nv;

	// A square matrix of size nv to represent the graph.
	vector<vector<int>> graph(nv, vector<int>(nv));

	for (int i = 0; i < nv; i++)
		for (int j = 0; j < nv; j++)
			cin >> graph[i][j];

	int source;
	cin >> source;

	djikstra(graph, nv, source);

	return 0;
}
// Time Complexity: O(V^2). It can be reduced to O(E * logV) by trading
// space for a binary heap.