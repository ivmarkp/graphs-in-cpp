/**
 * Djikstra's shortest path algorithm for adjacency list representation of
 * undirected, connected and weighted graphs.
 */
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pairInt;

void djikstra(vector<vector<pairInt>>& adj, int v, int s) {
	set<pairInt> eset;
	vector<int> dist(v, INT_MAX);
	vector<int> parent(v);

	dist[s] = 0;
	parent[s] = -1;

	eset.insert(make_pair(dist[s], s));

	while (!eset.empty()) {
		pairInt upair = *(eset.begin());
		eset.erase(eset.begin());

		int ulabel = upair.second;

		for (auto it = adj[ulabel].begin(); it != adj[ulabel].end(); ++it) {
			int v = (*it).first;
			int dist_v = (*it).second;

			// Update distance of v from source if there's
			// a shorter path to v via u.
			if (dist[v] > dist[ulabel] + dist_v) {
				// If v in the set, remove it and insert again
                // with updated less distance.
                if (dist[v] != INT_MAX)
                	eset.erase(eset.find(make_pair(dist[v], v)));

				dist[v] = dist[ulabel] + dist_v;
				// Update parent of v as u.
				parent[v] = ulabel;
				// Insert v and its updated distance in min heap.
				eset.insert(make_pair(dist[v], v));
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
// Time complexity : O(E * Log V))