/**
 * Djikstra's shortest path algorithm for adjacency list representation
 * of undirected, connected and weighted graphs.
 */
#include <bits/stdc++.h>
using namespace std;

class Graph {
	int v;
	vector<vector<pair<int, int>>> adj;
	public:
		Graph(int nv) : v(nv), adj(nv) {}
		void addEdge(int u, int v, int wt) {
			adj[u].push_back(make_pair(v, wt));
			adj[v].push_back(make_pair(u, wt));
		}
		void djikstra(int s);
};

void Graph::djikstra(int s) {
	priority_queue<pair<int, int>, vector<pair<int, int>>,
				   greater<pair<int, int>>> heap;

	vector<int> dist(v, INT_MAX);
	vector<int> parent(v);

	dist[s] = 0;
	parent[s] = -1;

	heap.push(make_pair(s, dist[s]));

	while (!heap.empty()) {
		int u = heap.top().first;
		heap.pop();

		for (auto it = adj[u].begin(); it != adj[u].end(); ++it) {
			int v = (*it).first;
			int dist_v = (*it).second;

			// Update distance of v from source if there's
			// a shorter path to v via u.
			if (dist[v] > dist[u] + dist_v) {
				dist[v] = dist[u] + dist_v;
				// Update parent of v as u.
				parent[v] = u;
				// Push v and its updated distance in min heap.
				heap.push(make_pair(v, dist[v]));
			}
		}
	}

	// Print the shortest path edges
	for (int i = 1; i < v; i++)
		cout << parent[i] << " -- " << i << endl;
}

int main() {

	Graph g(9);

	g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

	int source;
	cin >> source;

	g.djikstra(source);

	return 0;
}
// Time complexity : O(E * Log V))