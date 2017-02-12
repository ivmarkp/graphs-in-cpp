/**
 * Prim’s MST algorithm for adjacency matrix representation of undirected,
 * connected and weighted graphs.
 */
#include <bits/stdc++.h>
using namespace std;

int findMinKeyVertex(vector<int>& k, vector<bool>& mst, int v) {
	int min = INT_MAX, index;
	for (int i = 0; i < v; i++) {
		if (mst[i] == false && k[i] < min) {
			min = k[i];
			index = i;
		}
	}
	return index;
}

void primsMST(vector<vector<int>>& graph, int v) {
	// A vector for key values of all vertices with all keys initialised
	// as INT_MAX.
	vector<int> key(v, INT_MAX);

	// A boolean vector to represent set of vertices included in MST.
	vector<bool> InMST(v, false);

	// A vector to store indices of parents in MST.
	vector<int> parent(v);

	// Starting from vertex 0 so set its key as 0 and as it is the root of
	// MST so set its parent as -1.
	key[0] = 0;
	parent[0] = -1;

	for (int i = 0; i < v; i++) {
		// Find the min key vertex from the set of vertices
		// not included in MST.
		int u = findMinKeyVertex(key, InMST, v);

		// Mark min key vertex as included in MST.
		InMST[u] = true;

		// Update keys and parents of the adjacent vertices.
		for (int j = 0; j < v; j++) {
			if (graph[u][j] && InMST[j] == false
				&& graph[u][j] < key[j])
				parent[j] = u, key[j] = graph[u][j];
		}
	}

	// Print the edges of MST.
	for (int i = 1; i < v; i++)
		cout << parent[i] << " - " << i << endl;
}

int main() {
	int nv;
	cin >> nv;

	vector<vector<int>> graph(nv, vector<int>(nv));

	for (int i = 0; i < nv; i++)
		for (int j = 0; j < nv; j++)
			cin >> graph[i][j];

	primsMST(graph, nv);

	return 0;
}
// Time Complexity : O(V^2). With adjacency list representation, the time
// complexity can be reduced to O(E*logV) with the help of a binary heap.