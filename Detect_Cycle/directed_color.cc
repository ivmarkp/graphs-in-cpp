/** Given a directed graph, check whether the graph contains a cycle or not.
 *
 *	Note: The idea is to do DFS of given graph and while doing traversal, assign
 *	one of the three colors (white, gray, black) to every vertex.
 */
#include <bits/stdc++.h>
using namespace std;

enum COLOR {WHITE, GRAY, BLACK};

class graph {
    int nv;
    vector<list<int>> adj;
    // A utility function to be used by main "cyclic" function
    bool util(int s, vector<int>& color);
    public:
        graph(int num) : nv(num), adj(num) {}
    	void addEdge(int u, int v) {
    		adj[u].push_back(v);
    	}
    	bool cyclic();
};

bool graph::util(int s, vector<int>& visited) {
	if (visited[s] == false) {
		
		visited[s] = GRAY;

		// Recur through all the adjacent vertices to the current vertex
		for (auto i = adj[s].begin(); i != adj[s].end(); ++i) {
			// If the current vertex has not been processed and there is
			// a back edge in subtree rooted at it.
			if (visited[*i] == WHITE && util(*i, visited))
				return true;
			if (visited[*i] == GRAY)
				return true;
		}
	}
	// Mark the vertex as fully processed.
	visited[s] = BLACK;
	
	return false;
}

bool graph::cyclic() {
	// Mark all vertices as not visited.
    vector<int> color(nv, WHITE);
	
	// Call Util for each vertex.
    for (int i = 0; i < nv; i++) {
    	// Returns true if a cycle is present in the graph.
        if (util(i, color))
            return true;
    }
    
    return false;
}

int main() {
	graph g(4);
	
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 3);
	g.addEdge(3, 1);

	if (g.cyclic())
		cout << "Graph is cyclic.\n";
	else
		cout << "Not a cyclic graph.\n";
	
	return 0;
}
// Time Complexity: Same as DFS i.e. O(V + E).
