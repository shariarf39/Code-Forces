#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int t;
    cin >> t;  // Number of test cases
    while (t--) {
        int n, m;
        cin >> n >> m;  // n is the number of vertices in the left part (2n vertices), m is the number in the right part
        
        if (m >= 2 * n) {
            // If m >= 2n, it's impossible to avoid monochromatic cycles
            cout << "NO" << endl;
        } else {
            // If m < 2n, we can color the graph in a valid way
            cout << "YES" << endl;
            // Create the 2n x m matrix
            for (int i = 0; i < 2 * n; ++i) {
                for (int j = 0; j < m; ++j) {
                    // Color the edge (i, j) in a round-robin fashion
                    cout << (j % n) + 1 << " ";
                }
                cout << endl;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}