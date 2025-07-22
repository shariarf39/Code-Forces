#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

// Define a large integer value to represent infinity
#define INF 1000000000

// A structure to represent a pair of integers, similar to std::pair
typedef struct {
    int first;
    int second;
} Pair;

// A structure to represent the queue for BFS
typedef struct {
    Pair* items;
    int front;
    int rear;
    int capacity;
} Queue;

// Function to create a queue of a given capacity
Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->capacity = capacity;
    q->front = -1;
    q->rear = -1;
    q->items = (Pair*)malloc(q->capacity * sizeof(Pair));
    return q;
}

// Function to check if the queue is empty
bool isEmpty(Queue* q) {
    return q->front == -1;
}

// Function to add an item to the queue
void enqueue(Queue* q, Pair value) {
    if (q->rear == q->capacity - 1) {
        // This is a simple implementation and doesn't handle overflow.
        // For this problem, the capacity is pre-calculated to be sufficient.
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

// Function to remove an item from the queue
Pair dequeue(Queue* q) {
    Pair item;
    if (isEmpty(q)) {
        item.first = -1;
        item.second = -1;
        return item;
    }
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

// Function to free the memory allocated for the queue
void freeQueue(Queue* q) {
    free(q->items);
    free(q);
}

// Function to compute the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    while (b) {
        a %= b;
        int temp = a;
        a = b;
        b = temp;
    }
    return a;
}

// The main logic to solve the problem for a single test case
void solve() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Store edges temporarily to build the graph after calculating degrees
    Pair* edges = (Pair*)malloc(m * sizeof(Pair));
    int* deg = (int*)calloc(n + 1, sizeof(int));

    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        edges[i] = (Pair){u, v};
        deg[u]++;
        deg[v]++;
    }

    // Adjacency list representation of the graph
    int** adj = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 1; i <= n; ++i) {
        if (deg[i] > 0) {
            adj[i] = (int*)malloc(deg[i] * sizeof(int));
        } else {
            adj[i] = NULL;
        }
    }

    // Populate the adjacency list
    int* current_deg = (int*)calloc(n + 1, sizeof(int));
    for (int i = 0; i < m; ++i) {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u][current_deg[u]++] = v;
        adj[v][current_deg[v]++] = u;
    }
    free(edges);
    free(current_deg);

    // Compute LCM of all degrees to determine the period of the state
    int lcm = 1;
    for (int u = 1; u <= n; ++u) {
        if (deg[u] == 0) continue;
        lcm = (long long)lcm * deg[u] / gcd(lcm, deg[u]);
        if (lcm > 10000) {
            lcm = 10000; // Limit LCM to prevent excessive memory usage
            break;
        }
    }

    // BFS setup: state is (vertex, time mod lcm)
    // dist stores {total_time, wait_time}
    Pair** dist = (Pair**)malloc((n + 1) * sizeof(Pair*));
    for (int i = 0; i <= n; ++i) {
        dist[i] = (Pair*)malloc(lcm * sizeof(Pair));
        for (int j = 0; j < lcm; ++j) {
            dist[i][j] = (Pair){INF, INF};
        }
    }

    Queue* q = createQueue((n + 1) * lcm);
    dist[1][0] = (Pair){0, 0};
    enqueue(q, (Pair){1, 0});

    while (!isEmpty(q)) {
        Pair current = dequeue(q);
        int u = current.first;
        int mod = current.second;

        int current_time = dist[u][mod].first;
        int wait_time = dist[u][mod].second;

        // Option 1: Wait one second
        int new_mod_wait = (mod + 1) % lcm;
        if (dist[u][new_mod_wait].first > current_time + 1) {
            dist[u][new_mod_wait] = (Pair){current_time + 1, wait_time + 1};
            enqueue(q, (Pair){u, new_mod_wait});
        } else if (dist[u][new_mod_wait].first == current_time + 1 && dist[u][new_mod_wait].second > wait_time + 1) {
            dist[u][new_mod_wait].second = wait_time + 1;
            enqueue(q, (Pair){u, new_mod_wait});
        }

        // Option 2: Move through the designated edge
        if (deg[u] == 0) continue;
        int edge_idx = (mod % deg[u]);
        int v = adj[u][edge_idx];
        int new_mod_move = (mod + 1) % lcm;
        if (dist[v][new_mod_move].first > current_time + 1) {
            dist[v][new_mod_move] = (Pair){current_time + 1, wait_time};
            enqueue(q, (Pair){v, new_mod_move});
        } else if (dist[v][new_mod_move].first == current_time + 1 && dist[v][new_mod_move].second > wait_time) {
            dist[v][new_mod_move].second = wait_time;
            enqueue(q, (Pair){v, new_mod_move});
        }
    }

    // Find the minimal total time and corresponding minimal wait time to reach vertex n
    int min_time = INF;
    int min_wait = INF;
    for (int mod = 0; mod < lcm; ++mod) {
        if (dist[n][mod].first < min_time) {
            min_time = dist[n][mod].first;
            min_wait = dist[n][mod].second;
        } else if (dist[n][mod].first == min_time && dist[n][mod].second < min_wait) {
            min_wait = dist[n][mod].second;
        }
    }

    printf("%d %d\n", min_time, min_wait);

    // Free all dynamically allocated memory
    for (int i = 1; i <= n; ++i) {
        free(adj[i]);
        free(dist[i]);
    }
    free(adj);
    free(dist);
    free(deg);
    freeQueue(q);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}
