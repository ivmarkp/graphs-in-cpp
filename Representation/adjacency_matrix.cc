/**
 * Adjacency matrix representation of a graph.
 *
 * E.g. Consider the following graph.
 * A --- B
 * | \   |
 * |  \  |
 * |   \ |
 * D --- C
 *
 * Adjacency matrix for this (undirected) graph is:
 *	   0 1 2 3
 *	  ---------
 * 0 | 0 1 1 1
 * 1 | 1 0 1 0
 * 3 | 1 1 0 1
 * 4 | 1 0 1 0
 */
#include <bits/stdc++.h>
using namespace std;

class graph {
	// No. of vertices and edges
	int v, e;
	// A pointer to a 2-D array or directly declare an array as
	// adj_matrix[][MAX_SIZE]
	int **adj_matrix;

	public:
		graph(int nv, int ne) {
			v = nv;
			e = ne;

			// Dynamically allocate memory for v rows
			adj_matrix = new int* [v];
			// Allocate memory for v columns
			for (int i = 0; i < v; i++) {
				adj_matrix[i] = new int [v];
				for (int j = 0; j < v; j++)
					adj_matrix[i][j] = 0;
			}
		}

		~graph() {delete []adj_matrix;}

		void add_edge(int u, int v) {
			adj_matrix[u][v] = 1;
			adj_matrix[v][u] = 1;
		}

		void print_matrix() {
			for (int i = 0; i < v; i++) {
				for (int j = 0; j < v; j++)
					cout << adj_matrix[i][j] << ' ';
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

	g.print_matrix();

	return 0;
}
/**
 * Pros: Representation is easier to implement and follow. Removing an edge
 * takes O(1) time. Queries like whether there is an edge from vertex ‘u’
 * to vertex ‘v’ are efficient and can be done O(1).
 *
 * Cons: Consumes more space O(V^2). Even if the graph is sparse(contains
 * less number of edges), it consumes the same space. Adding a vertex is
 * O(V^2) time.
 */