/** Implementation of topological sorting algorithm for a DAG.
 *
 *	Note: Topological sorting for a Directed Acyclic Graph (DAG) is a linear
 *	ordering of vertices such that for every directed edge uv, vertex u comes
 *	before v in the ordering. Topological sorting for a graph is not possible
 *	if the graph is not a DAG.
 *
 *	We can modify DFS to find topological sorting of a DAG. In DFS, we start
 *	from a vertex, we first print it and then recursively call DFS for its adj-
 *	-acent vertices. In topological sorting, we use a temporary stack. We don’t
 *	print the vertex immediately, first recursively call topological sorting for
 *	all its adjacent vertices, then push it to a stack. Finally, print the cont-
 *	-ents of stack. A vertex is pushed onto stack only when all of its adjacent
 *	vertices (and their adjacent vertices and so on) are already in stack.
 */
#include <bits/stdc++.h>
using namespace std;

class graph {
    int nv;
    // Adjacency list representation i.e. an array of lists.
    vector<list<int>> adj;
    void util(int v, vector<bool>& visited, stack<int>& st);
    
    public:
        graph(int num) : nv(num), adj(num) {}
    	void addEdge(int u, int v) {
    		adj[u].push_back(v);
    	}
    	void top_sort();
};

void graph::util(int v, vector<bool>& visited, stack<int>& st) {
	// Mark the current vertex as visited.
	visited[v] = true;
	
	// Traverse all the unvisited adjacent vertices.
	for (auto it = adj[v].begin(); it != adj[v].end(); ++it)
		if (visited[*it] == 0)
			util(*it, visited, st);
	
	// Push the current vertex onto stack
	st.push(v);
}

void graph::top_sort() {
	// Create a boolean "visited" array of size V.
    vector<bool> visited(nv, false);
    stack<int> st;

	// Call the recursive traverse function for each vertex.
    for (int i = 0; i < nv; i++)
        if (visited[i] == false)
            util(i, visited, st);
    
    // Print the contents of stack
    while (!st.empty()) {
    	cout << st.top() << ' ';
    	st.pop();
    }
}

int main() {
	graph g(4);
	
	g.addEdge(0, 2);
	g.addEdge(0, 3);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	
	// Print topological sort.
	g.top_sort();
	cout << endl;
	
	return 0;
}
