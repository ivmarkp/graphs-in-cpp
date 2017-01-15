/**
 * Kruskal's algorithm to find MSTof a given connected, undirected and
 * weighted graph.
 */
#include <bits/stdc++.h>
using namespace std;

// DisjointSet class to implements Find and Union operations.
class DisjointSet {
	unordered_map<int, int> parent;
	unordered_map<int, int> rank;
	public:
		DisjointSet(int n) {
			for (int i = 0; i < n; i++) {
				parent.insert(pair<int, int>(i, i));
				rank.insert(pair<int, int>(i, 0));
			}
		}
		int Find(int x) {
			if (parent[x] == x)
				return x;
			else
				return Find(parent[x]);
		}
		void Union(int x, int y) {
			if (rank[x] > rank[y])
				parent[y] = x;
			else if (rank[y] > rank[x])
				parent[x] = y;
			else if (rank[x] == rank[y]) {
				parent[x] = y;
				rank[y]++;
			}
		}
};

class Graph {
	int v, e;
	vector<pair<int,pair<int,int>>> edges;
	public:
		Graph(int nv, int ne) : v(nv),  e(ne) {}
		void add_edge(int u, int v, int wt) {
			edges.push_back(make_pair(wt, make_pair(u, v)));
		}
		void kruskal();
};

void Graph::kruskal() {
	DisjointSet dset(v);

	sort(edges.begin(), edges.end());

	vector<pair<int, pair<int, int>>> mst;
	int mst_wt = 0;

	for (auto it = edges.begin(); it != edges.end(); ++it) {
		int u = it->second.first, v = it->second.second;
		int u_set = dset.Find(u), v_set = dset.Find(v);

		if (u_set != v_set) {
			mst.push_back(make_pair(it->first, make_pair(u, v)));
			dset.Union(u_set, v_set);
			mst_wt += it->first;
		}
	}
	cout << mst_wt << endl;
}

int main() {
	Graph g(6, 8);

	g.add_edge(0, 1, 4);
	g.add_edge(0, 5, 2);
	g.add_edge(1, 2, 6);
	g.add_edge(1, 5, 5);
	g.add_edge(2, 3, 3);
	g.add_edge(2, 5, 1);
	g.add_edge(3, 4, 2);
	g.add_edge(4, 5, 4);

	g.kruskal();

	return 0;
}
// Time Complexity: O(E * LogE) for sorting edges + O(LogV) time for
// find-union algorithm So, overall complexity is O(E * LogE + LogV).