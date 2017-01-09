/** Given a undirected graph, check whether the graph contains a cycle or not.
 *
 *	Note: Like directed graphs, we can use DFS to detect cycle in an undirected graph.
 *	For every visited vertex ‘v’, if there is an adjacent ‘u’ such that u has
 *	already been visited and u is not parent of v, then there is a cycle in graph.
 *	
 *	The assumption of this approach is that there are no parallel edges between any
 *	two vertices.
 */
#include <bits/stdc++.h>
using namespace std;

class graph {
    int nv;
    vector<list<int>> adj;
    // A utility function to be used by main "cyclic" function
    bool util(int s, vector<bool>& visited, int parent);
    public:
        graph(int num) : nv(num), adj(num) {}
    	void addEdge(int u, int v) {
    		// Birectional edges
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	bool cyclic();
};

bool graph::util(int s, vector<bool>& visited, int parent) {
	visited[s] = true;
	
	// Recur through all the adjacent vertices to the current vertex
	for (auto i = adj[s].begin(); i != adj[s].end(); ++i) {
		// If an adjacent vertex has not been visited then recur for it.
		if (!visited[*i]) {
			if(util(*i, visited, s))
				return true;
		}
		
		// If an adjacent has been visited and it's not the parent
		// then it forms a cycle in the graph.
		else if (*i != parent)
			return true;
	}
	return false;
}

bool graph::cyclic() {
	// Mark all vertices as not visited.
    vector<bool> visited(nv, false);
	
	// Call Util for each vertex.
    for (int i = 0; i < nv; i++) {
    	// Recur only if i has not been visited.
    	if (!visited[i]) {
        	if (util(i, visited, -1))
            	return true;
        }
    }
    return false;
}

int main() {
	graph g(4);
	
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 3);

	if (g.cyclic())
		cout << "Graph is cyclic.\n";
	else
		cout << "Not a cyclic graph.\n";
	
	return 0;
}
// Time Complexity: Same as DFS i.e. O(V + E).
