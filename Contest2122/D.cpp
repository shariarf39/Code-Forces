#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define INF INT_MAX

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

typedef struct {
    int first;
    int second;
} Pair;

typedef struct {
    int u;
    int mod;
} State;

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Allocate adjacency list
    int** adj = (int**)malloc((n + 1) * sizeof(int*));
    int* deg = (int*)calloc(n + 1, sizeof(int));
    for (int i = 0; i <= n; ++i) {
        adj[i] = (int*)malloc(m * sizeof(int)); // Maximum possible edges per node
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][deg[u]++] = v;
        adj[v][deg[v]++] = u;
    }

    // Compute LCM of all degrees to determine the period
    int lcm_val = 1;
    for (int u = 1; u <= n; ++u) {
        if (deg[u] == 0) continue;
        lcm_val = lcm(lcm_val, deg[u]);
        if (lcm_val > 10000) {
            lcm_val = 10000; // Limit LCM to prevent excessive memory usage
            break;
        }
    }

    // Allocate distance and wait time arrays
    Pair** dist = (Pair**)malloc((n + 1) * sizeof(Pair*));
    for (int i = 0; i <= n; ++i) {
        dist[i] = (Pair*)malloc(lcm_val * sizeof(Pair));
        for (int j = 0; j < lcm_val; ++j) {
            dist[i][j].first = INF;
            dist[i][j].second = INF;
        }
    }

    // Initialize queue for BFS
    State* queue = (State*)malloc(n * lcm_val * sizeof(State));
    int front = 0, rear = 0;
    dist[1][0].first = 0;
    dist[1][0].second = 0;
    queue[rear++] = (State){1, 0};

    while (front < rear) {
        State current = queue[front++];
        int u = current.u;
        int mod = current.mod;
        int current_time = dist[u][mod].first;
        int wait_time = dist[u][mod].second;

        // Option 1: Wait one second
        int new_mod = (mod + 1) % lcm_val;
        if (dist[u][new_mod].first > current_time + 1) {
            dist[u][new_mod].first = current_time + 1;
            dist[u][new_mod].second = wait_time + 1;
            queue[rear++] = (State){u, new_mod};
        } else if (dist[u][new_mod].first == current_time + 1 && dist[u][new_mod].second > wait_time + 1) {
            dist[u][new_mod].second = wait_time + 1;
            queue[rear++] = (State){u, new_mod};
        }

        // Option 2: Move through the (mod % deg[u] + 1)-th edge
        if (deg[u] == 0) continue;
        int edge_idx = mod % deg[u];
        int v = adj[u][edge_idx];
        int new_mod_move = (mod + 1) % lcm_val;
        if (dist[v][new_mod_move].first > current_time + 1) {
            dist[v][new_mod_move].first = current_time + 1;
            dist[v][new_mod_move].second = wait_time;
            queue[rear++] = (State){v, new_mod_move};
        } else if (dist[v][new_mod_move].first == current_time + 1 && dist[v][new_mod_move].second > wait_time) {
            dist[v][new_mod_move].second = wait_time;
            queue[rear++] = (State){v, new_mod_move};
        }
    }

    // Find the minimal total time and corresponding minimal wait time to reach vertex n
    int min_time = INF;
    int min_wait = INF;
    for (int mod = 0; mod < lcm_val; ++mod) {
        if (dist[n][mod].first < min_time) {
            min_time = dist[n][mod].first;
            min_wait = dist[n][mod].second;
        } else if (dist[n][mod].first == min_time && dist[n][mod].second < min_wait) {
            min_wait = dist[n][mod].second;
        }
    }

    printf("%d %d\n", min_time, min_wait);

    // Free allocated memory
    for (int i = 0; i <= n; ++i) {
        free(adj[i]);
        free(dist[i]);
    }
    free(adj);
    free(deg);
    free(dist);
    free(queue);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}
