/**
 * Given a directed graph, check whether the graph contains a cycle or not.
 *
 * Note: There is a cycle in a graph only if there is a back edge present
 * in it. A back edge is an edge that is from a node to itself (self-loop)
 * or one of its ancestor i.e. an edge to the next node will form a cycle,
 * only if that node is an ancestor of the present node.
 *
 * To detect back edge, we can keep track of vertices currently in recursion
 * stack of function for DFS traversal. If we reach a vertex that is already
 * in the recursion stack, then there is a cycle in the tree.
 */
#include <bits/stdc++.h>
using namespace std;

class graph {
    int nv;
    vector<list<int>> adj;
    // A utility function to be used by main "cyclic" function
    bool util(int s, vector<bool>& visited, vector<bool>& recur_stack);

    public:
        graph(int num) : nv(num), adj(num) {}
    	void addEdge(int u, int v) {
    		adj[u].push_back(v);
    	}
    	bool cyclic();
};

bool graph::util(int s, auto& visited, auto& recur_stack) {
	if (visited[s] == false) {

		// Mark the current vertex visited and a part of recur_stack.
		visited[s] = true;
		recur_stack[s] = true;

		// Recur through all the adjacent vertices to the current vertex
		for (auto i = adj[s].begin(); i != adj[s].end(); ++i) {
			// If an adjacent has not been visited then recur for it.
			if (!visited[*i]) {
				if (util(*i, visited, recur_stack))
					return true;
			}
			// If an adjacent has been visited and is present in the
			// recur_stack then it forms a cycle in the graph.
			else if (recur_stack[*i])
				return true;
		}
	}
	// Set the current vertex as false in recur_stack
	// to mark it as removed from it.
	recur_stack[s] = false;

	return false;
}

bool graph::cyclic() {
	// Mark all vertices as not visited.
    vector<bool> visited(nv, false);
    vector<bool> recur_stack(nv, false);

	// Call Util for each vertex.
    for (int i = 0; i < nv; i++) {
    	// Returns true if a cycle is present in the graph.
        if (util(i, visited, recur_stack))
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