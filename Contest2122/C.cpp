#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<pair<int, int>, int>> points(n); // {{x, y}, index}
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            points[i] = {{x, y}, i + 1}; // store original index
        }

        // Sort by x first, then by y
        sort(points.begin(), points.end());

        vector<pair<int, int>> result;

        // Pair outermost with each other
        for (int i = 0; i < n / 2; ++i) {
            int idx1 = points[i].second;
            int idx2 = points[n - 1 - i].second;
            result.push_back({idx1, idx2});
        }

        for (auto [a, b] : result) {
            cout << a << " " << b << '\n';
        }
    }

    return 0;
}
