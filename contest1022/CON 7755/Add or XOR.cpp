#include <iostream>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

struct State {
    int value;
    int cost;
    bool operator>(const State& other) const {
        return cost > other.cost;
    }
};

int minCostToMakeEqual(int a, int b, int x, int y) {
    if (a == b) return 0;

    priority_queue<State, vector<State>, greater<State>> pq;
    unordered_map<int, int> min_cost;

    pq.push({a, 0});
    min_cost[a] = 0;

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        if (current.value == b) {
            return current.cost;
        }

        if (current.cost > min_cost[current.value]) {
            continue;
        }

        // Operation 1: a + 1
        int next_value = current.value + 1;
        int new_cost = current.cost + x;
        if (next_value <= b + 200) { // Prevent infinite loop; 200 is arbitrary but large enough
            if (min_cost.find(next_value) == min_cost.end() || new_cost < min_cost[next_value]) {
                min_cost[next_value] = new_cost;
                pq.push({next_value, new_cost});
            }
        }

        // Operation 2: a XOR 1
        next_value = current.value ^ 1;
        new_cost = current.cost + y;
        if (next_value <= b + 200) {
            if (min_cost.find(next_value) == min_cost.end() || new_cost < min_cost[next_value]) {
                min_cost[next_value] = new_cost;
                pq.push({next_value, new_cost});
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        cout << minCostToMakeEqual(a, b, x, y) << '\n';
    }

    return 0;
}
