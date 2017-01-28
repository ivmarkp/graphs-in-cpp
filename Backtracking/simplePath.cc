/**
 * Find if there is a simple path (without any cycle) starting from the
 * given source vertex and ending at any other vertex of length > k.
 */
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> intPair;

bool findPath(vector<vector<intPair>>& adj, vector<bool>& visited,
			  int k , int src) {
	if (k <= 0)
		return true;

	// Explore all paths from s recurvisely via its adjacent vertices
	for (auto it = adj[src].begin(); it != adj[src].end(); ++it) {
		int v = (*it).first;
		int v_wt = (*it).second;

		// If the current adjacent is already visited, skip it
		if (visited[v])
			continue;

		// If weight of this vertex is more than, equal to k; return
		// true otherwise mark this vertex in visited array
		if (v_wt >= k)
			return true;

		visited[v] = true;

		// Recur to check this vertex's weight is more than k
		// and src is now updated to v
		if (findPath(adj, visited, k-v_wt, v))
			return true;

		// Else backtrack
		visited[v] = false;
	}
	return false;
}

int main() {
	int nv, e, k, src;
	cin >> nv >> e >> k >> src;

	// Create adjacency list
	vector<vector<intPair>> adj(nv);
	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}

	// A visited vector to store visited path vertices
	vector<bool> visited(nv, false);
	visited[src] = true;

	// Check if a simple 	path exists
	if (!findPath(adj, visited, k , src))
		cout << "No simple path exists...\n";
	else
		cout << "Path exists...\n";
	return 0;
}
// Time Complexity: O(n!)