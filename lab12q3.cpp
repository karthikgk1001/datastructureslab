// Graph_ADT_Algorithms_WithIntMax.cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INT_MAX 2147483647  // manually defining INT_MAX

struct Edge {
    int src, dest, weight;
};

class Graph {
private:
    int V;
    vector<Edge> edges;
    vector<vector<pair<int, int>>> adjList;

public:
    Graph(int vertices) {
        V = vertices;
        adjList.resize(V);
    }

    void addEdge(int src, int dest, int weight) {
        edges.push_back({src, dest, weight});
        adjList[src].push_back({dest, weight});
        adjList[dest].push_back({src, weight}); // Undirected graph
        cout << "Edge added.\n";
    }

    void primMST() {
        vector<int> key(V, INT_MAX);
        vector<bool> inMST(V, false);
        vector<int> parent(V, -1);

        key[0] = 0;
        for (int count = 0; count < V - 1; ++count) {
            int u = -1;
            int minKey = INT_MAX;

            for (int v = 0; v < V; ++v) {
                if (!inMST[v] && key[v] < minKey) {
                    minKey = key[v];
                    u = v;
                }
            }

            if (u == -1) break;

            inMST[u] = true;

            for (auto &[v, weight] : adjList[u]) {
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                }
            }
        }

        cout << "Prim's MST:\n";
        for (int i = 1; i < V; ++i) {
            if (parent[i] != -1)
                cout << parent[i] << " - " << i << "\n";
        }
    }

    void bubbleSortEdges() {
        int n = edges.size();
        for (int i = 0; i < n-1; ++i) {
            for (int j = 0; j < n-i-1; ++j) {
                if (edges[j].weight > edges[j+1].weight) {
                    Edge temp = edges[j];
                    edges[j] = edges[j+1];
                    edges[j+1] = temp;
                }
            }
        }
    }

    int findParent(int vertex, vector<int> &parent) {
        if (vertex == parent[vertex])
            return vertex;
        return parent[vertex] = findParent(parent[vertex], parent);
    }

    void kruskalMST() {
        bubbleSortEdges(); // instead of std::sort

        vector<int> parent(V);
        for (int i = 0; i < V; ++i)
            parent[i] = i;

        cout << "Kruskal's MST:\n";
        for (auto edge : edges) {
            int srcParent = findParent(edge.src, parent);
            int destParent = findParent(edge.dest, parent);

            if (srcParent != destParent) {
                cout << edge.src << " - " << edge.dest << "\n";
                parent[srcParent] = destParent;
            }
        }
    }

    void dijkstra(int start) {
        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto &[v, weight] : adjList[u]) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Dijkstra's shortest paths:\n";
        for (int i = 0; i < V; ++i) {
            if (dist[i] == INT_MAX)
                cout << "Distance from " << start << " to " << i << ": Unreachable\n";
            else
                cout << "Distance from " << start << " to " << i << ": " << dist[i] << "\n";
        }
    }
};

int main() {
    int vertices;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    Graph g(vertices);

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Edge\n2. Prim's MST\n3. Kruskal's MST\n4. Dijkstra's Algorithm\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int src, dest, weight, start;
        switch (choice) {
            case 1:
                cout << "Enter source, destination, and weight: ";
                cin >> src >> dest >> weight;
                g.addEdge(src, dest, weight);
                break;
            case 2:
                g.primMST();
                break;
            case 3:
                g.kruskalMST();
                break;
            case 4:
                cout << "Enter starting vertex for Dijkstra's Algorithm: ";
                cin >> start;
                g.dijkstra(start);
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
