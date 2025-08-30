#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Graph {
public:
    // Adjacency list (node -> list of neighbours)
    unordered_map<int, list<int>> adj;

    // Add edge (directed or undirected)
    void addEdge(int u, int v, bool directed) {
        // Add edge u -> v
        adj[u].push_back(v);

        // If undirected, also add v -> u
        if (!directed) {
            adj[v].push_back(u);
        }
    }

    // Print adjacency list
    void printAdjList() {
        for (auto& node : adj) {
            cout << node.first << " -> ";
            for (auto& neighbour : node.second) {
                cout << neighbour << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g;
    int n, m;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

    cout << "Enter edges (u v): " << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, false); // false = undirected
    }

    cout << "\nAdjacency List:\n";
    g.printAdjList();

    return 0;
}
