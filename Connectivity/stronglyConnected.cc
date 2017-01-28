/**
 * Given a directed graph, find out whether the graph is strongly connected.
 * A graph is strongly connected if there is a path between every pair of
 * vertices which not necessarily be a _direct_ path.
 *
 * Note: For undirected graphs however, we just do a BFS and DFS starting from
 * any vertex. If BFS or DFS visits all vertices, then the given undirected
 * graph is connected. This simple approach doesn't work for a directed graph.
 *
 * For directed graph, one solution is to do DFS V times starting from each
 * vertex. If any DFS, doesn’t visit all vertices, then graph is not strongly
 * connected. This algorithm takes O(V*(V+E)) time.
 *
 * A better idea can be Strongly Connected Components (SCC) algorithm. We can
 * find all SCCs in O(V+E) time. If number of SCCs is one, then graph is strongly
 * connected.
 */
#include <bits/stdc++.h>
using namespace std;

void transpose(vector<vector<int>>& adj, int nv) {
	vector<vector<int>> adj_temp(nv);
	for (int u = 0; u < nv; u++)
		for (auto it = adj[u].begin(); it != adj[u].end(); ++it)
			adj_temp[*it].push_back(u);
	adj = adj_temp;
}

void dfs(vector<vector<int>>& adj, vector<bool>& visited, int v) {
	visited[v] = true;

	for (auto it = adj[v].begin(); it != adj[v].end(); ++it)
		if (visited[*it] == false)
			dfs(adj, visited, *it);
}

bool isStronglyConnected(vector<vector<int>>& adj, vector<bool>& visited,
						 int nv) {
	// DFS traversal starting from the first vertex
	dfs(adj, visited, 0);

	// If dfs traversal doesn't visit all vertices, return false
	for (int i = 0; i < nv; i++)
		if (visited[i] == false)
			return false;

	// Reverse the graph
	transpose(adj, nv);

	// Mark all vertices as unvisited
	vector<bool> unvisited(nv, false);
	visited = unvisited;

	// DFS traversal of reversed graph
	dfs(adj, visited, 0);

	// If dfs traversal doesn't visit all vertices, return false
	for (int i = 0; i < visited.size(); i++)
		if (visited[i] == false)
			return false;

	return true;
}


int main() {
	int nv, ne;
	cin >> nv >> ne;

	vector<vector<int>> adj(nv);
	for (int i = 0; i < ne; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	vector<bool> visited(nv, false);

	if (!isStronglyConnected(adj, visited, nv))
		cout << "Not a strongly connected directed graph.\n";
	else
		cout << "It's a strongly connected directed graph.\n";

	return 0;
}
// Time Complexity: Same as DFS i.e. O(V+E)