#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }

        vector<vector<int>> dp(n, vector<int>(m, INF));
        dp[0][0] = grid[0][0];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + grid[i][j]);
                if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + grid[i][j]);
            }
        }

        int min_cost = dp[n-1][m-1];
        for (int shift = 0; shift < m; ++shift) {
            vector<vector<int>> shifted_grid = grid;
            for (int i = 0; i < n; ++i) {
                rotate(shifted_grid[i].begin(), shifted_grid[i].begin() + shift, shifted_grid[i].end());
            }

            vector<vector<int>> dp_shifted(n, vector<int>(m, INF));
            dp_shifted[0][0] = shifted_grid[0][0];

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (i > 0) dp_shifted[i][j] = min(dp_shifted[i][j], dp_shifted[i-1][j] + shifted_grid[i][j]);
                    if (j > 0) dp_shifted[i][j] = min(dp_shifted[i][j], dp_shifted[i][j-1] + shifted_grid[i][j]);
                }
            }

            int cost = k * shift + dp_shifted[n-1][m-1];
            min_cost = min(min_cost, cost);
        }

        cout << min_cost << '\n';
    }

    return 0;
}