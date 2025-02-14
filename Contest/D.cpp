#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        vector<int> b(m);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        vector<int> prefix_sum(m + 1, 0);
        for (int i = 0; i < m; ++i) {
            prefix_sum[i + 1] = prefix_sum[i] + b[i];
        }

        vector<int> result(m, 0);

        for (int k = 1; k <= m; ++k) {
            int contests = m / k;
            int remaining = m % k;

            int sum_ranks = 0;
            for (int i = 0; i < contests; ++i) {
                int start = i * k;
                int end = start + k;

                int kevin_solved = upper_bound(b.begin() + start, b.begin() + end, a[0]) - (b.begin() + start);
                int rank = 1;

                for (int j = 1; j < n; ++j) {
                    int participant_solved = upper_bound(b.begin() + start, b.begin() + end, a[j]) - (b.begin() + start);
                    if (participant_solved > kevin_solved) {
                        rank++;
                    }
                }

                sum_ranks += rank;
            }

            result[k - 1] = sum_ranks;
        }

        for (int i = 0; i < m; ++i) {
            cout << result[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}