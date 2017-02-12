// Recursive Depth First traversal of a graph.
#include <bits/stdc++.h>
using namespace std;

class graph {
    int nv;
    // Adjacency list representation i.e. an array of lists.
    vector<list<int>> adj;
    void traverse(int v, vector<bool>& visited);

    public:
        graph(int num) : nv(num), adj(num) {}
    	void addEdge(int u, int v) { adj[u].push_back(v); }
    	void dfs();
};

void graph::traverse(int v, bool visited []) {
	// Mark the current vertex as visited & print it.
	visited[v] = true;
	cout << v << ' ';

	// Traverse all the adjacent vertices to the current vertex.
	for (auto it = adj[v].begin(); it != adj[v].end(); ++it)
		if (visited[*it] == 0)
			traverse(*it, visited);
}

void graph::dfs() {
	// Create a boolean "visited" array of size V.
    vector<bool> visited(nv, false);

	// Call the recursive traverse function for each vertex.
    for (int i = 0; i < nv; i++)
        if (visited[i] == false)
            traverse(i, visited);
}

int main() {
	graph g(4);

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	// Print DFS traversal.
	g.dfs();
	cout << endl;

	return 0;
}

/**
 * Time Complexity: O(V+E) where V is number of vertices & E is number of
 * edges.
 *
 * Note: The above implementation does the complete graph traversal even
 * if the nodes are unreachable (e.g. in a disconnected graph). To do so,
 * traverse() must be called for every vertex. Before calling traverse(),
 * we need to check if the current vertex was already printed by some other
 * instance of traverse().
 */