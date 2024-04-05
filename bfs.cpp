#include <iostream>
#include <cstdlib> // For exit()

using namespace std;

#define MAX 100
#define initial 1
#define waiting 2
#define visited 3

int n;
int adj[MAX][MAX];
int state[MAX];
int queue[MAX], front = -1, rear = -1;

// Function declarations
void create_graph();
void BF_Traversal();
void BFS(int v);
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();

int main() {
    create_graph();
    BF_Traversal();
    return 0;
}

void create_graph() {
    int i, max_edges, origin, destin;
    cout << "\n\n Enter number of nodes : ";
    cin >> n;

    if (n <= 0 || n > MAX) {
        cout << "Invalid number of nodes. Exiting.\n";
        exit(1);
    }

    max_edges = n * (n - 1);

    for (i = 0; i < max_edges; i++) {
        cout << "Enter edge " << i << " (-1 -1 to quit): ";
        cin >> origin >> destin;
        if (origin == -1 && destin == -1)
            break;
        if (origin >= n || destin >= n || origin < 0 || destin < 0) {
            cout << "Invalid edge!\n\n";
            i--;
        } else
            adj[origin][destin] = 1;
    }
}

void BF_Traversal() {
    int v;
    for (v = 0; v < n; v++)
        state[v] = initial;
    cout << "\n\n Enter starting vertex for Breadth First Search: ";
    cin >> v;
    BFS(v);
}

void BFS(int v) {
    int i;
    insert_queue(v);
    state[v] = waiting;
    while (!isEmpty_queue()) {
        v = delete_queue();
        cout << v;
        state[v] = visited;
        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && state[i] == initial) {
                insert_queue(i);
                state[i] = waiting;
            }
        }
    }
}

void insert_queue(int vertex) {
    if (rear == MAX - 1) {
        cout << "\n\nQueue Overflow";
        exit(1);
    }
    if (front == -1)
        front = 0;
    rear = rear + 1;
    queue[rear] = vertex;
}

int isEmpty_queue() {
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
}

int delete_queue() {
    int del;
    if (front == -1 || front > rear) {
        cout << "\n\nQueue Underflow";
        exit(1);
    }
    del = queue[front];
    front = front + 1;
    return del;
}

