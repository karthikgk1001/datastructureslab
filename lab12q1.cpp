// Graph_ADT_Matrix_Improved.cpp
#include <iostream>
#include <vector>
using namespace std;

class GraphMatrix {
private:
    vector<vector<int>> adjMatrix;
    int numVertices;

public:
    GraphMatrix(int vertices) {
        numVertices = vertices;
        adjMatrix.resize(numVertices, vector<int>(numVertices, 0));
    }

    void insertEdge(int src, int dest) {
        if (isValidVertex(src) && isValidVertex(dest)) {
            adjMatrix[src][dest] = 1;
            adjMatrix[dest][src] = 1; // For undirected graph
            cout << "Edge inserted.\n";
        } else {
            cout << "Invalid vertices.\n";
        }
    }

    void deleteEdge(int src, int dest) {
        if (isValidVertex(src) && isValidVertex(dest)) {
            adjMatrix[src][dest] = 0;
            adjMatrix[dest][src] = 0;
            cout << "Edge deleted.\n";
        } else {
            cout << "Invalid vertices.\n";
        }
    }

    void searchEdge(int src, int dest) {
        if (isValidVertex(src) && isValidVertex(dest)) {
            if (adjMatrix[src][dest])
                cout << "Edge exists.\n";
            else
                cout << "Edge does not exist.\n";
        } else {
            cout << "Invalid vertices.\n";
        }
    }

    void display() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

private:
    bool isValidVertex(int v) {
        return v >= 0 && v < numVertices;
    }
};

int main() {
    int vertices;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    GraphMatrix g(vertices);

    int choice, src, dest;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert Edge\n2. Delete Edge\n3. Search Edge\n4. Display Graph\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter source and destination vertices: ";
                cin >> src >> dest;
                g.insertEdge(src, dest);
                break;
            case 2:
                cout << "Enter source and destination vertices: ";
                cin >> src >> dest;
                g.deleteEdge(src, dest);
                break;
            case 3:
                cout << "Enter source and destination vertices: ";
                cin >> src >> dest;
                g.searchEdge(src, dest);
                break;
            case 4:
                g.display();
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
