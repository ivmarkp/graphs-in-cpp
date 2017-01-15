/**
 * Iterative depth first traversal of a graph.
 *
 * Note: The recursive implementation uses function call stack. In iterative
 * implementation, an explicit stack is used to hold visited vertices. The
 * implementation is similar to BFS, the only difference is queue is replaced
 * by stack.
 */
#include <bits/stdc++.h>
using namespace std;

class graph {
    int nv;
    vector<list<int>> adj;
    void traverse(int s, vector<bool>& visited);

    public:
        graph(int num) : nv(num), adj(num) {}
    	void addEdge(int u, int v) {
    		adj[u].push_back(v);
    	}
    	void bfs();
};

void graph::traverse(int s, vector<bool>& visited) {
    stack<int> st;

    // Push the current source node.
    st.push(s);

    while(!st.empty()) {
        // Pop the front element.
        int p = st.top();
        st.pop();

        // Stack may contain same vertex twice. So, print the
        // popped item, only if it has not been visited.
        if (!visited[p]) {
            cout << p << " ";
            visited[p] = true;
        }

        // Go through all the adjacent vertices of popped
        // vertex one by one and if it has not been visited,
        // then mark it visited and push it onto stack.
        for(auto it = adj[p].begin(); it != adj[p].end(); ++it)
            if(!visited[*it])
                st.push(*it);
	}
}

void graph::bfs() {
    vector<bool> visited(nv, false);

	// Call Util to print bFS traversal from each vertex.
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
	g.bfs();
	cout << endl;

	return 0;
}
// Like recursive traversal, its time complexity is O(V+E) as well.