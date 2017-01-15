/**
 * Prim’s MST algorithm for adjacency list representation of undirected,
 * connected and weighted graphs.
 */
#include <bits/stdc++.h>
using namespace std;

class graph {
    int nv;
    // A weighted graph, so need to store a vertex and
    // weight pair for every single vertex.
    vector<vector<pair<int, int>>> adj;
    public:
        graph(int num) : nv(num), adj(num) {}
    	void addEdge(int u, int v, int wt) {
    		adj[u].push_back(make_pair(v, wt));
    		adj[v].push_back(make_pair(u, wt));
    	}
    	void prims(int s);
    	void print_mst();
};

void graph::prims(int s) {
	// Create a min-heap using priority_queue container. priority_queue
	// container constructor requires two extra arguments to make it a
	// min heap i.e. vector<...> & greater<...>.
	priority_queue<pair<int, int>, vector<pair<int, int>>,
				   greater<pair<int, int>> > heap;

	// A vector to store weights of vertices with all weights
	// intialised as INT_MAX.
	vector<int> weight(nv, INT_MAX);
	// Another vector to store the parent of vertices.
	vector<int> parent(nv, -1);
	// A vector to keep track of vertices included in MST.
	vector<bool> mst(nv, false);

	// Set weight of source vertex as zero.
	weight[s] = 0;

	// Insert source vertex in the heap.
	heap.push(make_pair(weight[s], s));

	while (!heap.empty()) {
		// Extract the min vertex based on their associated weights.
		int u = heap.top().second;
		heap.pop();

		// Include extracted vertex in mst.
		mst[u] = true;

		for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
			// Get the vertex label and the weights
			int v = (*i).first;
			int v_wt = (*i).second;

			// If v is not in mst and edge (u, v) weight < weight of v
			if (mst[v] == false && v_wt < weight[v]) {
				// Update weight of v
				weight[v] = v_wt;
				heap.push(make_pair(weight[v], v));
				// Update parent of v
				parent[v] = u;
			}
		}
	}
	for (int i = 1; i < nv; i++)
		cout << parent[i] << " -> " << i << endl;
	cout << endl;
}


int main() {
	graph g(5);

	g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 7);
    g.addEdge(2, 3, 4);
    g.addEdge(3, 4, 6);

	g.prims(0);

	return 0;
}
// Time complexity : O(E*Log V))