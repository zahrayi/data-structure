#include <iostream>
#include <queue>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int v;
    struct Node** graph;

    Graph(int vert) {
        v = vert;
        graph = new Node * [v];
        for (int i = 0; i < v; i++) {
            graph[i] = nullptr;
        }
    }

    void addEdge(int s, int d) {
        struct Node* n = new Node();
        n->vertex = d;
        n->next = graph[s];
        graph[s] = n;
    }

    void removeEdge(int s, int d) {
        Node* current = graph[s];
        Node* previous = nullptr;

        while (current != nullptr) {
            if (current->vertex == d) {
                if (previous == nullptr) {
                    graph[s] = current->next;
                }
                else {
                    previous->next = current->next;
                }
                delete current;
                break;
            }

            previous = current;
            current = current->next;
        }
    }

    void addVertex(int vertex) {
        if (vertex >= 0 && vertex < v && graph[vertex] == nullptr) {
            graph[vertex] = new Node();
            graph[vertex]->vertex = vertex;
            graph[vertex]->next = nullptr;
        }
    }

    void removeVertex(int vertex) {
        for (int i = 0; i < v; i++) {
            if (i != vertex) {
                removeEdge(i, vertex);
            }
        }

        for (int i = vertex; i < v - 1; i++) {
            graph[i] = graph[i + 1];
        }
        v--;
    }
    data-structure 
