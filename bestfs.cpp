#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <functional>

using namespace std;
struct Node {
    char name;
    vector<Node*> neighbors;
    Node(char n) : name(n) {}
};

void addEdge(Node* u, Node* v) {
    u->neighbors.push_back(v);
    v->neighbors.push_back(u);
}

void bestFirstSearch(Node* start, Node* goal) {
    map<Node*, bool> visited;
    priority_queue<Node*, vector<Node*>, function<bool(Node*, Node*)>> 
        pq([&](Node* a, Node* b) {
            return a->neighbors.size() < b->neighbors.size();
        }
    );

    pq.push(start);
    visited[start] = true;

    while (!pq.empty()) {
        Node* current = pq.top();
        pq.pop();
        cout << "Visiting node: " << current->name << endl;
        if (current == goal) {
            cout << "Goal found!" << endl;
            return;
        }

        for (Node* neighbor : current->neighbors) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                pq.push(neighbor);
            }
        }
    }

    cout << "Goal not found!" << endl;
}

int main() {
    Node* A = new Node('A');
    Node* B = new Node('B');
    Node* C = new Node('C');
    Node* D = new Node('D');
    Node* E = new Node('E');
    Node* F = new Node('F');

    addEdge(A, B);
    addEdge(A, C);
    addEdge(B, D);
    addEdge(C, D);
    addEdge(C, E);
    addEdge(D, F);
    addEdge(E, F);

    bestFirstSearch(A, F);
    return 0;
}
