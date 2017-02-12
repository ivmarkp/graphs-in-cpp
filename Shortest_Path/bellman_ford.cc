/**
 * Bellman-Ford algorithm for shortest paths from a src vertex to all other
 * vertices in the given graph contains negative weight edges.
 */
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pairInt;

void bellmanford(auto& adj, int v, int s) {
    vector<int> dist(v, INT_MAX);
    vector<int> parent(v);

    dist[s] = 0;
    parent[s] = -1;

    // Loop through all edges v-1 times, relaxing each in turn.
    for (int i = 1; i <= v - 1; i++)
        for (int j = 0; j < v; j++)
            for (auto it = adj[j].begin(); it != adj[j].end(); ++it) {
                int v = (*it).first;
                int w = (*it).second;

                if (w + dist[j] < dist[v]) {
                    dist[v] = dist[j] + w;
                    parent[v] = j;
                }
            }

    bool flag = true;
    // Check for negative cycles
    for (int j = 0; j < v; j++)
        for (auto it = adj[j].begin(); it != adj[j].end(); ++it)
            if (it->second + dist[j] < dist[it->first]) {
                flag = false;
                j = v;
                break;
            }

    // Print the shortest path edges with their respective weights.
    if (flag)
        for (int i = 0; i < v; i++)
            cout << parent[i] << " -- " << i
                 << " : " << dist[i] << endl;
    else
        cout << "Negative cycle found...\n";
}

int main() {
    int vertices, edges, source;
    cin >> vertices >> edges >> source;

    vector<vector<pairInt>> adj(vertices);

    int u, v, wt;
    for (int i = 0; i < edges; i++) {
        cin >> u >> v >> wt;
        adj[u].push_back(make_pair(v, wt));
        //adj[v].push_back(make_pair(u, wt)); // Dealing with dir. graphs.
    }

    bellmanford(adj, vertices, source);

    return 0;
}
// Time Complexity: O(V) + O(V.E) + O(E) ~ O(V.E).