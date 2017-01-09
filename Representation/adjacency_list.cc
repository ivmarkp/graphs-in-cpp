/** Implementation of adjacency list representation of a graph.
 *  E.g. Consider the following graph
 *	A --- B
 *	| \   |
 *	|  \  |
 *	|	\ |
 *	D --- C
 *
 *  Adjacency matrix for this (undirected) graph is:
 *	 0 -> 1 -> 2 -> 3
 *	 1 -> 0 -> 2
 *	 2 -> 0 -> 1 -> 3
 *	 3 -> 0 -> 2
 */
#include <bits/stdc++.h>
using namespace std;

class graph {
	// No. of vertices and edges
	int v;
	int e;
	// A pointer to a vector(or array) of lists
	vector<list<int>> adj_list;

	public:
		graph(int nv, int ne) { 
			v = nv;
			e = ne;
			// Resize adj_list to contain v elements
			adj_list.resize(v);
		}

		~graph() {adj_list.clear();}

		void add_edge(int u, int v) {
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
		}

		void print_list() {
			for (int i = 0; i < adj_list.size(); ++i) {
				cout << i << ": ";
				for (auto li = adj_list[i].begin();
					 li != adj_list[i].end(); ++li)
					cout << *li << ' ';
				cout << endl;
    		}
		}
};

int main() {
	int nv, ne;
	cin >> nv >> ne;

	graph g(nv, ne);

	for (int i = 0; i < ne; i++) {
		int u, v;
		cout << "Create edge: ";
		cin >> u >> v;
		g.add_edge(u, v);
	}

	g.print_list();

	return 0;
}
/** Pros: Takes space O(|V|+|E|). In the worst case, there can be C(V, 2)
 *	number of edges in a graph thus consuming O(V^2) space.
 *	
 *	Cons: Queries like whether there is an edge from vertex u to vertex v
 *	are not efficient and take O(V) time. Deleting an edge is also ineffi-
 *	-cient as it might requires traversing a long list in a large graph.
