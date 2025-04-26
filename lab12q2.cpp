// Graph_ADT_List.cpp
#include <iostream>
#include <list>
using namespace std;

class GraphList {
private:
    int numVertices;
    list<int> *adjList;

public:
    GraphList(int vertices) {
        numVertices = vertices;
        adjList = new list<int>[numVertices];
    }

    ~GraphList() {
        delete[] adjList;
    }

    void insertEdge(int src, int dest) {
        if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices) {
            adjList[src].push_back(dest);
            adjList[dest].push_back(src); // For undirected graph
            cout << "Edge inserted.\n";
        } else {
            cout << "Invalid vertices.\n";
        }
    }

    void deleteEdge(int src, int dest) {
        if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices) {
            adjList[src].remove(dest);
            adjList[dest].remove(src);
            cout << "Edge deleted.\n";
        } else {
            cout << "Invalid vertices.\n";
        }
    }

    void searchEdge(int src, int dest) {
        if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices) {
            for (int neighbor : adjList[src]) {
                if (neighbor == dest) {
                    cout << "Edge exists.\n";
                    return;
                }
            }
            cout << "Edge does not exist.\n";
        } else {
            cout << "Invalid vertices.\n";
        }
    }

    void display() {
        cout << "Adjacency List:\n";
        for (int i = 0; i < numVertices; ++i) {
            cout << i << " --> ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    GraphList g(vertices);

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

