/**
 * Given a directed graph, find out if a vertex j is reachable from another
 * vertex i for all vertex pairs. Here reachable mean that there is a path
 * from vertex i to j
 *
 * Note:  The reach-ability matrix is called transitive closure of a graph
 * i.e. graph[i][j] is 1 if there is an edge from vertex i to vertex j or
 * i is equal to j, otherwise graph[i][j] is 0.
 */
#include <bits/stdc++.h>
using namespace std;

void transitiveClosure(int nv, vector<vector<bool>> graph) {
	vector<vector<bool>> res(nv, vector<bool>(nv));

	// Initialise output matrix same as input graph matrix
	res = graph;

	for (int k = 0; k < nv; k++) {
        // Pick all vertices as source one by one
        for (int i = 0; i < nv; i++) {
            // Pick all vertices as destination for the above source
            for (int j = 0; j < nv; j++) {
                // If vertex k is on a path from i to j, then
                // set value of reach[i][j] as 1.
                res[i][j] = res[i][j] || (res[i][k] && res[k][j]);
            }
        }
    }

    // Print transitive closure
    for (int i = 0; i < nv; i++) {
    	for (int j = 0; j < nv; j++)
    		cout << res[i][j] << ' ';
    	cout << endl;
    }

}

int main() {
	int nv;
	cin >> nv;

	vector<vector<bool>> graph(nv, vector<bool>(nv));
	for (int i = 0; i < nv; i++)
		for (int j = 0; j < nv; j++) {
			bool val; cin >> val;
			graph[i][j] = val;
		}

	transitiveClosure(nv, graph);

	return 0;
}
// Time Complexity: Same as Floyd-Warshall algorithm i.e. O(V^3).