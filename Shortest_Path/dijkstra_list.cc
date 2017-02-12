/**
 * Djikstra's shortest path algo. for adjacency list representation of
 * undirected, connected and weighted graphs.
 */
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pairInt;

void djikstra(auto& adj, int v, int s) {
	priority_queue<pairInt, vector<pairInt>, greater<pairInt>> heap;

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

	// Print the shortest path edges with their respective weights.
	for (int i = 0; i < v; i++)
		if (parent[i] != -1)
			cout << parent[i] << " -- " << i << " : " << dist[i] << endl;
}

int main() {
	int vertices, edges, source;
	cin >> vertices >> edges >> source;

	vector<vector<pairInt>> adj(vertices);

	int u, v, wt;
	for (int i = 0; i < edges; i++) {
		cin >> u >> v >> wt;
		adj[u].push_back(make_pair(v, wt));
		adj[v].push_back(make_pair(u, wt));
	}

	djikstra(adj, vertices, source);

	return 0;
}
// Time complexity : O(E * Log V)).
// #TODO Can be further improved by using a fibonaci heap instead of using
// a binary heap.