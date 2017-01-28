/**
 * Check whether there is a path from the first given vertex to  the second in
 * a given directed graph.
 */
#include <bits/stdc++.h>
using namespace std;

bool checkPath(vector<vector<int>>& adj, vector<bool>& visited,
			   int src, int dest) {
	queue<int> q;

	visited[src] = true;
	q.push(src);

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (auto it = adj[u].begin(); it != adj[u].end(); ++it) {
			// If an adjacent vertex is destination node, return true.
			if (u == dest)
			return true;

			if (visited[*it] == false) {
				visited[*it] = true;
				q.push(*it);
			}
		}
	}
	return false;
}

int main() {
	int nv, ne, src, dest;
	cin >> nv >> ne >> src >> dest;

	vector<vector<int>> adj(nv);
	for (int i = 0; i < ne; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	vector<bool> visited(nv, false);
	// Using simple BFS. Could use DFS as well.
	if (!checkPath(adj, visited, src, dest))
		cout << "No path found...\n";
	else
		cout << "Path do exists from "<< src << " to " << dest << "\n";

	return 0;
}
// Time Complexity: O(V+E) i.e. same as DFS or BFS